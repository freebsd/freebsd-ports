# $FreeBSD$

PORTNAME=	ponyc
DISTVERSION=	0.25.0
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Pony language compiler

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Undefined reference to __atomic_compare_exchange_8

LIB_DEPENDS=	libunwind.so:devel/libunwind
BUILD_DEPENDS=	llvm-link${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
RUN_DEPENDS=	llvm-link${LLVM_VERSION}:devel/llvm${LLVM_VERSION}

USES=		gmake ncurses compiler:c++11-lang

LLVM_VERSION=	50
# LLVM 6 has assertion failures when e.g. optimizing the mandelbrot example

PLIST_SUB=	VERSION="${DISTVERSION}" PONYARCH="${PONYARCH}"
OPTIONS_SUB=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ponylang

PORTDOCS=	*.md

MAKE_ENV=	config=release verbose=true default_pic=true \
		prefix=${PREFIX} arch=${PONYARCH} \
		LLVM_CONFIG=llvm-config${LLVM_VERSION}

OPTIONS_DEFINE=			DOCS EXAMPLES DTRACE
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

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200085
MAKE_ENV+=	default_ssl=openssl_1.1.0
.endif

.if ${CHOSEN_COMPILER_TYPE} == clang
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
