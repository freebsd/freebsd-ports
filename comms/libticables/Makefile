# New ports collection makefile for:	libticables
# Date created:		27 August 2003
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticables
PORTVERSION=	3.9.2
CATEGORIES=	comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tilp

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI calculator link cables library

LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack pkgconfig
USE_LIBTOOL_VER=	15
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
