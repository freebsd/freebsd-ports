# New ports collection makefile for:	saoimage
# Version required:	1.22
# Date created:		21 Feb 1998
# Whom:			giffunip@asme.org
#
# $Id: Makefile,v 1.1.1.1 1998/04/17 21:27:31 mph Exp $
#

DISTNAME=       saoimage-1.22
CATEGORIES=	astro
MASTER_SITES=	ftp://cfa-ftp.harvard.edu/pub/gsc/SAOimage/Old

MAINTAINER=	giffunip@asme.org

MAKEFILE=	makefile
ALL_TARGET=	FreeBSD
INSTALL_TARGET= -f makefile.$(ALL_TARGET) install_saobin install_saoman

MANL=		saoimage.l
USE_X11=	yes

pre-patch:
	$(CP) $(WRKSRC)/makefile.sun $(WRKSRC)/makefile.$(ALL_TARGET)
pre-build:
	 @(cd ${WRKSRC}; ${MAKE} ${MAKEFILE} clean )
post-install:
	strip $(PREFIX)/bin/saoimage

.include <bsd.port.mk>
