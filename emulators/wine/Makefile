# New ports collection makefile for:    wine
# Version required:     95020
# Date created:         Sun Feb  5 16:12:09  1995
#

DISTNAME=       Wine-950202
MASTER_SITES=   ftp://sunsite.unc.edu/pub/Linux/ALPHA/wine/ \
		ftp://aris.com/pub/linux/ALPHA/Wine/development/ \
		ftp://tsx-11.mit.edu/pub/linux/ALPHA/Wine/development/ \
		ftp://ftp.funet.fi/pub/OS/Linux/ALPHA/Wine/ \
		ftp://ftp.wonderland.org/Wine/
WRKSRC=		${WRKDIR}/wine950202
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT= Configure
IS_INTERACTIVE=	yes
# set this until wine installs cleanly
NO_INSTALL=	yes

.include <bsd.port.mk>
