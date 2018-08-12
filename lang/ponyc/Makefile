# $FreeBSD$

PORTNAME=	ponyc
DISTVERSION=	0.24.4
CATEGORIES=	lang

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Pony language compiler

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Undefined reference to __atomic_compare_exchange_8
BROKEN_FreeBSD_10=	Undefined reference to __atomic_compare_exchange

LIB_DEPENDS=	libunwind.so:devel/libunwind
BUILD_DEPENDS=	llvm-link${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
RUN_DEPENDS=	llvm-link${LLVM_VERSION}:devel/llvm${LLVM_VERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		gmake ncurses compiler:c++11-lang
MAKE_ARGS=	config=release

LLVM_VERSION=	50

PLIST_SUB=	VERSION="${DISTVERSION}" PONYARCH="${PONYARCH}"

USE_GITHUB=	yes
GH_ACCOUNT=	ponylang

PORTDOCS=	*.md

MAKE_ENV=	prefix=${PREFIX} verbose=true arch=${PONYARCH}

# Pony defaults to 'native', which
# a) doesn't work on aarch64
# b) is not appropriate for official OS packages
.if "${ARCH}" == aarch64
PONYARCH?=	armv8-a
.elif "${ARCH}" == amd64
# Can't use 'x86-64' because atomics are required
PONYARCH?=	core2
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pony/${DISTVERSION}/bin/ponyc

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
