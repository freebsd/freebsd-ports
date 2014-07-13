# Created by: arved
# $FreeBSD$

PORTNAME=	ccid
PORTVERSION=	1.4.17
CATEGORIES=	devel
MASTER_SITES=	https://alioth.debian.org/frs/download.php/file/4091/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Generic USB CCID (Chip/Smart Card Interface Devices) driver

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcsclite.so:${PORTSDIR}/devel/pcsc-lite

USES=		pkgconfig perl5 tar:bzip2
GNU_CONFIGURE=	yes
USE_PERL5=	build
CONFIGURE_ARGS=	--enable-usbdropdir=${PREFIX}/lib/pcsc/drivers \
		--enable-ccidtwindir=${PREFIX}/lib/pcsc/drivers/serial
CONFIGURE_ENV=	LIBUSB_CFLAGS="-I${LOCALBASE}/include" \
		LIBUSB_LIBS="-L${LOCALBASE}/lib -lusb"
CPPFLAGS+=	-I${LOCALBASE}/include

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 801000
IGNORE=		needs a complete libusb-1 implementation
.endif

.if ${OSVERSION} < 1000000
FETCH_DEPENDS=	wget:${PORTSDIR}/ftp/wget
DISABLE_SIZE=	yes
FETCH_CMD=	${LOCALBASE}/bin/wget -c -nc --no-check-certificate
.endif

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
