PORTNAME=	openocd
DISTVERSION=	0.12.0
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	Open On-Chip Debugger
WWW=		https://openocd.sf.net

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

# Note: A local patch would be feasible but upstream has removed support for the offending feature
#       implementation since their last release (0.12.0). As such, this will no longer be relevant
#       from 0.13.0 onwards. Hence we're not addressing this "limitation" right now.
BROKEN_aarch64=	fails to build: src/target/nds32_tlb.h:25:2: error: expected identifier PAGE_SIZE_4K = 0

USES=		gmake libtool makeinfo pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

# Required to make OpenOCD's internal libjaylink work
CONFIGURE_ENV+=	libusb_CFLAGS=" " libusb_LIBS="-lusb"

CFLAGS+=	-Wno-error=strict-prototypes \
		-Wno-error=unused-but-set-parameter \
		-Wno-error=unused-but-set-variable \

INFO=		openocd

# Note: Some adapters are not supported or do not currently work on FreeBSD.
#       These have been consciously left out of this port entirely.

OPTIONS_DEFAULT=	BITBANG_REMOTE JIMTCL_INTERNAL LIBUSB LIBHIDAPI LIBFTDI SERIAL
OPTIONS_GROUP=		DEBUG ADAPTERS
OPTIONS_GROUP_ADAPTERS=	BITBANG_REMOTE LIBUSB LIBHIDAPI LIBFTDI SERIAL PARPORT
OPTIONS_GROUP_DEBUG=	VERBOSE_JTAGIO VERBOSE_USBIO VERBOSE_USBCOMM
OPTIONS_SINGLE=		JIMTCL
OPTIONS_SINGLE_JIMTCL=	JIMTCL_INTERNAL JIMTCL_EXTERNAL

ADAPTERS_DESC=		Hardware adapters/programmers/debuggers support
BITBANG_REMOTE_DESC=	Remote bitbang driver
JIMTCL_DESC=		Jim Tcl interpreter
JIMTCL_EXTERNAL_DESC=	External
JIMTCL_INTERNAL_DESC=	Internal
LIBFTDI_DESC=		Adapters using libftdi
LIBHIDAPI_DESC=		Adapters using libhidapi
LIBUSB_DESC=		Adapters using libusb
PARPORT_DESC=		Adapters using parallel port
SERIAL_DESC=		Adapters using serial port
VERBOSE_JTAGIO_DESC=	Enable verbose JTAG I/O messages
VERBOSE_USBCOMM_DESC=	Enable verbose USB communication messages
VERBOSE_USBIO_DESC=	Enable verbose USB I/O messages

# Remote bitbang driver
BITBANG_REMOTE_CONFIGURE_ENABLE=	remote-bitbang

# Internal (built-in) or external Jim Tcl interpreter
JIMTCL_EXTERNAL_LIB_DEPENDS=		libjim.so:lang/jimtcl
JIMTCL_EXTERNAL_USES=			localbase:ldflags
JIMTCL_INTERNAL_CONFIGURE_ENABLE=	internal-jimtcl

# Adapters depending on libftdi
LIBFTDI_LIB_DEPENDS=		libftdi.so:devel/libftdi
LIBFTDI_CONFIGURE_ENABLE=	usb_blaster \
				presto \
				openjtag

# Adapters depending on libhidapi
LIBHIDAPI_LIB_DEPENDS=		libhidapi.so:comms/hidapi
LIBHIDAPI_CONFIGURE_ENABLE=	cmsis_dap \
				nulink \
				kitprog

# Adapters depending on libusb
LIBUSB_CONFIGURE_ENABLE=	ftdi \
				stlink \
				ti_icdi \
				ulink \
				angie \
				usb_blaster_2 \
				ft232r \
				vsllink \
				xds110 \
				cmsis_dap_v2 \
				osbdm \
				opendous \
				armjtagew \
				rlink \
				usbprog \
				esp_usb_jtag

# Parallel port based adapters
PARPORT_CONFIGURE_ENABLE=	parport

# Serial port based adapters
SERIAL_CONFIGURE_ENABLE=	buspirate

# Debug options
VERBOSE_JTAGIO_CONFIGURE_ENABLE=	verbose
VERBOSE_USBCOMM_CONFIGURE_ENABLE=	verbose-usb-comms
VERBOSE_USBIO_CONFIGURE_ENABLE=		verbose-usb-io

.include <bsd.port.mk>
