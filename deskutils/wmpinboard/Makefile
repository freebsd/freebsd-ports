# New ports collection makefile for:	wmpinboard
# Version required:		0.8.5
# Date created:			17 January 1999
# Whom:				Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.3 1999/04/23 16:07:26 mharo Exp $
#

DISTNAME=	wmpinboard-0.8.5
CATEGORIES=	deskutils afterstep windowmaker
MASTER_SITES=	http://www.tu-ilmenau.de/~gomar/stuff/wmpinboard/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wmpinboard.app

USE_BZIP2=	yes
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpinboard ${X11BASE}/bin

post-install:
	@${ECHO} "              "
	@${ECHO} "------------------------------------------------------------"
	@${ECHO} "===>  Installing README in ${PREFIX}/share/doc/wmpinboard"
	@${ECHO} "------------------------------------------------------------"
	@${ECHO} "              "
	@${MKDIR} ${PREFIX}/share/doc/wmpinboard && chmod a+rx ${PREFIX}/share/doc/wmpinboard
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmpinboard

.include <bsd.port.mk>
