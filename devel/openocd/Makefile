# New ports collection makefile for:   openocd
# Date created:       31 May 2009
# Whom:               Tomek CeDeROM Cedro (http://www.tomek.cedro.info)
#
# $FreeBSD$
#

PORTNAME=	openocd
PORTVERSION=	0.1.0
CATEGORIES=	devel
MASTER_SITES=	BERLIOS

MAINTAINER=	tomek.cedro@gmail.com
COMMENT=	Open On-Chip Debugger

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/
MAN1=		openocd.1
INFO=		${PORTNAME}
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release
OPTIONS=	DUMMY "Dummy driver support" on \
		FT2232 "FT2232 based USB devices (using libftdi)" on \
		RLINK "Raisonance RLink JTAG Programmer" on \
		JLINK "Segger J-Link JTAG Programmer" on \
		VSLLINK "Versaloon-Link JTAG Programmer" on \
		USBPROG "usbprog JTAG Programmer" on \
		PRESTO "ASIX Presto Programmer (using libftdi)" on \
		AT91RM9200 "AT91RM9200 based SBCs" on \
		EP93XX "EP93xx based SBCs" on
#Below are the interfaces that need source rewitre to work with FreeBSD
# They are hidden because they break a build. Patches are welcome :-)
# Type: make WITH_{OPTION}=1 to try the broken build (ie: make WITH_PARPORT=1)
#		PARPORT "Enable building the pc parallel port driver" off\
# Parport: parport.c:68:20: error: sys/io.h: No such file or directory
#		AMTJTAGACCEL "Amontec JTAG-Accelerator driver" off \
# Amtjtagaccel: amt_jtagaccel.c:45:20: error: sys/io.h: No such file or directory
#		ECOSBOARD "eCosBoard based JTAG debugger" off\
# Ecosboard:	replacements.h:36:28: error: pkgconf/system.h: No such file or directory
#		OOCDTRACE "OpenOCD+trace ETM capture device" off\
# Oocdtrace:	ocd_trace.c:127: error: 'B2500000' undeclared (first use in this function)
#		GW16012 "Gateworks GW16012 JTAG Programmer" off\
# Gw16012:	gw16012.c:67:20: error: sys/io.h: No such file or directory
#		HTTPD "Enable builtin httpd server" off\
# microhttpd does not link properly, used by some Zyli cable
#		IOUTIL "Enable ioutil functions" off

.include <bsd.port.options.mk>

.if defined(WITH_DUMMY)
CONFIGURE_ARGS+=	--enable-dummy
.else
CONFIGURE_ARGS+=	--disable-dummy
.endif

.if defined(WITH_FT2232)
CONFIGURE_ARGS+=	--enable-ft2232_libftdi
USE_LIBFTDI=		yes
.else
CONFIGURE_ARGS+=	--disable-ft2232_libftdi
.endif

.if defined(WITH_PARPORT)
CONFIGURE_ARGS+=	--enable-parport
.else
CONFIGURE_ARGS+=	--disable-parport
.endif

.if defined(WITH_AMTJTAGACCEL)
CONFIGURE_ARGS+=	--enable-amtjtagaccel
USE_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-amtjtagaccel
.endif

.if defined(WITH_ECOSBOARD)
CONFIGURE_ARGS+=	--enable-ecosboard
USE_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-ecosboard
.endif

.if defined(WITH_RLINK)
CONFIGURE_ARGS+=	--enable-rlink
USE_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-rlink
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

.if defined(WITH_OOCDTRACE)
CONFIGURE_ARGS+=	--enable-oocd_trace
USE_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-oocd_trace
.endif

.if defined(WITH_USBPROG)
CONFIGURE_ARGS+=	--enable-usbprog
USE_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-usbprog
.endif

.if defined(WITH_PRESTO)
CONFIGURE_ARGS+=	--enable-presto_libftdi
USE_LIBFTDI=		yes
.else
CONFIGURE_ARGS+=	--disable-presto_libftdi
.endif

.if defined(WITH_GW16012)
CONFIGURE_ARGS+=	--enable-gw16012
USE_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-gw16012
.endif

.if defined(WITH_AT91RM9200)
CONFIGURE_ARGS+=	--enable-at91rm9200
USE_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-at91rm9200
.endif

.if defined(WITH_EP93XX)
CONFIGURE_ARGS+=	--enable-ep93xx
USE_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-ep93xx
.endif

.if defined(WITH_HTTPD)
CONFIGURE_ARGS+=	--enable-httpd
LIB_DEPENDS+=		microhttpd:${PORTSDIR}/www/libmicrohttpd
.else
CONFIGURE_ARGS+=	--disable-httpd
.endif

.if defined(WITH_IOUTIL)
CONFIGURE_ARGS+=	--enable-ioutil
.else
CONFIGURE_ARGS+=	--disable-ioutil
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
