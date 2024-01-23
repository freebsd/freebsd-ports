PORTNAME=	pcsc-cyberjack
DISTVERSION=	3.99.5final.SP15
PORTREVISION=	3
CATEGORIES=	devel security
MASTER_SITES=	https://downloads.reiner-sct.de/LINUX/V3.99.5_SP15/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tm@NetBSD.org
COMMENT=	Reiner SCT cyberJack card reader PCSC driver
WWW=		https://www.reiner-sct.com/

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYRIGHT.GPL
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYRIGHT.LGPL

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite \
		libxml2.so:textproc/libxml2

USES=		autoreconf dos2unix libtool localbase pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release --with-usbdropdir=${PREFIX}/lib/pcsc/drivers
DOS2UNIX_FILES=	cjeca32/Debug.cpp cjeca32/RSCTCriticalSection.cpp
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

.include <bsd.port.mk>
