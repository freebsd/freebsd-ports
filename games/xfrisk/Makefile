# New ports collection makefile for:   xfrisk
# Version required:    1.00
# Date created:        20 April 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $Id: Makefile,v 1.6 1998/04/17 23:26:23 mph Exp $
#

DISTNAME=	XFrisk-1.00
PKGNAME=	xfrisk-1.00
CATEGORIES=	games
MASTER_SITES=	$(MASTER_SITE_XCONTRIB)
MASTER_SITE_SUBDIR=	games/multiplayer

MAINTAINER=	mph@freebsd.org

NO_CDROM=	Possible trademark infringement

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

pre-configure:
	${TOUCH} ${WRKSRC}/types.h

.include <bsd.port.mk>
