# New ports collection Makefile for:		libccid
# Date created:					2005-01-20
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	ccid
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://alioth.debian.org/download.php/1474/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Generic USB CCID (Chip/Smart Card Interface Devices) driver

LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb \
		pcsclite.1:${PORTSDIR}/devel/pcsc-lite

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-usbdropdir=${LOCALBASE}/lib/pcsc/drivers \
		--enable-ccidtwindir=${LOCALBASE}/lib/pcsc/drivers/serial \
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}" \
		LIBUSB_CFLAGS="-I${LOCALBASE}/include" \
		LIBUSB_LIBS="-L${LOCALBASE}/lib -lusb"

.include <bsd.port.mk>
