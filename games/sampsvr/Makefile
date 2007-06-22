# New ports collection makefile for:	sampsvr
# Date created:				6 November 2006
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	sampsvr
PORTVERSION=	0.2
CATEGORIES=	games linux
MASTER_SITES=	http://www.sa-mp.com/files/ \
		http://eu.littlewhitey.com/ \
		http://dedi.azer.nl/upload/ \
		http://www.kfcgang.com/files/
DISTNAME=	samp02svr

MAINTAINER=	ports@logvinov.com
COMMENT=	Rockstar's GTA: San Andreas multiplayer modification dedicated server

USE_LINUX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/samp02
USE_DOS2UNIX=	server.cfg *.pwn
USE_RC_SUBR=	sampd
SAMPDIR=	${PREFIX}/lib/${PORTNAME}
PORTDOCS=	README
PLIST_SUB=	SAMPDIR="${SAMPDIR:S,^${PREFIX}/,,}"
SUB_FILES=	pkg-message
SUB_LIST=	SAMPDIR="${SAMPDIR}"
.if !defined(NOPORTDOCS)
SUB_LIST+=	NOTEWORK="Read ${DOCSDIR}/README to configure SA-MP Server"
.else
SUB_LIST+=	NOTEWORK=""
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${MV} ${WRKSRC}/${DISTNAME} ${WRKSRC}/${USE_RC_SUBR}

do-install:
	${MKDIR} ${SAMPDIR}
.for i in ${USE_RC_SUBR} announce
	${BRANDELF} -t Linux ${WRKSRC}/${i}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${SAMPDIR}
.endfor
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
	${FIND} . -type d ! -empty -exec \
		${MKDIR} "${DATADIR}/{}" \; && \
	${FIND} filterscripts -type f -exec \
		${INSTALL_DATA} "{}" "${DATADIR}/{}" \; && \
	${FIND} gamemodes -type f -exec \
		${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
	${LN} -sf ${DATADIR}/filterscripts/ ${SAMPDIR}/filterscripts
	${LN} -sf ${DATADIR}/gamemodes/ ${SAMPDIR}/gamemodes
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
