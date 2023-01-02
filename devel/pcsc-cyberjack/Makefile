PORTNAME=	pcsc-cyberjack
DISTVERSION=	3.99.5final.SP15
CATEGORIES=	devel security
MASTER_SITES=	https://support.reiner-sct.de/downloads/LINUX/V3.99.5_SP15/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tm@NetBSD.org
COMMENT=	Reiner SCT cyberJack card reader pcsc driver
WWW=		https://www.reiner-sct.de

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYRIGHT.GPL
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYRIGHT.LGPL

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite \
		libxml2.so:textproc/libxml2

USES=		autoreconf compiler:gcc-c++11-lib dos2unix gmake libtool pkgconfig \
		tar:bzip2

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

CONFIGURE_ARGS=	--enable-release --with-usbdropdir=${PREFIX}/lib/pcsc/drivers
CONFIGURE_ENV=	LIBUSB_CFLAGS="-I${LOCALBASE}/include" \
		LIBUSB_LIBS="-L${LOCALBASE}/lib -lusb"
CXXFLAGS+=	-Wno-c++11-narrowing
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.mk>
