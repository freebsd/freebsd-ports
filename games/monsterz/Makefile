# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	monsterz
PORTVERSION=	0.7.1
PORTREVISION=	9
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
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYGAME}

USE_PYTHON=	yes
MAKE_ENV=	prefix=${PREFIX}

PORTDOCS=	AUTHORS README TODO

SCOREDIR=	/var/games
PLIST_SUB=	SCOREDIR=${SCOREDIR}

DESKTOP_ENTRIES="Monsterz" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.for d in graphics sound
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${DATADIR}
	(cd ${STAGEDIR}${PREFIX}	\
	&& ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d ${DATADIR}	\
		-f ${DATADIR:S;${PREFIX}/;;}	\
	&& ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -d ${DATADIR}\
		-f ${DATADIR:S;${PREFIX}/;;})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/monsterz
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
