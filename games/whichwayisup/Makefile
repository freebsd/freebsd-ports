# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	whichwayisup
PORTVERSION=	0.7.9
PORTREVISION=	5
CATEGORIES=	games python
MASTER_SITES=	http://www.oletus.fi/static/whichwayisup/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}_b${DISTVERSION:S/.//g}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}_b${DISTVERSION:S/.//g}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Platformer game with rotational twist

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PYTHON=	yes
USE_ZIP=	yes
USE_GNOME=	desktopfileutils
INSTALLS_ICONS=	yes
USE_DOS2UNIX=	*.py *.txt

PORTDOCS=	README.txt changelog.txt

DESKTOP_ENTRIES="Which Way Is Up" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Game;ArcadeGame;" false

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/libdir =/s|=.*|= "${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}"|'\
		${WRKSRC}/run_game.py
	@${REINPLACE_CMD} -e '/data_dir =/s|data_py.*data.|"${DATADIR}"|'\
		${WRKSRC}/lib/data.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete -or -name "*.orig" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}
	@${TOUCH} ${WRKSRC}/data/music/.keep_me

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run_game.py ${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${DATADIR})
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
