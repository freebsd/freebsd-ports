# New ports collection makefile for:	QuIRC
# Version required:	0.9.77
# Date created:		21 May 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $Id: Makefile,v 1.1.1.1 1999/06/09 01:58:17 steve Exp $
#

DISTNAME=	quirc
PKGNAME=	quirc-0.9.77
CATEGORIES=	net tk80
MASTER_SITES=	http://www.quirc.org/ \
		http://patearl.powersurfr.com/quirc/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

USE_XLIB=	yes
GNU_CONFIGURE=	yes

post-install:
	@strip ${PREFIX}/bin/quirc

.include <bsd.port.mk>
