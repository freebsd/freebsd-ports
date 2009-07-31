# New ports collection makefile for:	gpredict
# Date created:		2004-01-22
# Whom:			Matt Dawson <matt@mattsnetwork.co.uk>
#
# $FreeBSD$

PORTNAME=	gpredict
PORTVERSION=	0.9.0
PORTREVISION=	4
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	groundstation

MAINTAINER=	matt@chronos.org.uk
COMMENT=	Amateur Radio satellite tracking and prediction

LIB_DEPENDS=	hamlib:${PORTSDIR}/comms/hamlib:install
BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl:install
RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl:install

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-network
USE_GMAKE=	yes

MAN1=		gpredict.1

DESKTOP_ENTRIES="GPREDICT" \
		"Predict satellite passage times" \
		"${PREFIX}/share/pixmaps/gpredict/icons/gpredict-icon.png" \
		"gpredict" \
		"" \
		true

.include <bsd.port.mk>
