# New ports collection makefile for:   xfrisk
# Date created:        20 April 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	xfrisk
PORTVERSION=	1.00
CATEGORIES=	games
MASTER_SITES=	$(MASTER_SITE_XCONTRIB)
MASTER_SITE_SUBDIR=	games/multiplayer
DISTNAME=	XFrisk-${PORTVERSION}

MAINTAINER=	mph@freebsd.org

NO_CDROM=	Possible trademark infringement

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

pre-configure:
	${TOUCH} ${WRKSRC}/types.h

.include <bsd.port.mk>
