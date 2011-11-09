# New ports collection makefile for:	openobex
# Date created:				15 March 2004
# Whom:					Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	openobex
PORTVERSION=	1.4
CATEGORIES=	comms net
MASTER_SITES=	${MASTER_SITE_KERNEL_ORG}
MASTER_SITE_SUBDIR=	linux/bluetooth

MAINTAINER=	mad@madpilot.net
COMMENT=	Open source implementation of the OBEX protocol

USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
MAKE_JOBS_SAFE=	yes

OPTIONS=	LIBUSB "Enable OBEX over USB" no

.include <bsd.port.pre.mk>

.if defined(WITH_LIBUSB)
. if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
CFLAGS+=	-I${PREFIX}/include
. else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure
. endif
CONFIGURE_ARGS+=--enable-usb
.else
CONFIGURE_ARGS+=--disable-usb
.endif

.include <bsd.port.post.mk>
