# Created by: Tomasz "CeDeROM" CEDRO (http://www.tomek.cedro.info)
# $FreeBSD$

PORTNAME=	openocd
PORTVERSION=	0.10.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Open On-Chip Debugger

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-werror

OPTIONS_DEFINE=	DOXYGEN JIMTCL VERBOSE JTAG_IO USB_IO PARPORT DUMMY FT2232 FTDI \
	USBBLASTER EP93XX AT91RM9200 PRESTO USBPROG JLINK VSLLINK RLINK ULINK \
	ARMJTAGEW BUSPIRATE TIICDI STLINK OSBDM OPENDOUS SYSFSGPIO RMTBITBANG \
	MINIDRIVER CMSISDAP USB_COMMS
OPTIONS_DEFAULT=JIMTCL PARPORT DUMMY FT2232 FTDI USBBLASTER EP93XX \
	AT91RM9200 PRESTO USBPROG JLINK VSLLINK RLINK ULINK ARMJTAGEW \
	BUSPIRATE STLINK OSBDM OPENDOUS RMTBITBANG

DOXYGEN_DESC=	Build HTML and PDF documentation with Doxygen
JIMTCL_DESC=	Build with internal JimTCL interpreter
VERBOSE_DESC=	Enable verbose JTAG I/O messages
JTAG_IO_DESC=	Enable verbose JTAG I/O messages
USB_IO_DESC=	Enable verbose USB I/O messages
PARPORT_DESC=	Support Parallel Port based drivers
DUMMY_DESC=	Support Dummy Driver
FT2232_DESC=	Support FT2232 based USB devices (using libftdi)
FTDI_DESC=	Support experimental FTDI+MPSSE+libusb-1.0 async.
USBBLASTER_DESC=Support USB-Blaster Programmer (using libftdi)
EP93XX_DESC=	Support EP93xx based SBCs
AT91RM9200_DESC=Support AT91RM9200 based SBCs
PRESTO_DESC=	Support ASIX Presto Programmer (using libftdi)
USBPROG_DESC=	Support USB-Prog JTAG Programmer
JLINK_DESC=	Support Segger J-Link JTAG Programmer
VSLLINK_DESC=	Support Versaloon-Link JTAG Programmer
RLINK_DESC=	Support Raisonance RLink JTAG Programmer
ULINK_DESC=	Support Keil ULINK-JTAG Programmer
ARMJTAGEW_DESC=	Support Olimex ARM-JTAG-EW Programmer
BUSPIRATE_DESC=	Support BusPirate Programmer
STLINK_DESC=	Support STLink Programmer
OSBDM_DESC=	Support OSBDM Programmer (JTAG only)
OPENDOUS_DESC=	Support EStick/OpenDous Programmer
SYSFSGPIO_DESC=	Support Programming via sysfs GPIOs
RMTBITBANG_DESC=	Support Remote-Bitbang Driver
MINIDRIVER_DESC=	Dummy minidriver only (will exclude others!)
CMSISDAP_DESC=	Support for CMSIS-DAP Compliant Debugger
TIICDI_DESC=	Support for the TI ICDI JTAG Programmer
USB_COMMS_DESC=	Enable verbose USB communication messages

USES=		gmake libtool makeinfo pkgconfig tar:bzip2
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -Wno-error
INFO=		openocd

post-patch:
	@${REINPLACE_CMD} -e '/PKG_CONFIG/{/1\.0/!s/libusb/&-0.1/;}' \
		${WRKSRC}/configure

# IMPORTANT INFORMATION FOR DEVELOPERS:
# Some Interfaces and Options are not on the list because they break a build.
# If you need them working on FreeeBSD, code, patches are welcome :-)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
CONFIGURE_ARGS+=	--enable-doxygen-pdf
WITH_DOXYGEN=		yes
.else
CONFIGURE_ARGS+=	--disable-doxygen-pdf --disable-doxygen-html
.endif

.if ${PORT_OPTIONS:MJIMTCL}
CONFIGURE_ARGS+=	--enable-internal-jimtcl
.else
CONFIGURE_ARGS+=	--disable-internal-jimtcl
.endif

.if ${PORT_OPTIONS:MVERBOSE}
CONFIGURE_ARGS+=	--enable-verbose
.else
CONFIGURE_ARGS+=	--disable-verbose
.endif

.if ${PORT_OPTIONS:MJTAG_IO}
CONFIGURE_ARGS+=	--enable-verbose-jtag-io
.else
CONFIGURE_ARGS+=	--disable-verbose-jtag-io
.endif

.if ${PORT_OPTIONS:MUSB_IO}
CONFIGURE_ARGS+=	--enable-verbose-usb-io
.else
CONFIGURE_ARGS+=	--disable-verbose-usb-io
.endif

.if ${PORT_OPTIONS:MUSB_COMMS}
CONFIGURE_ARGS+=	--enable-verbose-usb-comms
.else
CONFIGURE_ARGS+=	--disable-verbose-usb-comms
.endif

.if ${PORT_OPTIONS:MMALLOC}
CONFIGURE_ARGS+=	--enable-malloc-logging
.else
CONFIGURE_ARGS+=	--disable-malloc-logging
.endif

.if ${PORT_OPTIONS:MPARPORT}
CONFIGURE_ARGS+=	--enable-parport
.else
CONFIGURE_ARGS+=	--disable-parport
.endif

.if ${PORT_OPTIONS:MDUMMY}
CONFIGURE_ARGS+=	--enable-dummy
.else
CONFIGURE_ARGS+=	--disable-dummy
.endif

.if ${PORT_OPTIONS:MFT2232}
CONFIGURE_ARGS+=	--enable-legacy-ft2232_libftdi
WITH_LIBFTDI=		yes
.else
CONFIGURE_ARGS+=	--disable-legacy-ft2232_libftdi
.endif

.if ${PORT_OPTIONS:MFTDI}
CONFIGURE_ARGS+=	--enable-ftdi
WITH_LIBFTDI=		yes
.else
CONFIGURE_ARGS+=	--disable-ftdi
.endif

.if ${PORT_OPTIONS:MUSBBLASTER}
CONFIGURE_ARGS+=	--enable-usb_blaster_libftdi
.else
CONFIGURE_ARGS+=	--disable-usb_blaster_libftdi
.endif

.if ${PORT_OPTIONS:MAMTJTAGACCEL}
CONFIGURE_ARGS+=	--enable-amtjtagaccel
.else
CONFIGURE_ARGS+=	--disable-amtjtagaccel
.endif

.if ${PORT_OPTIONS:MZY1000}
CONFIGURE_ARGS+=	--enable-zy1000
.else
CONFIGURE_ARGS+=	--disable-zy1000
.endif

.if ${PORT_OPTIONS:MIOUTIL}
CONFIGURE_ARGS+=	--enable-ioutil
.else
CONFIGURE_ARGS+=	--disable-ioutil
.endif

.if ${PORT_OPTIONS:MEP93XX}
CONFIGURE_ARGS+=	--enable-ep93xx
.else
CONFIGURE_ARGS+=	--disable-ep93xx
.endif

.if ${PORT_OPTIONS:MAT91RM9200}
CONFIGURE_ARGS+=	--enable-at91rm9200
.else
CONFIGURE_ARGS+=	--disable-at91rm9200
.endif

.if ${PORT_OPTIONS:MGW16012}
CONFIGURE_ARGS+=	--enable-gw16012
.else
CONFIGURE_ARGS+=	--disable-gw16012
.endif

.if ${PORT_OPTIONS:MPRESTO}
CONFIGURE_ARGS+=	--enable-presto_libftdi
WITH_LIBFTDI=		yes
.else
CONFIGURE_ARGS+=	--disable-presto_libftdi
.endif

.if ${PORT_OPTIONS:MUSBPROG}
CONFIGURE_ARGS+=	--enable-usbprog
WITH_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-usbprog
.endif

.if ${PORT_OPTIONS:MOOCDTRACE}
CONFIGURE_ARGS+=	--enable-oocd_trace
.else
CONFIGURE_ARGS+=	--disable-oocd_trace
.endif

.if ${PORT_OPTIONS:MJLINK}
CONFIGURE_ARGS+=	--enable-jlink
WITH_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-jlink
.endif

.if ${PORT_OPTIONS:MVSLLINK}
CONFIGURE_ARGS+=	--enable-vsllink
WITH_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-vsllink
.endif

.if ${PORT_OPTIONS:MRLINK}
CONFIGURE_ARGS+=	--enable-rlink
WITH_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-rlink
.endif

.if ${PORT_OPTIONS:MULINK}
CONFIGURE_ARGS+=	--enable-ulink
.else
CONFIGURE_ARGS+=	--disable-ulink
.endif

.if ${PORT_OPTIONS:MARMJTAGEW}
CONFIGURE_ARGS+=	--enable-arm-jtag-ew
WITH_LIBUSB=		yes
.else
CONFIGURE_ARGS+=	--disable-arm-jtag-ew
.endif

.if ${PORT_OPTIONS:MBUSPIRATE}
CONFIGURE_ARGS+=	--enable-buspirate
.else
CONFIGURE_ARGS+=	--disable-buspirate
.endif

.if ${PORT_OPTIONS:MSTLINK}
CONFIGURE_ARGS+=	--enable-stlink
.else
CONFIGURE_ARGS+=	--disable-stlink
.endif

.if ${PORT_OPTIONS:MTIICDI}
CONFIGURE_ARGS+=	--enable-ti-icdi
.else
CONFIGURE_ARGS+=	--disable-ti-icdi
.endif

.if ${PORT_OPTIONS:MOSBDM}
CONFIGURE_ARGS+=	--enable-osbdm
.else
CONFIGURE_ARGS+=	--disable-osbdm
.endif

.if ${PORT_OPTIONS:MOPENDOUS}
CONFIGURE_ARGS+=	--enable-opendous
.else
CONFIGURE_ARGS+=	--disable-opendous
.endif

.if ${PORT_OPTIONS:MSYSFSGPIO}
CONFIGURE_ARGS+=	--enable-sysfsgpio
.else
CONFIGURE_ARGS+=	--disable-sysfsgpio
.endif

.if ${PORT_OPTIONS:MRMTBITBANG}
CONFIGURE_ARGS+=	--enable-remote-bitbang
.else
CONFIGURE_ARGS+=	--disable-remote-bitbang
.endif

.if ${PORT_OPTIONS:MMINIDRIVER}
CONFIGURE_ARGS+=	--enable-minidriver-dummy
.else
CONFIGURE_ARGS+=	--disable-minidriver-dummy
.endif

.if ${PORT_OPTIONS:MCMSISDAP}
CONFIGURE_ARGS+=	--enable-cmsis-dap
LIB_DEPENDS+=		libhidapi.so:comms/hidapi
.else
CONFIGURE_ARGS+=	--disable-cmsis-dap
.endif

.if defined(WITH_LIBFTDI)
LIB_DEPENDS+=		libftdi.so:devel/libftdi
.endif

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=		doxygen:devel/doxygen
.endif

.include <bsd.port.mk>
