# New ports collection makefile for:	gtimer
# Version required:    1.1.4
# Date created:        25 February 1999
# Whom:                Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.3 1999/05/05 14:22:22 flathill Exp $
#

DISTNAME=	gtimer-1.1.4
CATEGORIES=	deskutils
MASTER_SITES=	http://www.radix.net/~cknudsen/gtimer/

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

GNU_CONFIGURE=	YES
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"
USE_GMAKE=	YES
USE_BZIP2=	YES
MAN1=		gtimer.1

post-install:
	@${INSTALL_MAN} ${WRKSRC}/gtimer.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
