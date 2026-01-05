PORTNAME=	acsccid
PORTVERSION=	1.1.13
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	mp39590@gmail.com
COMMENT=	PC/SC driver for CS CCID smart card readers
WWW=		https://www.acs.com.hk/en/driver/4/acr38-smart-card-reader/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		perl5 pkgconfig tar:bz2

PLIST_FILES=	lib/pcsc/drivers/ifd-acsccid.bundle/Contents/${OPSYS}/libacsccid.so \
		lib/pcsc/drivers/ifd-acsccid.bundle/Contents/Info.plist

GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pcsc/drivers/ifd-acsccid.bundle/Contents/${OPSYS}/libacsccid.so

.include <bsd.port.mk>
