# New ports collection makefile for:	warp-rogue
# Date created:		2007-02-26
# Whom:			Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $Carpetsmoker: ports/games/wrogue/Makefile,v 1.4 2008/01/27 04:50:01 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	wrogue
PORTVERSION=	0.8.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	todoom

MAINTAINER=	steinex@nognu.de
COMMENT=	A gothic science fantasy roguelike game

USE_BZIP2=	yes
USE_SDL=	yes
USE_GMAKE=	yes
MAKEFILE=	unix.mak
ALL_TARGET=	release
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKDIR}
PORTDOCS=	changes.txt license.txt readme.txt scenario_guide.txt

post-patch:
	@${REINPLACE_CMD} -e "s|-march=i586||; \
		s|gcc|${CC}|; \
		s|CFLAGS=|CFLAGS+=|" \
	${WRKSRC}/src/unix.mak

	@${REINPLACE_CMD} -e "s|\./data/|${DATADIR}/|" \
		${WRKSRC}/src/platform/unix/platform_unix.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wrogue ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && ${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC}/data && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
