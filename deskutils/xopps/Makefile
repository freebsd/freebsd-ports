# New ports collection makefile for:	xopps
# Version required:	1.13
# Date created:		1 Ag 1997
# Whom:			Pedro Giffuni (orig)
#
# $Id: Makefile,v 1.1.1.1 1997/07/31 08:18:36 tg Exp $
#

DISTNAME=	xopps.1.13
PKGNAME=	xopps-1.13
CATEGORIES=	misc
MASTER_SITES=	ftp://devvax.jpl.nasa.gov/pub/xopps/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=
USE_X11=	yes
REQUIRES_MOTIF=	yes
MOTIF_STATIC=	yes
MACH=		FreeBSD
MAKE_ENV=	'MACH=$(MACH)'

MAN1=	xopps.1

pre-patch:
	$(CP) $(WRKSRC)/Defines.spr $(WRKSRC)/Defines.$(MACH)

.include <bsd.port.mk>
