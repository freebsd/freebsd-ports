# Created by: Bruce M. Simpson <bms@FreeBSD.org>

PORTNAME=	urjtag
DISTVERSION=	2021.03
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

OPTIONS_DEFINE=			FTDI JEDEC NOASYNC NLS PYTHON USB
OPTIONS_DEFAULT=		FTDI USB
OPTIONS_SUB=			yes

FTDI_DESC=			FTDI-based USB JTAG adapters support
FTDI_LIB_DEPENDS=		libftdi1.so:devel/libftdi1
FTDI_CONFIGURE_WITH=		libftdi

JEDEC_DESC=			Experimental JEDEC flash detection
JEDEC_CONFIGURE_ENABLE=		jedec-exp

NOASYNC_DESC=			Disable the libftdi async mode # possible workaround for bugs like bug#251533

NLS_USES=			gettext
NLS_CONFIGURE_ENABLE=		nls

PYTHON_CONFIGURE_ENABLE=	python
PYTHON_BROKEN=			ld: error: unable to find library -l-Wl,-rpath # see https://sourceforge.net/p/urjtag/bugs/132/

USB_DESC=			USB JTAG adapters support
#USB_CONFIGURE_ON=		--with-libusb=/usr # causes libusb to not be recognized: https://sourceforge.net/p/urjtag/bugs/133/
USB_CONFIGURE_OFF=		--without-libusb

post-patch-NOASYNC-on:
	@${REINPLACE_CMD} -e 's|"ftdi_read_data_submit"|"ftdi_read_data_submitx"|' ${WRKSRC}/configure

.include <bsd.port.mk>
