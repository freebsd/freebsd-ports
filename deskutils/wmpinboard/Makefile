# New ports collection makefile for:	wmpinboard
# Version required:	0.7
# Date created:		17 January 1999
# Whom:			Jim Mock <jim@phrantic.phear.net>
#
# $Id$
#

DISTNAME=	wmpinboard-0.7
CATEGORIES=	deskutils afterstep windowmaker
MASTER_SITES=	http://www.tu-ilmenau.de/~gomar/stuff/wmpinboard/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wmpinboard.app

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpinboard ${X11BASE}/bin

.include <bsd.port.mk>
