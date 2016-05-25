# Created by: mp39590@gmail.com
# $FreeBSD$

PORTNAME=	acsccid
PORTVERSION=	1.1.2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	mp39590@gmail.com
COMMENT=	PC/SC driver for CS CCID smart card readers

LICENSE=	GPLv2

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=	perl5 pkgconfig tar:bz2

PLIST_FILES=	lib/pcsc/drivers/ifd-acsccid.bundle/Contents/FreeBSD/libacsccid.so \
		lib/pcsc/drivers/ifd-acsccid.bundle/Contents/Info.plist

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

# Old versions don't have pkgconfig files for libusb
.if ${OSVERSION} < 1000024
CONFIGURE_ENV+=	LIBUSB_CFLAGS="-I${LOCALBASE}/include" \
		LIBUSB_LIBS="-L${LOCALBASE}/lib -lusb"
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pcsc/drivers/ifd-acsccid.bundle/Contents/FreeBSD/libacsccid.so

.include <bsd.port.post.mk>
