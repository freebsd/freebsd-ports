PORTNAME=	log4cplus
DISTVERSION=	2.1.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/REL_${DISTVERSION:S:.:_:g}/

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Logging library for C++
WWW=		https://log4cplus.github.io/log4cplus/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	catch>=0:devel/catch

USES=		cmake:testing compiler:c++11-lang pathfix tar:xz
USE_LDCONFIG=	yes

EXTRACT_AFTER_ARGS=	--exclude catch

.if ${.TARGETS} == "test"
CXXFLAGS+=	-I${LOCALBASE}/include/catch2
.endif

PORTDOCS=	*

CMAKE_TESTING_ON=	LOG4CPLUS_BUILD_TESTING WITH_UNIT_TESTS
CMAKE_OFF=	LOG4CPLUS_BUILD_TESTING WITH_UNIT_TESTS

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

post-build-DOCS-on:
	cd ${WRKDIR} && doxygen ${DISTNAME}/docs/doxygen.config

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${STAGEDIR}${DOCSDIR}

pre-test:
	${RM} ${BUILD_WRKSRC}/CMakeCache.txt

.include <bsd.port.mk>
