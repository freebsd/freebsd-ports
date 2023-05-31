PORTNAME=	heimer
DISTVERSION=	4.2.0
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/juzzlin/Heimer/releases/download/${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple mind map, diagram, and note-taking tool
WWW=		https://github.com/juzzlin/Heimer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing compiler:c++17-lang qt:5
USE_QT=		core gui network svg widgets xml buildtools:build \
		linguisttools:build qmake:build testlib:build

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
