# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyspacewar
PORTVERSION=	1.1.0
CATEGORIES=	games python
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Game loosely based on the original Spacewar!

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL.txt

RUN_DEPENDS=	${PYGAME}

USE_GITHUB=	yes
GH_ACCOUNT=	mgedmin
GH_TAGNAME=	f872564

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
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}/icons/${PORTNAME}${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}/icons/${PORTNAME}${i}.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}${i}.svg
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
