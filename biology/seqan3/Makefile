PORTNAME=	seqan3
DISTVERSION=	3.4.0
CATEGORIES=	biology devel math
MASTER_SITES=	https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.42.0/:cpm
DISTFILES=	CPM.cmake:cpm
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		xxsds-sdsl-lite-d54d389_GH0${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library for biological sequence analysis
WWW=		https://www.seqan.de/ \
		https://github.com/seqan/seqan3

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

HPP_DEPENDS=	cereal>0:devel/cereal \
		range-v3>0:devel/range-v3
BUILD_DEPENDS=	${HPP_DEPENDS}
RUN_DEPENDS=	${HPP_DEPENDS} \
		coin-or-lemon>0:math/lemon

USES=		cmake compiler:c++23-lang localbase

USE_GITHUB=	yes
GH_ACCOUNT=	seqan
GH_TUPLE=	xxsds:sdsl-lite:d54d389:sdsl_lite/submodules/sdsl-lite

CMAKE_ARGS=	-DCPM_LOCATION=${DISTDIR}/${DIST_SUBDIR}

TEST_WRKSRC=	${WRKSRC}/.test

NO_ARCH=	yes

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

do-test:
	@${MKDIR} ${TEST_WRKSRC} && cd ${TEST_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DFETCHCONTENT_FULLY_DISCONNECTED=OFF ${WRKSRC}/test/unit && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		ctest

.include <bsd.port.mk>
