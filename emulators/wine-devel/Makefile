# New ports collection makefile for:    wine
# Version required:     950302
# Date created:         Sun Feb  5 16:12:09  1995
# Whom:			hsu
#
# $Id: Makefile,v 1.6 1995/05/18 18:46:04 hsu Exp $
#

DATE=		950606
DISTNAME=       Wine-${DATE}
PKGNAME=	Wine-95.06.06
CATEGORIES+=	utilities x11 emulation
MASTER_SITES=   ftp://sunsite.unc.edu/pub/Linux/ALPHA/wine/ \
		ftp://aris.com/pub/linux/ALPHA/Wine/development/ \
		ftp://tsx-11.mit.edu/pub/linux/ALPHA/Wine/development/ \
		ftp://ftp.funet.fi/pub/OS/Linux/ALPHA/Wine/ \
		ftp://ftp.wonderland.org/Wine/

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wine${DATE}
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT= Configure
IS_INTERACTIVE=	yes
# set this until wine installs cleanly
NO_INSTALL=	yes

.include <bsd.port.mk>
