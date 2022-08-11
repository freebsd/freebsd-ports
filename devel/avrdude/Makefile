PORTNAME=	avrdude
PORTVERSION=	7.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Program for programming the on-chip memory of Atmel AVR CPUs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		libtool localbase readline cmake
USE_GITHUB=	yes
GH_ACCOUNT=	avrdudes
GH_PROJECT=	avrdude
GH_TAGNAME=	v${PORTVERSION}

OPTIONS_DEFINE=		FTDI PARPORT
OPTIONS_DEFAULT=	FTDI
FTDI_DESC=		libftdi support
FTDI_LIB_DEPENDS=	libftdi1.so:devel/libftdi1
PARPORT_DESC=		support for parallel-port programmers
PARPORT_CONFIGURE_ENABLE= parport

# man page currently not handled by CMake
# https://github.com/avrdudes/avrdude/issues/947
post-install:
	${GZIP_CMD} < ${WRKSRC}/src/avrdude.1 > ${STAGEDIR}/${MANPREFIX}/man/man1/avrdude.1.gz

.include <bsd.port.mk>
