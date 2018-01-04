# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	whichwayisup
PORTVERSION=	0.7.9
PORTREVISION=	7
CATEGORIES=	games python
MASTER_SITES=	http://www.oletus.fi/static/whichwayisup/ \
		SF/nemysisfreebsdp/games/${PORTNAME}/:icons
DISTFILES=	${PORTNAME}_b${DISTVERSION:S/.//g}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}_b${DISTVERSION:S/.//g}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Platformer game with rotational twist

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		dos2unix python zip
USE_PYTHON=	py3kplist
DOS2UNIX_REGEX=	.*.[^pt][^nt][^gf]
INSTALLS_ICONS=	yes

PORTDOCS=	README.txt changelog.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Which Way Is Up" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} \
		-e 's|libdir =.*|libdir = "${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}"| ; \
		s|/usr/bin/env python|${PYTHON_CMD}|' \
		${WRKSRC}/run_game.py
	@${REINPLACE_CMD} -e 's|(data_py.*|("${DATADIR}"))|' \
		${WRKSRC}/lib/data.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete -or -name "*.orig" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}
	@${TOUCH} ${WRKSRC}/data/music/.keep_me

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run_game.py \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
