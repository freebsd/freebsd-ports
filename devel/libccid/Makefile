# New ports collection Makefile for:		libccid
# Date created:					2005-01-20
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	ccid
PORTVERSION=	1.3.12
CATEGORIES=	devel
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3281/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Generic USB CCID (Chip/Smart Card Interface Devices) driver

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

LICENSE=	LGPL
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=yes
CONFIGURE_ARGS=	--enable-usbdropdir=${PREFIX}/lib/pcsc/drivers \
		--enable-ccidtwindir=${PREFIX}/lib/pcsc/drivers/serial \
		--enable-udev
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}" \
		LIBUSB_CFLAGS="-I${LOCALBASE}/include" \
		LIBUSB_LIBS="-L${LOCALBASE}/lib -lusb"

PLIST_SUB=	VER=${PORTVERSION}
.if !defined(NOPORTDOCS)
MAN1=		RSA_SecurID_getpasswd.1
MAN8=		Kobil_mIDentity_switch.8
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

post-patch:
	${REINPLACE_CMD} -e "s,use warnings;,," ${WRKSRC}/src/create_Info_plist.pl
	${REINPLACE_CMD} -e "s,ndef __APPLE__, !(__APPLE__ || __FreeBSD__)," ${WRKSRC}/contrib/Kobil_mIDentity_switch/Kobil_mIDentity_switch.c

.include <bsd.port.post.mk>
