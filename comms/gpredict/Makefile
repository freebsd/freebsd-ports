# New ports collection makefile for:	gpredict
# Date created:		2004-01-22
# Whom:			Matt Dawson <matt@mattsnetwork.co.uk>
#
# $FreeBSD$

PORTNAME=	gpredict
PORTVERSION=	0.4.99.6
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	groundstation

MAINTAINER=	matt@mattsnetwork.co.uk
COMMENT=	Amateur Radio satellite tracking and prediction

USE_X_PREFIX=	yes
USE_GNOME=	gnomecanvas gal
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-nls	# nls isn't supported yet

.include <bsd.port.mk>
