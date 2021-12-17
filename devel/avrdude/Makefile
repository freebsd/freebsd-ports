# Created by: Brian Dean <bsd@FreeBSD.org>

PORTNAME=	avrdude
PORTVERSION=	6.4
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH/avrdude

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Program for programming the on-chip memory of Atmel AVR CPUs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		libtool localbase readline gmake
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		FTDI PARPORT
OPTIONS_DEFAULT=	FTDI
FTDI_DESC=		libftdi support
FTDI_LIB_DEPENDS=	libftdi1.so:devel/libftdi1
PARPORT_DESC=		support for parallel-port programmers
PARPORT_CONFIGURE_ENABLE= parport

post-patch-FTDI-off:
	@${REINPLACE_CMD} -e '/LIBS=/ s|-lftdi1*|&-do-not-detect|' ${WRKSRC}/configure

.include <bsd.port.mk>
