# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	monsterz
PORTVERSION=	0.7.1
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://sam.zoy.org/monsterz/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Monsterz - arcade puzzle game

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYGAME}

USES=		python
MAKE_ENV=	prefix=${PREFIX}

PORTDOCS=	AUTHORS README TODO

SCOREDIR=	/var/games
PLIST_SUB=	SCOREDIR=${SCOREDIR}

DESKTOP_ENTRIES="Monsterz" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

pre-configure:
	${REINPLACE_CMD} '/test -f/ s|scorefile)|&.sample|g' \
		${WRKSRC}/Makefile

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

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
