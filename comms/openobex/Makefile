# $FreeBSD$

PORTNAME=	openobex
PORTVERSION=	1.6
CATEGORIES=	comms net
MASTER_SITES=	http://www.hendrik-sattler.de/downloads/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-Source

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Open source implementation of the OBEX protocol

USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	USB

USB_DESC=	Enable OBEX over USB

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUSB}
. if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
CFLAGS+=	-I${PREFIX}/include
. else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure
. endif
CONFIGURE_ARGS+=--enable-usb
.else
CONFIGURE_ARGS+=--disable-usb
.endif

.include <bsd.port.mk>
