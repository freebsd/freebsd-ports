# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urjtag
PORTVERSION=	0.10
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extended utility to work with JTAG-aware boards

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash

USES=		gmake localbase:ldflags readline shebangfix tar:bzip2
SHEBANG_FILES=	src/bsdl2jtag
USE_CSTD=	c99
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		FTDI JEDEC NLS USB
OPTIONS_DEFAULT=	FTDI USB
OPTIONS_SUB=		yes

FTDI_DESC=		FTDI-based USB JTAG adapters support
FTDI_LIB_DEPENDS=	libftdi.so:devel/libftdi
FTDI_CONFIGURE_WITH=	libftdi

JEDEC_DESC=		Experimental JEDEC flash detection
JEDEC_CONFIGURE_ENABLE=	jedec

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

USB_DESC=		USB JTAG adapters support
USB_CONFIGURE_ON=	--with-libusb=/usr

post-patch:
# Suppress svn(1) binary detection
	@${REINPLACE_CMD} -e \
		's|^SVN=.*|SVN=''| ; \
		 s|-Lwith_libusb |-L$$with_libusb/lib | ; \
		 s|-I$$with_libusb"|-I$$with_libusb/include"|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
