# Created by: Brian Dean <bsd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avrdude
PORTVERSION=	6.3
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH/avrdude

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Program for programming the on-chip memory of Atmel AVR CPUs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		libtool localbase readline
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		FTDI
OPTIONS_DEFAULT=	FTDI
FTDI_DESC=		libftdi support
FTDI_LIB_DEPENDS=	libftdi1.so:devel/libftdi1

post-patch:
	@${REINPLACE_CMD} -e 's|-lusb-1.0|-lusb|g' ${WRKSRC}/configure

post-patch-FTDI-off:
	@${REINPLACE_CMD} -e '/LIBS=/ s|-lftdi1*|&-do-not-detect|' ${WRKSRC}/configure

.include <bsd.port.mk>
