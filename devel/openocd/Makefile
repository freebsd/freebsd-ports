# New ports collection makefile for:   openocd
# Date created:       16 August 2009
# Whom:               Tomek CeDeROM Cedro (http://www.tomek.cedro.info)
#
# $FreeBSD$
#

PORTNAME=	openocd
PORTVERSION=	0.2.0
CATEGORIES=	devel
MASTER_SITES=	BERLIOS

MAINTAINER=	tomek.cedro@gmail.com
COMMENT=	Open On-Chip Debugger

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/
MAN1=		${PORTNAME}.1
INFO=		${PORTNAME}
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-werror
OPTIONS=	VERBOSE "Enable verbose JTAG I/O messages" off \
		JTAG_IO "Enable verbose JTAG I/O messages" off \
		USB_IO "Enable verbose USB I/O messages" off \
		USB_COMMS "Enable verbose USB communication messages" off \
		DUMMY "Dummy driver support" on \
		FT2232 "FT2232 based USB devices (using libftdi)" on \
		EP93XX "EP93xx based SBCs" on \
		AT91RM9200 "AT91RM9200 based SBCs" on \
		PRESTO "ASIX Presto Programmer (using libftdi)" on \
		USBPROG "Usbprog JTAG Programmer" on \
		JLINK "Segger J-Link JTAG Programmer" on \
		VSLLINK "Versaloon-Link JTAG Programmer" on \
		RLINK "Raisonance RLink JTAG Programmer" on \
		ARMJTAGEW "Olimex ARM-JTAG-EW Programmer" on \
		MINIDRIVER "Dummy minidriver  (will exclude others!)" off
#Below are the interfaces that need source rewitre to work with FreeBSD
# They are hidden because they break a build. Patches are welcome :-)
# Type: make WITH_{OPTION}=1 to try the broken build (ie: make WITH_PARPORT=1)
#		PARPORT "PC parallel port driver" off\
# Parport: parport.c:68:20: error: sys/io.h: No such file or directory
#		AMTJTAGACCEL "Amontec JTAG-Accelerator driver" off \
#		MALLOC "Include free space in logging messages" off \
# Malloc: log.c:41:2: error: #error "malloc.h is required to use --enable-malloc-logging"
# Amtjtagaccel: amt_jtagaccel.c:45:20: error: sys/io.h: No such file or directory
#		ECOSBOARD "eCos based JTAG debugger" off \
# Ecosboard:	replacements.h:36:28: error: pkgconf/system.h: No such file or directory
#		HTTPD "Enable builtin httpd server" off\
# Zy1000: Requires working microhttpd
#		ZY1000 "ZY1000 minidriver (will exclude others!)" off \
# microhttpd does not link properly, used by some Zyli cable
#		GW16012 "Gateworks GW16012 JTAG Programmer" off \
# Gw16012:	gw16012.c:67:20: error: sys/io.h: No such file or directory
#		IOUTIL "Enable ioutil functions" off
#		OOCDTRACE "OpenOCD+trace ETM capture device" off\
# Oocdtrace:	ocd_trace.c:127: error: 'B2500000' undeclared (first use in this function)

.include <bsd.port.options.mk>

.if defined(WITH_VERBOSE)
CONFIGURE_ARGS+=	--enable-verbose
.else
CONFIGURE_ARGS+=	--disable-verbose
.endif

.if defined(WITH_JTAG_IO)
CONFIGURE_ARGS+=	--enable-verbose-jtag-io
.else
CONFIGURE_ARGS+=	--disable-verbose-jtag-io
.endif

.if defined(WITH_USB_IO)
CONFIGURE_ARGS+=	--enable-verbose-usb-io
.else
CONFIGURE_ARGS+=	--disable-verbose-usb-io
.endif

.if defined(WITH_USB_COMMS)
CONFIGURE_ARGS+=	--enable-verbose-usb-comms
.else
CONFIGURE_ARGS+=	--disable-verbose-usb-comms
.endif

.if defined(WITH_MALLOC)
CONFIGURE_ARGS+=	--enable-malloc-logging
.else
CONFIGURE_ARGS+=	--disable-malloc-logging
.endif

.if defined(WITH_DUMMY)
CONFIGURE_ARGS+=	--enable-dummy
.else
CONFIGURE_ARGS+=	--disable-dummy
.endif

.if defined(WITH_PARPORT)
CONFIGURE_ARGS+=	--enable-parport
.else
CONFIGURE_ARGS+=	--disable-parport
.endif

.if defined(WITH_FT2232)
CONFIGURE_ARGS+=	--enable-ft2232_libftdi
USE_LIBFTDI=		yes
.else
CONFIGURE_ARGS+=	--disable-ft2232_libftdi
.endif

.if defined(WITH_AMTJTAGACCEL)
CONFIGURE_ARGS+=	--enable-amtjtagaccel
.else
CONFIGURE_ARGS+=	--disable-amtjtagaccel
.endif

.if defined(WITH_ECOSBOARD)
CONFIGURE_ARGS+=	--enable-ecosboard
.else
CONFIGURE_ARGS+=	--disable-ecosboard
.endif

.if defined(WITH_ZY1000)
CONFIGURE_ARGS+=	--enable-zy1000
.else
CONFIGURE_ARGS+=	--disable-zy1000
.endif

.if defined(WITH_IOUTIL)
CONFIGURE_ARGS+=	--enable-ioutil
.else
CONFIGURE_ARGS+=	--disable-ioutil
.endif

.if defined(WITH_HTTPD)
CONFIGURE_ARGS+=	--enable-httpd
BUILD_DEPENDS+=	libmicrohttpd:${PORTSDIR}/www/libmicrohttpd
LIB_DEPENDS+=		microhttpd:${PORTSDIR}/www/libmicrohttpd
.else
CONFIGURE_ARGS+=	--disable-httpd
.endif

.if defined(WITH_EP93XX)
CONFIGURE_ARGS+=	--enable-ep93xx
.else
CONFIGURE_ARGS+=	--disable-ep93xx
.endif

.if defined(WITH_AT91RM9200)
CONFIGURE_ARGS+=	--enable-at91rm9200
.else
CONFIGURE_ARGS+=	--disable-at91rm9200
.endif

.if defined(WITH_GW16012)
CONFIGURE_ARGS+=	--enable-gw16012
.else
CONFIGURE_ARGS+=	--disable-gw16012
.endif

.if defined(WITH_PRESTO)
CONFIGURE_ARGS+=	--enable-presto_libftdi
USE_LIBFTDI=		yes
.else
CONFIGURE_ARGS+=	--disable-presto_libftdi
.endif

.if defined(WITH_USBPROG)
CONFIGURE_ARGS+=	--enable-usbprog
USE_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-usbprog
.endif

.if defined(WITH_OOCDTRACE)
CONFIGURE_ARGS+=	--enable-oocd_trace
.else
CONFIGURE_ARGS+=	--disable-oocd_trace
.endif

.if defined(WITH_JLINK)
CONFIGURE_ARGS+=	--enable-jlink
USE_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-jlink
.endif

.if defined(WITH_VSLLINK)
CONFIGURE_ARGS+=	--enable-vsllink
USE_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-vsllink
.endif

.if defined(WITH_RLINK)
CONFIGURE_ARGS+=	--enable-rlink
USE_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-rlink
.endif

.if defined(WITH_ARMJTAGEW)
CONFIGURE_ARGS+=	--enable-arm-jtag-ew
USE_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-arm-jtag-ew
.endif

.if defined(WITH_MINIDRIVER)
CONFIGURE_ARGS+=	--enable-minidriver-dummy
.else
CONFIGURE_ARGS+=	--disable-minidriver-dummy
.endif

.include <bsd.port.pre.mk>

.if defined(USE_LIBUSB) && ${OSVERSION} < 800069
LIB_DEPENDS+=		usb:${PORTSDIR}/devel/libusb
.endif

.if defined(USE_LIBFTDI)
LIB_DEPENDS+=		ftdi:${PORTSDIR}/devel/libftdi
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
