# New ports collection makefile for:	bbrb
# Date created:				19 February 2002
# Whom:					Dan Peck <peckdani@msu.edu>
#
# $FreeBSD$
#

PORTNAME=	bbrb
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical background manager for the Blackbox window manager

RUN_DEPENDS=	xv:${PORTSDIR}/graphics/xv \
		blackbox:${PORTSDIR}/x11-wm/blackbox

USE_X_PREFIX=	yes
USE_GNOME=	imlib
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
