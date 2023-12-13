PORTNAME=	heimer
DISTVERSION=	4.3.0
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/juzzlin/Heimer/releases/download/${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple mind map, diagram, and note-taking tool
WWW=		https://github.com/juzzlin/Heimer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing compiler:c++17-lang gl qt:6
USE_GL=		opengl
USE_QT=		base svg translations

CMAKE_ON=	BUILD_WITH_QT6

PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS EXAMPLES TEST
OPTIONS_SUB=		yes
TEST_CMAKE_BOOL=	BUILD_TESTS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/heimer

.include <bsd.port.mk>
