# New ports collection makefile for:    Mesa
# Version required:     1.1.2beta
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $Id: Makefile,v 1.2 1995/03/06 04:35:27 hsu Exp $
#

DISTNAME=       Mesa-1.1.2beta
MASTER_SITES=   ftp://iris.ssec.wisc.edu/pub/misc/
WRKSRC=		${WRKDIR}/Mesa
ALL_TARGET=	freebsd
# won't install until I convert the Makefiles to Imakefiles
NO_INSTALL=	yes

# won't need this after I convert the Makefiles to Imakefiles
pre-build:
	if [ ! -e /usr/include/X11 ]; then \
	  ln -s /usr/X11R6/include/X11 /usr/include; \
	fi

.include <bsd.port.mk>
