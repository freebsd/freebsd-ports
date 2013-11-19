# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	sampsvr
PORTVERSION=	0.3c
CATEGORIES=	games linux
MASTER_SITES=	http://files.sa-mp.com/
DISTNAME=	samp${PORTVERSION:S,.,,}svr

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rockstar's GTA: San Andreas multiplayer modification dedicated server

USES=		dos2unix
USE_LINUX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/samp03
DOS2UNIX_GLOB=	*.txt *.pwn *.inc
USE_RC_SUBR=	sampd
SAMPDIR=	${PREFIX}/libexec/${PORTNAME}
PORTDOCS=	LICENSE README
PLIST_SUB=	SAMPDIR="${SAMPDIR:S,^${PREFIX}/,,}"
SUB_FILES=	pkg-message
SUB_LIST=	SAMPDIR="${SAMPDIR}" SAMPBIN=samp03svr
.if !defined(NOPORTDOCS)
SUB_LIST+=	NOTEWORK="Read ${DOCSDIR}/README to configure SA-MP Server"
.else
SUB_LIST+=	NOTEWORK=""
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${SAMPDIR}
.for i in announce samp-npc samp03svr
	${BRANDELF} -t Linux ${WRKSRC}/${i}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${SAMPDIR}
.endfor
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
	${FIND} . -type d ! -empty -exec \
		${MKDIR} "${DATADIR}/{}" \;
.for i in filterscripts gamemodes include npcmodes scriptfiles
	cd ${WRKSRC} && \
	${FIND} ${i} -type f -exec \
		${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
	${LN} -sf ${DATADIR}/${i}/ ${SAMPDIR}/${i}
.endfor	
.if !exists(${PREFIX}/etc/${PORTNAME}.cfg)
	${INSTALL_DATA} ${WRKSRC}/server.cfg ${PREFIX}/etc/${PORTNAME}.cfg
.endif
	${INSTALL_DATA} ${WRKSRC}/server.cfg ${PREFIX}/etc/${PORTNAME}.cfg.dist
	${LN} -sf ${PREFIX}/etc/${PORTNAME}.cfg ${SAMPDIR}/server.cfg
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
