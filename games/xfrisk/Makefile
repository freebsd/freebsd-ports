# New ports collection makefile for:   xfrisk
# Version required:    0.99c0pl9
# Date created:        20 April 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $Id: Makefile,v 1.2 1997/11/16 09:13:49 fenner Exp $
#

DISTNAME=	XFrisk-0.99c0pl9
PKGNAME=	xfrisk-0.99c09
CATEGORIES=	games
MASTER_SITES=	$(MASTER_SITE_XCONTRIB)
MASTER_SITE_SUBDIR=	games/multiplayer/

MAINTAINER=	mph@pobox.com

BROKEN=		package

NO_CDROM=	Possible trademark infringement

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

pre-configure:
	touch ${WRKSRC}/types.h

.include <bsd.port.mk>
