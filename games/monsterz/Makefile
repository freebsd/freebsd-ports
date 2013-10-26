# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	monsterz
PORTVERSION=	0.7.1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://sam.zoy.org/monsterz/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Monsterz - arcade puzzle game

LICENSE=	WTFPL
LICENSE_NAME=	Do What The [expletive] You Want To Public License, Version 2
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

RUN_DEPENDS=	${PYGAME}

USE_PYTHON=	yes
MAKE_ENV=	prefix=${PREFIX}

PORTDOCS=	AUTHORS README TODO

SCOREDIR=	/var/games
PLIST_SUB=	SCOREDIR=${SCOREDIR}

DESKTOP_ENTRIES="Monsterz" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.for d in graphics sound
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${DATADIR}
	@${PYTHON_CMD} -m compileall ${DATADIR}
	@${PYTHON_CMD} -O -m compileall ${DATADIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
