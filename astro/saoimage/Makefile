# New ports collection makefile for:	saoimage
# Version required:	1.22
# Date created:		21 Feb 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

DISTNAME=       saoimage-1.22
CATEGORIES=	astro
MASTER_SITES=	ftp://cfa-ftp.harvard.edu/pub/gsc/SAOimage/Old/

MAINTAINER=	giffunip@asme.org

MAKEFILE=	makefile
ALL_TARGET=	FreeBSD
INSTALL_TARGET= -f makefile.$(ALL_TARGET) install_saobin install_saoman

MANL=		saoimage.l
USE_X_PREFIX=	yes

pre-patch:
	$(CP) $(WRKSRC)/makefile.sun $(WRKSRC)/makefile.$(ALL_TARGET)
pre-build:
	@(cd ${WRKSRC}/btnlib; ${MAKE})
post-install:
	strip $(PREFIX)/bin/saoimage

.include <bsd.port.mk>
