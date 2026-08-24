PORTNAME=	avrdude
PORTVERSION=	8.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Program for programming the on-chip memory of Atmel AVR CPUs
WWW=		https://github.com/avrdudes/avrdude/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase readline cmake ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	avrdudes
GH_PROJECT=	avrdude

LIB_DEPENDS+=libhidapi.so:comms/hidapi
LIB_DEPENDS+=libserialport.so:devel/libserialport

OPTIONS_DEFINE=		FTDI PARPORT GUI
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	FTDI
FTDI_DESC=		libftdi support
FTDI_LIB_DEPENDS=	libftdi1.so:devel/libftdi1
PARPORT_DESC=		support for parallel-port programmers
PARPORT_CMAKE_ON=	-DHAVE_PARPORT=1
GUI_DESC=		build SWIG / Python GUI
GUI_USES=		python
GUI_BUILD_DEPENDS=	swig:devel/swig
GUI_LIB_DEPENDS=	libpython${PYTHON_VER}.so:${PYTHON_PORTSDIR}

# man page currently not handled by CMake
# https://github.com/avrdudes/avrdude/issues/947
post-install:
	${GZIP_CMD} < ${WRKSRC}/src/avrdude.1 > ${STAGEDIR}/${PREFIX}/share/man/man1/avrdude.1.gz

.include <bsd.port.mk>
