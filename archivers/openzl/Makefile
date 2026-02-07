PORTNAME=	openzl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/google/googletest/releases/download/v${GOOGLETEST_VER}/:googletest
DISTFILES=	${DISTFILE_GOOGLETEST}:googletest
EXTRACT_ONLY=	${DISTFILE_DEFAULT} \
		${DISTFILE_zstd}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Novel data compression framework
WWW=		https://openzl.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to build: error: static assertion failed due to requirement 'sizeof(HeapMeta) == 16': sizeof(HeapMeta) must be 16 to guarantee alignment

BUILD_DEPENDS=	gmd5sum:sysutils/coreutils
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cmake:indirect gmake

USE_GITHUB=	yes
GH_ACCOUNT=	facebook
GH_TUPLE=	facebook:zstd:v${ZSTD_VER}:zstd/deps/zstd

USE_LDCONFIG=	yes

MAKE_ARGS=	ZL_JOBS=${MAKE_JOBS_NUMBER}

CFLAGS_i386=	-msse2
LDFLAGS+=	-pthread

PORTDOCS=	CHANGELOG CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

GOOGLETEST_VER=		1.17.0
ZSTD_VER=		1.5.7
DISTFILE_GOOGLETEST=	googletest-${GOOGLETEST_VER}${EXTRACT_SUFX}

post-extract:
	@${CP} ${DISTDIR}/${DISTFILE_GOOGLETEST} \
		${WRKSRC}/deps/googletest${EXTRACT_SUFX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zli ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include
	cd ${WRKSRC}/cpp/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libopenzl.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libopenzl.so ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ./gtests

.include <bsd.port.mk>
