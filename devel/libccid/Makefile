PORTNAME=	ccid
PORTVERSION=	1.4.36
CATEGORIES=	devel
MASTER_SITES=	https://ccid.apdu.fr/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic driver for USB CCID and ICCD

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		perl5 pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-usbdropdir=${PREFIX}/lib/pcsc/drivers \
		--enable-ccidtwindir=${PREFIX}/lib/pcsc/drivers/serial

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/RSA_SecurID_getpasswd \
		lib/pcsc/drivers/ifd-ccid.bundle/Contents/FreeBSD/libccid.so \
		lib/pcsc/drivers/ifd-ccid.bundle/Contents/Info.plist \
		man/man1/RSA_SecurID_getpasswd.1.gz

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/RSA_SecurID/RSA_SecurID_getpasswd \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/contrib/RSA_SecurID/RSA_SecurID_getpasswd.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pcsc/drivers/ifd-ccid.bundle/Contents/FreeBSD/libccid.so

.include <bsd.port.mk>
