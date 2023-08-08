PORTNAME=	log4cplus
PORTVERSION=	2.1.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/REL_${PORTVERSION:S:.:_:g}/

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Logging library for C++
WWW=		https://log4cplus.github.io/log4cplus/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang tar:xz

OPTIONS_DEFINE=	DOCS

USE_LDCONFIG=	yes
CMAKE_OFF=	LOG4CPLUS_BUILD_TESTING

PORTDOCS=	*

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

post-build-DOCS-on:
	cd ${WRKDIR} && doxygen ${DISTNAME}/docs/doxygen.config

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
