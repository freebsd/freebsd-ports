# New ports collection makefile for:	libticables
# Date created:		27 August 2003
# Whom:			Tijl Coosemans <tijl@ulyssis.org>
#
# $FreeBSD$
#

PORTNAME=	libticables
PORTVERSION=	3.7.7
CATEGORIES=	comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tilp

MAINTAINER=	tijl@ulyssis.org
COMMENT=	TI calculator link cables library

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

WANT_AUTOMAKE_VER=	15
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"\
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	ticables-config.1

.include <bsd.port.pre.mk>

.if defined(WITH_LIBUSB) || exists(${LOCALBASE}/bin/libusb-config)
LIB_DEPENDS+=	usb-0.1.7:${PORTSDIR}/devel/libusb
.else
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG} "If you want to compile with USB support, hit Ctrl-C"
	@${ECHO_MSG} "right now and use \"make WITH_LIBUSB=yes\""
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG}
.endif #WITH_LIBUSB

.include <bsd.port.post.mk>
