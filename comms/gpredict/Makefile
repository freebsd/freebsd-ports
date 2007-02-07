# New ports collection makefile for:	gpredict
# Date created:		2004-01-22
# Whom:			Matt Dawson <matt@mattsnetwork.co.uk>
#
# $FreeBSD$

PORTNAME=	gpredict
PORTVERSION=	0.7.1
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	groundstation

MAINTAINER=	matt@chronos.org.uk
COMMENT=	Amateur Radio satellite tracking and prediction

LIB_DEPENDS=	hamlib:${PORTSDIR}/comms/hamlib:install

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man

MAN1=		gpredict.1

.include <bsd.port.mk>
