# New ports collection makefile for:   openocd
# Date created:       16 August 2009
# Whom:               Tomasz "CeDeROM" CEDRO (http://www.tomek.cedro.info)
#
# $FreeBSD$
#

PORTNAME=	openocd
PORTVERSION=	0.6.0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	cederom@tlen.pl
COMMENT=	Open On-Chip Debugger

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-werror
OPTIONS=	DOC	"Build HTML and PDF documentation with Doxygen" on \
		JIMTCL	"Build with internal JimTCL interpreter" on \
		VERBOSE	"Enable verbose JTAG I/O messages" off \
		JTAG_IO	"Enable verbose JTAG I/O messages" off \
		USB_IO	"Enable verbose USB I/O messages" off \
		PARPORT	"Support Parallel Port based drivers" on \
		DUMMY	"Support Dummy Driver" on \
		FT2232	"Support FT2232 based USB devices (using libftdi)" on \
		FTDI	"Support experimental FTDI+MPSSE+libusb-1.0 async." on \
		USBBLASTER "Support USB-Blaster Programmer (using libftdi)" on \
		EP93XX	"Support EP93xx based SBCs" on \
		AT91RM9200 "Support AT91RM9200 based SBCs" on \
		PRESTO	"Support ASIX Presto Programmer (using libftdi)" on \
		USBPROG	"Support USB-Prog JTAG Programmer" on \
		JLINK	"Support Segger J-Link JTAG Programmer" on \
		VSLLINK	"Support Versaloon-Link JTAG Programmer" on \
		RLINK	"Support Raisonance RLink JTAG Programmer" on \
		ULINK	"Support Keil ULINK-JTAG Programmer" on \
		ARMJTAGEW "Support Olimex ARM-JTAG-EW Programmer" on \
		BUSPIRATE "Support BusPirate Programmer" on \
		STLINK	"Support STLink Programmer" on \
		OSBDM	"Support OSBDM Programmer (JTAG only)" on \
		OPENDOUS "Support EStick/OpenDous Programmer" on \
		RMTBITBANG "Support Remote-Bitbang Driver" on \
		MINIDRIVER "Dummy minidriver only (will exclude others!)" off

MAN1=		${PORTNAME}.1
INFO=		${PORTNAME}
USE_GMAKE=	yes
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

# IMPORTANT INFORMATION FOR DEVELOPERS:
# Some Interfaces and Options are not on the list because they break a build.
# If you need them working on FreeeBSD, code, patches are welcome :-)

.include <bsd.port.options.mk>

.if defined(WITH_DOC)
CONFIGURE_ARGS+=	--enable-doxygen-pdf
WITH_DOXYGEN=		yes
.else
CONFIGURE_ARGS+=	--disable-doxygen-pdf --disable-doxygen-html
.endif

.if defined(WITH_JIMTCL)
CONFIGURE_ARGS+=	--enable-internal-jimtcl
.else
CONFIGURE_ARGS+=	--disable-internal-jimtcl
.endif

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

.if defined(WITH_PARPORT)
CONFIGURE_ARGS+=	--enable-parport
.else
CONFIGURE_ARGS+=	--disable-parport
.endif

.if defined(WITH_DUMMY)
CONFIGURE_ARGS+=	--enable-dummy
.else
CONFIGURE_ARGS+=	--disable-dummy
.endif

.if defined(WITH_FT2232)
CONFIGURE_ARGS+=	--enable-ft2232_libftdi
WITH_LIBFTDI=		yes
.else
CONFIGURE_ARGS+=	--disable-ft2232_libftdi
.endif

.if defined(WITH_FTDI)
CONFIGURE_ARGS+=	--enable-ftdi
.else
CONFIGURE_ARGS+=	--disable-ftdi
.endif

.if defined(WITH_USBBLASTER)
CONFIGURE_ARGS+=	--enable-usb_blaster_libftdi
.else
CONFIGURE_ARGS+=	--disable-usb_blaster_libftdi
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
WITH_LIBFTDI=		yes
.else
CONFIGURE_ARGS+=	--disable-presto_libftdi
.endif

.if defined(WITH_USBPROG)
CONFIGURE_ARGS+=	--enable-usbprog
WITH_LIBUSB=		yes
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
WITH_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-jlink
.endif

.if defined(WITH_VSLLINK)
CONFIGURE_ARGS+=	--enable-vsllink
WITH_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-vsllink
.endif

.if defined(WITH_RLINK)
CONFIGURE_ARGS+=	--enable-rlink
WITH_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-rlink
.endif

.if defined (WITH_ULINK)
CONFIGURE_ARGS+=	--enable-ulink
.else
CONFIGURE_ARGS+=	--disable-ulink
.endif

.if defined(WITH_ARMJTAGEW)
CONFIGURE_ARGS+=	--enable-arm-jtag-ew
WITH_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-arm-jtag-ew
.endif

.if defined(WITH_BUSPIRATE)
CONFIGURE_ARGS+=	--enable-buspirate
.else
CONFIGURE_ARGS+=	--disable-buspirate
.endif

.if defined(WITH_STLINK)
CONFIGURE_ARGS+=	--enable-stlink
.else
CONFIGURE_ARGS+=	--disable-stlink
.endif

.if defined(WITH_OSBDM)
CONFIGURE_ARGS+=	--enable-osbdm
.else
CONFIGURE_ARGS+=	--disable-osbdm
.endif

.if defined(WITH_OPENDOUS)
CONFIGURE_ARGS+=	--enable-opendous
.else
CONFIGURE_ARGS+=	--disable-opendous
.endif

.if defined(WITH_RMTBITBANG)
CONFIGURE_ARGS+=	--enable-remote-bitbang
.else
CONFIGURE_ARGS+=	--disable-remote-bitbang
.endif

.if defined(WITH_MINIDRIVER)
CONFIGURE_ARGS+=	--enable-minidriver-dummy
.else
CONFIGURE_ARGS+=	--disable-minidriver-dummy
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_LIBUSB) && ${OSVERSION} < 800069
LIB_DEPENDS+=		usb:${PORTSDIR}/devel/libusb
.endif

.if defined(WITH_LIBFTDI)
LIB_DEPENDS+=		ftdi:${PORTSDIR}/devel/libftdi
.endif

.if defined(WITH_DOXYGEN)
BUILD_DEPENDS+=		doxygen:${PORTSDIR}/devel/doxygen
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
