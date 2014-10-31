# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	robocalypto
PORTVERSION=	0.08
DISTVERSIONSUFFIX=	-alpha4c
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	GOOGLE_CODE \
		SF/nemysisfreebsdp/games/:icons
PROJECTHOST=	pyggel
DISTFILES=	PYGGEL-V${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	PYGGEL-V${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PYGGEL demo game

LICENSE=	Public_Domain_LICENSE
LICENSE_NAME=	Public Domain License
LICENSE_TEXT=	Public Domain
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyggel>=0:${PORTSDIR}/graphics/py-pyggel

WRKSRC=		${WRKDIR}/PYGGEL-V${DISTVERSION}${DISTVERSIONSUFFIX}/Robocalypto

USES=		python:run zip
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Robocalypto" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;StrategyGame;" ""

post-patch:
.for f in run_game.py gamelib/main.py gamelib/game.py
	@${REINPLACE_CMD} -e 's|^.*#!.*python.*$$|#!${PYTHON_CMD}|' \
		${WRKSRC}/${f}
.endfor
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data gamelib" ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
