# New ports collection makefile for:	xopps
# Version required:	1.13
# Date created:		1 Ag 1997
# Whom:			Pedro Giffuni (orig)
#
# $Id: Makefile,v 1.4 1998/08/05 09:31:34 asami Exp $
#

DISTNAME=	xopps.1.13
PKGNAME=	xopps-1.13
CATEGORIES=	deskutils
MASTER_SITES=	ftp://devvax.jpl.nasa.gov/pub/xopps/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=
USE_X_PREFIX=	yes
REQUIRES_MOTIF=	yes
MACH=		FreeBSD
MAKE_ENV=	'MACH=$(MACH)'

MAN1=	xopps.1

pre-patch:
	$(CP) $(WRKSRC)/Defines.spr $(WRKSRC)/Defines.$(MACH)

.include <bsd.port.mk>
