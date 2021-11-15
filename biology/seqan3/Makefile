PORTNAME=	seqan3
DISTVERSION=	3.1.0
CATEGORIES=	biology devel math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library for biological sequence analysis

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

HPP_DEPENDS=	cereal>0:devel/cereal \
		range-v3>0:devel/range-v3
BUILD_DEPENDS=	${HPP_DEPENDS}
RUN_DEPENDS=	${HPP_DEPENDS} \
		coin-or-lemon>0:math/lemon

USES=		cmake localbase

USE_GITHUB=	yes
GH_ACCOUNT=	seqan
GH_TUPLE=	xxsds:sdsl-lite:cf9ff4a:sdsl_lite/submodules/sdsl-lite

USE_GCC=	yes # tests only pass with gcc, see https://github.com/seqan/seqan3/issues/2643, otherwise gcc isn't needed because this is a header-only library

TEST_WRKSRC=	${WRKSRC}/.test

NO_ARCH=	yes

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

do-test:
	@${MKDIR} ${TEST_WRKSRC} && cd ${TEST_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${WRKSRC}/test/unit && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		ctest

.include <bsd.port.mk>
