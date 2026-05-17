PORTNAME=	openzl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	archivers

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Novel data compression framework
WWW=		https://openzl.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	32-bit platforms not yet supported (https://github.com/facebook/openzl/issues/342)

BUILD_DEPENDS=	gmd5sum:sysutils/coreutils
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd

USES=		cmake:indirect gmake

USE_GITHUB=	yes
GH_ACCOUNT=	facebook
GH_TUPLE=	facebook:zstd:f8745da6ff1ad1e7bab384bd1f9d742439278e99:zstd/deps/zstd \
		lz4:lz4:ebb370ca83af193212df4dcbadcc5d87bc0de2f0:lz4/deps/lz4 \
		dmlc:xgboost:ccb511768e13d1670c10be07dea89d0edca138f3:xgboost/deps/xgboost \
		dmlc:dmlc-core:8986b0598df709117570984571476c3614f55724:dmlc_core/deps/xgboost/dmlc-core \
		rapidsai:gputreeshap:40eae8c4c45974705f8053e4d3d05b88e3cfaefd:gputreeshap//deps/xgboost/gputreeshap \
		google:googletest:56efe3983185e3f37e43415d1afa97e3860f187f:googletest/deps/googletest

USE_LDCONFIG=	yes

MAKE_ARGS=	ZL_JOBS=${MAKE_JOBS_NUMBER}

CFLAGS_i386=	-msse2
LDFLAGS+=	-pthread -lexecinfo

PORTDOCS=	CHANGELOG CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

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
