PORTNAME=	ccid
PORTVERSION=	1.6.1
CATEGORIES=	devel
MASTER_SITES=	https://ccid.apdu.fr/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic driver for USB CCID and ICCD
WWW=		https://ccid.apdu.fr/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		perl5 pkgconfig tar:xz meson
USE_LDCONFIG=	yes
USE_PERL5=	build

MESON_ARGS=	-Dpcsclite=true

.include "../../devel/pcsc-lite/Makefile.common"

BUNDLE_DIR=	${USBDROPDIR}/ifd-ccid.bundle
PLIST_DIRS=	${USBDROPDIR}
PLIST_FILES=	bin/RSA_SecurID_getpasswd \
		bin/Kobil_mIDentity_switch \
		${BUNDLE_DIR}/Contents/FreeBSD/libccid.so \
		${BUNDLE_DIR}/Contents/Info.plist \
		share/man/man1/RSA_SecurID_getpasswd.1.gz \
		share/man/man8/Kobil_mIDentity_switch.8.gz

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${MESON_BUILD_DIR}/Kobil_mIDentity_switch \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/contrib/Kobil_mIDentity_switch/Kobil_mIDentity_switch.8 \
		${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/${MESON_BUILD_DIR}/RSA_SecurID_getpasswd \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/contrib/RSA_SecurID/RSA_SecurID_getpasswd.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
