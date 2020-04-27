# $FreeBSD$

PORTNAME=	ponyc
DISTVERSION=	0.33.2
CATEGORIES=	lang

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Pony language compiler

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Undefined reference to __atomic_compare_exchange_8

BUILD_DEPENDS=	llvm-link${LLVM_VERSION}:devel/llvm${LLVM_VERSION}

FLAVORS=	llvm_dynamic llvm_static
FLAVOR?=	${FLAVORS:[1]}

llvm_dynamic_RUN_DEPENDS=	llvm-link${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
llvm_dynamic_CONFLICTS_INSTALL=	ponyc-static
llvm_static_PKGNAMESUFFIX=	-static
llvm_static_CONFLICTS_INSTALL=	ponyc
.if ${FLAVOR} == llvm_static
COMMENT+=			(statically linked with LLVM)
.endif

USES=		gmake ncurses compiler:c++11-lang

LLVM_VERSION?=	70

PLIST_SUB=	VERSION="${DISTVERSION}" PONYARCH="${PONYARCH}"
OPTIONS_SUB=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ponylang

PORTDOCS=	*.md

MAKE_ENV=	config=release verbose=true default_pic=true \
		prefix=${PREFIX} arch=${PONYARCH} \
		LLVM_CONFIG=llvm-config${LLVM_VERSION}
.if ${FLAVOR} == llvm_dynamic
MAKE_ENV+=	link=llvm-dynamic
.else
MAKE_ENV+=	link=llvm-static
.endif

OPTIONS_DEFINE=			DOCS DTRACE EXAMPLES
OPTIONS_EXCLUDE_aarch64=	DTRACE
# Not enabling DTrace by default yet because it breaks --runtimebc ("super LTO"):
# https://github.com/ponylang/ponyc/issues/2915

DTRACE_MAKE_ENV=		use=dtrace

.include <bsd.port.pre.mk>

# Pony defaults to 'native', which
# a) doesn't work on aarch64
# b) is not appropriate for official OS packages
.if "${ARCH}" == aarch64
PONYARCH?=	armv8-a
.elif "${ARCH}" == amd64
# Can't use 'x86-64' because atomics are required
PONYARCH?=	core2
.endif

# keep in sync with all platforms where libunwind is available
.if (${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == aarch64)
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

.if ${CHOSEN_COMPILER_TYPE} == clang
# Building the bitcode with clangX and linking with llvmY often fails,
# so let's use the clang from the LLVM version that will be used by ponyc
CC=		${LOCALBASE}/bin/clang${LLVM_VERSION}
CXX=		${LOCALBASE}/bin/clang++${LLVM_VERSION}
MAKE_ENV+=	runtime-bitcode=yes
PLIST_SUB+=	BITCODE=""
.else
PLIST_SUB+=	BITCODE="@comment "
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pony/${DISTVERSION}/bin/ponyc

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.post.mk>
