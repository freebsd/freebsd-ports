# New ports collection makefile for:	QuIRC
# Version required:	0.9.79
# Date created:		21 May 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	quirc-0.9.79
CATEGORIES=	irc tk82
MASTER_SITES=	http://www.quirc.org/ \
		http://patearl.powersurfr.com/quirc/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

USE_XLIB=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all quirc.inst

pre-install:
	@${MKDIR} ${PREFIX}/share/doc/quirc/doc

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/quirc.inst ${PREFIX}/bin
	@strip ${PREFIX}/bin/quirc

.include <bsd.port.mk>
