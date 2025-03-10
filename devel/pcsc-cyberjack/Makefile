PORTNAME=	pcsc-cyberjack
DISTVERSION=	3.99.5final.SP16
CATEGORIES=	devel security
MASTER_SITES=	https://support.reiner-sct.de/downloads/LINUX/V3.99.5_SP16/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Reiner SCT cyberJack card reader PCSC driver
WWW=		https://www.reiner-sct.com/

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYRIGHT.GPL
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYRIGHT.LGPL

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		autoreconf dos2unix gnome libtool localbase pkgconfig tar:bzip2
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release --with-usbdropdir=${PREFIX}/lib/pcsc/drivers
DOS2UNIX_FILES=	cjeca32/Debug.cpp \
		cjeca32/RSCTCriticalSection.cpp \
		cjeca32/RSCTCriticalSection.h
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

.include <bsd.port.mk>
