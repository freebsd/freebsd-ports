# New ports collection Makefile for:		libccid
# Date created:					2005-01-20
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	ccid
PORTVERSION=	0.9.3
CATEGORIES=	devel
MASTER_SITES=	http://alioth.debian.org/download.php/992/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Generic USB CCID (Chip/Smart Card Interface Devices) driver

LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb \
		pcsclite.1:${PORTSDIR}/devel/pcsc-lite

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-libusb=${LOCALBASE} \
		--enable-usbdropdir=${LOCALBASE}/lib/pcsc/drivers \
		--enable-ccidtwindir=${LOCALBASE}/lib/pcsc/drivers/serial \
		--enable-pcsclite=yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"

post-patch:
#	${REINPLACE_CMD} -e "s,-lpcsclite,-lpcsclite ${PTHREAD_LIBS}," \
#		${WRKSRC}/examples/Makefile.in
	${REINPLACE_CMD} -e "s,LDLIBS,LIBS,g" ${WRKSRC}/configure

.include <bsd.port.mk>
