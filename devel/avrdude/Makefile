PORTNAME=	avrdude
PORTVERSION=	7.1
DISTVERSIONPREFIX=	v
#PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Program for programming the on-chip memory of Atmel AVR CPUs
WWW=		https://www.nongnu.org/avrdude/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool localbase readline cmake
USE_GITHUB=	yes
GH_ACCOUNT=	avrdudes
GH_PROJECT=	avrdude

OPTIONS_DEFINE=		FTDI PARPORT
OPTIONS_DEFAULT=	FTDI
FTDI_DESC=		libftdi support
FTDI_LIB_DEPENDS=	libftdi1.so:devel/libftdi1
PARPORT_DESC=		support for parallel-port programmers
PARPORT_CMAKE_ON=	-DHAVE_PARPORT=1

# man page currently not handled by CMake
# https://github.com/avrdudes/avrdude/issues/947
post-install:
	${GZIP_CMD} < ${WRKSRC}/src/avrdude.1 > ${STAGEDIR}/${MANPREFIX}/man/man1/avrdude.1.gz

.include <bsd.port.mk>
