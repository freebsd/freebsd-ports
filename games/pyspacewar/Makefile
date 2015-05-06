# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyspacewar
PORTVERSION=	0.9.8
CATEGORIES=	games python
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Game loosely based on the original Spacewar!

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL.txt

RUN_DEPENDS=	${PYGAME}

USE_GITHUB=	yes
GH_ACCOUNT=	mgedmin
GH_TAGNAME=	2d058b1

USES=		python
USE_PYTHON=	distutils autoplist

PORTDOCS=	*.rst
OPTIONS_DEFINE=	DOCS

INSTALLS_ICONS=	yes

DESKTOP_ENTRIES="PySpaceWar" "" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-install:
.for i in 16 22 32 48
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	${INSTALL_DATA} ${WRKSRC}/src/pyspacewar/icons/${PORTNAME}${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/src/pyspacewar/icons/${PORTNAME}${i}.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}${i}.svg
.endfor
# Symlink icon which is needed that PySpaceWar works
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/icons
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/icons/${PORTNAME}48.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
