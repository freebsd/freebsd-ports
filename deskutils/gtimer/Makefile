# New ports collection makefile for:	gtimer
# Version required:    1.1.3
# Date created:        25 February 1999
# Whom:                Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.2 1999/04/21 19:07:31 mharo Exp $
#

DISTNAME=	gtimer-1.1.3
CATEGORIES=	deskutils
MASTER_SITES=	http://www.radix.net/~cknudsen/gtimer/

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

WRKSRC=		${WRKDIR}/gtimer-1.1.4
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"
USE_GMAKE=	YES
USE_BZIP2=	YES
MAN1=		gtimer.1

post-install:
	@${INSTALL_MAN} ${WRKSRC}/gtimer.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
