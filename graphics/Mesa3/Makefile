# New ports collection makefile for:    Mesa
# Version required:     1.1.3beta
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $Id: Makefile,v 1.5 1995/04/01 12:45:46 jkh Exp $
#

DISTNAME=       Mesa-1.1.3beta
MASTER_SITES=   ftp://iris.ssec.wisc.edu/pub/misc/
CATEGORIES+=	graphics
WRKSRC=		${WRKDIR}/Mesa
USE_GMAKE=
ALL_TARGET=	freebsd
# won't install until I convert the Makefiles to Imakefiles
NO_INSTALL=	yes

# won't need this after I convert the Makefiles to Imakefiles
pre-build:
	if [ ! -e /usr/include/X11 ]; then \
	  ln -s /usr/X11R6/include/X11 /usr/include; \
	fi

.include <bsd.port.mk>
