# New ports collection makefile for:	QuIRC
# Version required:	0.9.77
# Date created:		21 May 1999
# Whom:			Chris Piazza <cpiazza@home.net>
#
# $Id$
#

DISTNAME=	quirc
PKGNAME=	quirc-0.9.77
CATEGORIES=	net tk80
MASTER_SITES=	http://www.quirc.org/ \
		http://patearl.powersurfr.com/quirc/

MAINTAINER=	cpiazza@home.net

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

USE_XLIB=	yes
GNU_CONFIGURE=	yes

post-install:
	@strip ${PREFIX}/bin/quirc

.include <bsd.port.mk>
