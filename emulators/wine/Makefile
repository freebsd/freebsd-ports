# New ports collection makefile for:    wine
# Version required:     951003
# Date created:         Sun Feb  5 16:12:09  1995
# Whom:			hsu
#
# $Id: Makefile,v 1.9 1995/07/13 01:13:20 asami Exp $
#

DATE=		951003
DISTNAME=       Wine-${DATE}
PKGNAME=	Wine-95.10.03
CATEGORIES+=	emulation x11
MASTER_SITES=   ftp://sunsite.unc.edu/pub/Linux/ALPHA/wine/ \
		ftp://aris.com/pub/linux/ALPHA/Wine/development/ \
		ftp://tsx-11.mit.edu/pub/linux/ALPHA/Wine/development/ \
		ftp://ftp.funet.fi/pub/OS/Linux/ALPHA/Wine/ \
		ftp://ftp.wonderland.org/Wine/

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/wine${DATE}
GNU_CONFIGURE=	yes
# wine doesn't come w/ an install rule
NO_INSTALL=	yes

.include <bsd.port.mk>
