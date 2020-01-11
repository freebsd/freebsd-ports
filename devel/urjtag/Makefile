# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	urjtag
DISTVERSION=	2019.12
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extended utility to work with JTAG-aware boards

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash

USES=		gmake libtool readline tar:xz
USE_CSTD=	c99
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-stapl

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=			FTDI JEDEC NLS PYTHON USB
OPTIONS_DEFAULT=		FTDI USB
OPTIONS_SUB=			yes

FTDI_DESC=			FTDI-based USB JTAG adapters support
FTDI_LIB_DEPENDS=		libftdi1.so:devel/libftdi1
FTDI_CONFIGURE_WITH=		libftdi

JEDEC_DESC=			Experimental JEDEC flash detection
JEDEC_CONFIGURE_ENABLE=		jedec-exp

NLS_USES=			gettext
NLS_CONFIGURE_ENABLE=		nls

PYTHON_CONFIGURE_ENABLE=	python
PYTHON_BROKEN=			ld: error: unable to find library -l-Wl,-rpath

USB_DESC=			USB JTAG adapters support
USB_CONFIGURE_ON=		--with-libusb=/usr
USB_CONFIGURE_OFF=		--without-libusb

.include <bsd.port.mk>
