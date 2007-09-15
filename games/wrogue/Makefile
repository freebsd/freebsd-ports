# New ports collection makefile for:	warp-rogue
# Date created:		2007-02-26
# Whom:			Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $Carpetsmoker: ports/games/wrogue/Makefile,v 1.3 2007/09/09 13:32:49 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	wrogue
DISTVERSION=	0.7.7b
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	todoom

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	A gothic science fantasy roguelike game

USE_BZIP2=	yes
USE_SDL=	yes
USE_GMAKE=	yes
MAKEFILE=	unix.mak
ALL_TARGET=	release
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e "s|-march=i586||; \
		s|gcc|${CC}|; \
		s|CFLAGS=|CFLAGS+=|" \
	${WRKSRC}/src/unix.mak

	@${REINPLACE_CMD} -e "s|\./data/|${DATADIR}/|" \
		${WRKSRC}/src/platform/unix/pl_unix.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wrogue ${PREFIX}/bin
	${MKDIR} ${DATADIR} ${DATADIR}/engine ${DATADIR}/scenario
.for dir in engine/config engine/desc engine/graphics engine/help \
	engine/psybolts scenario/careers scenario/info scenario/npcs \
	scenario/objects scenario/race scenario/terrain scenario/user scenario/world
	${MKDIR} ${DATADIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/data/${dir}/* ${DATADIR}/${dir}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in changes.txt license.txt sc_guide.txt
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
