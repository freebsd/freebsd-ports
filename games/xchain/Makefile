# New ports collection makefile for:	xchain
# Version required:			1.0.2
# Date created:				13 March 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/04/27 04:36:16 mph Exp $
#

DISTNAME=	xchain_1.0-2
PKGNAME=	xchain-1.0.2
CATEGORIES=	games
MASTER_SITES=	http://thor.cam.ac.uk/~ac212/xchain/

MAINTAINER=	andy@icc.surw.chel.su

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80

USE_X11=	yes
WRKSRC=		${WRKDIR}/xchain-1.0

MAN6=		xchain.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xchain ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/xchain.6 ${PREFIX}/man/man6
	@ ${MKDIR} ${PREFIX}/share/doc/xchain
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchain
	@ ${INSTALL_DATA} ${WRKSRC}/copyright ${PREFIX}/share/doc/xchain

.include <bsd.port.mk>
