# New ports collection makefile for:    Mesa
# Version required:     1.1.3beta
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $Id: Makefile,v 1.8 1995/04/09 07:09:32 asami Exp $
#

DISTNAME=       Mesa-1.1.3beta
PKGNAME=	Mesa-1.1.3b
CATEGORIES+=	graphics
MASTER_SITES=   ftp://iris.ssec.wisc.edu/pub/misc/

BROKEN=		yes # won't install until I convert the Makefiles to Imakefiles
WRKSRC=		${WRKDIR}/Mesa
USE_GMAKE=	yes
USE_X11=	yes
ALL_TARGET=	freebsd

# won't need this after I convert the Makefiles to Imakefiles
pre-build:
	if [ ! -e /usr/include/X11 ]; then \
	  ln -s /usr/X11R6/include/X11 /usr/include; \
	fi

.include <bsd.port.mk>
