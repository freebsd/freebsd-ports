# New ports collection makefile for:	sampsvr
# Date created:				6 November 2006
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	sampsvr
PORTVERSION=	0.2.3
CATEGORIES=	games linux
MASTER_SITES=	http://files.sa-mp.com/
DISTNAME=	samp02Xsvr

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Rockstar's GTA: San Andreas multiplayer modification dedicated server

USE_LINUX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S,svr,,}
USE_DOS2UNIX=	*.txt *.pwn
USE_RC_SUBR=	sampd
SAMPDIR=	${PREFIX}/libexec/${PORTNAME}
PORTDOCS=	README
PLIST_SUB=	SAMPDIR="${SAMPDIR:S,^${PREFIX}/,,}" SAMPBIN=${DISTNAME}
SUB_FILES=	pkg-message
SUB_LIST=	SAMPDIR="${SAMPDIR}" SAMPBIN=${DISTNAME}
.if !defined(NOPORTDOCS)
SUB_LIST+=	NOTEWORK="Read ${DOCSDIR}/README to configure SA-MP Server"
.else
SUB_LIST+=	NOTEWORK=""
.endif

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${SAMPDIR}
.for i in ${DISTNAME} announce
	${BRANDELF} -t Linux ${WRKSRC}/${i}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${SAMPDIR}
.endfor
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
	${FIND} . -type d ! -empty -exec \
		${MKDIR} "${DATADIR}/{}" \;
.for i in filterscripts gamemodes scriptfiles
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
