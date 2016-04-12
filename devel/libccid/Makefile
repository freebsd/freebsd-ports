# Created by: arved
# $FreeBSD$

PORTNAME=	ccid
PORTVERSION=	1.4.22
CATEGORIES=	devel
MASTER_SITES=	https://alioth.debian.org/frs/download.php/file/4162/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Generic USB CCID (Chip/Smart Card Interface Devices) driver

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		perl5 pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_PERL5=	build
CONFIGURE_ARGS=	--enable-usbdropdir=${PREFIX}/lib/pcsc/drivers \
		--enable-ccidtwindir=${PREFIX}/lib/pcsc/drivers/serial
CONFIGURE_ENV=	LIBUSB_CFLAGS="-I${LOCALBASE}/include" \
		LIBUSB_LIBS="-L${LOCALBASE}/lib -lusb"
CPPFLAGS+=	-I${LOCALBASE}/include

PLIST_SUB=	VER=${PORTVERSION}
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,use warnings;,," ${WRKSRC}/src/create_Info_plist.pl
	${REINPLACE_CMD} -e "s,ndef __APPLE__, !(__APPLE__ || __FreeBSD__)," ${WRKSRC}/contrib/Kobil_mIDentity_switch/Kobil_mIDentity_switch.c
	${REINPLACE_CMD} -e "s,libusb-1.0/libusb.h,libusb.h," \
		${WRKSRC}/configure ${WRKSRC}/src/ccid_usb.c \
		${WRKSRC}/src/ccid_usb.h \
		${WRKSRC}/contrib/Kobil_mIDentity_switch/Kobil_mIDentity_switch.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/RSA_SecurID/RSA_SecurID_getpasswd \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/contrib/RSA_SecurID/RSA_SecurID_getpasswd.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
