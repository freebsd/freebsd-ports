# New ports collection Makefile for:		libccid
# Date created:					2005-01-20
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	ccid
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3518/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Generic USB CCID (Chip/Smart Card Interface Devices) driver

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=yes
CONFIGURE_ARGS=	--enable-usbdropdir=${PREFIX}/lib/pcsc/drivers \
		--enable-ccidtwindir=${PREFIX}/lib/pcsc/drivers/serial
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}" \
		LIBUSB_CFLAGS="-I${LOCALBASE}/include" \
		LIBUSB_LIBS="-L${LOCALBASE}/lib -lusb"

PLIST_SUB=	VER=${PORTVERSION}
MAN1=		RSA_SecurID_getpasswd.1
MAN8=		Kobil_mIDentity_switch.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 801000
IGNORE=		needs a complete libusb-1 implementation
.endif

post-patch:
	${REINPLACE_CMD} -e "s,use warnings;,," ${WRKSRC}/src/create_Info_plist.pl
	${REINPLACE_CMD} -e "s,ndef __APPLE__, !(__APPLE__ || __FreeBSD__)," ${WRKSRC}/contrib/Kobil_mIDentity_switch/Kobil_mIDentity_switch.c
	${REINPLACE_CMD} -e "s,libusb-1.0/libusb.h,libusb.h," \
		${WRKSRC}/configure ${WRKSRC}/src/ccid_usb.c \
		${WRKSRC}/src/ccid_usb.h \
		${WRKSRC}/contrib/Kobil_mIDentity_switch/Kobil_mIDentity_switch.c

.include <bsd.port.post.mk>
