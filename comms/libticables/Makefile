# New ports collection makefile for:	libticables
# Date created:		27 August 2003
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticables
PORTVERSION=	3.7.7
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tilp

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI calculator link cables library

LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GNOME=	pkgconfig
USE_LIBTOOL_VER=	13
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"\
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	ticables-config.1

.include <bsd.port.mk>
