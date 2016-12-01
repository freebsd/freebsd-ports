# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	sampsvr
PORTVERSION=	0.3c
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://files.sa-mp.com/
DISTNAME=	samp${PORTVERSION:S,.,,}svr

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rockstar's GTA: San Andreas multiplayer modification dedicated server

USES=		dos2unix linux
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/samp03
DOS2UNIX_GLOB=	*.txt *.pwn *.inc
USE_RC_SUBR=	sampd
SAMPDIR=	${PREFIX}/libexec/${PORTNAME}
PORTDOCS=	LICENSE README
PLIST_SUB=	SAMPDIR="${SAMPDIR:S,^${PREFIX}/,,}"
SUB_FILES=	pkg-message
SUB_LIST=	SAMPDIR="${SAMPDIR}" SAMPBIN=samp03svr

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${SAMPDIR}
.for i in announce samp-npc samp03svr
	${BRANDELF} -t Linux ${WRKSRC}/${i}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${SAMPDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && \
	${FIND} . -type d ! -empty -exec \
		${MKDIR} "${STAGEDIR}${DATADIR}/{}" \;
.for i in filterscripts gamemodes include npcmodes scriptfiles
	cd ${WRKSRC} && \
	${FIND} ${i} -type f -exec \
		${INSTALL_DATA} {} "${STAGEDIR}${DATADIR}/{}" \;
	${LN} -sf ${DATADIR}/${i} ${STAGEDIR}${SAMPDIR}/${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/server.cfg \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample
	${LN} -sf ${PREFIX}/etc/${PORTNAME}.cfg ${STAGEDIR}${SAMPDIR}/server.cfg
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
