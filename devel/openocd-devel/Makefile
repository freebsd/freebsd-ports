PORTNAME=	openocd
DISTVERSION=	g20250708
CATEGORIES=	devel
PKGNAMESUFFIX=	-devel

MAINTAINER=	wiacek.m@witia.com.pl
COMMENT=	Open On-Chip Debugger (development version)
WWW=		https://openocd.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool makeinfo pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	openocd-org
GH_TAGNAME=	6872f7e40
GH_TUPLE=	msteveb:jimtcl:f160866:jimtcl/jimtcl

USE_GITLAB=	nodefault
GL_TUPLE=	https://gitlab.zapb.de:libjaylink:libjaylink:f73ad5e:libjaylink/src/jtag/drivers/libjaylink

GNU_CONFIGURE=	yes

# Required to make OpenOCD's internal libjaylink work
CONFIGURE_ENV+=	libusb_CFLAGS=" " \
		libusb_LIBS="-lusb"

CFLAGS+=	-Wno-error=strict-prototypes \
		-Wno-error=unused-but-set-parameter \
		-Wno-error=unused-but-set-variable
# Conflicts
CONFLICTS_INSTALL=	openocd

INFO=		openocd

# Note: Some adapters are not supported or do not currently work on FreeBSD.
#       These have been consciously left out of this port entirely.

OPTIONS_DEFINE=		CAPSTONE
OPTIONS_DEFAULT=	BITBANG_REMOTE JIMTCL_INTERNAL LIBFTDI LIBHIDAPI LIBUSB \
			SERIAL
OPTIONS_GROUP=		ADAPTERS DEBUG
OPTIONS_GROUP_ADAPTERS=	BITBANG_REMOTE LIBFTDI LIBHIDAPI LIBUSB PARPORT SERIAL
OPTIONS_GROUP_DEBUG=	VERBOSE_JTAGIO VERBOSE_USBCOMM VERBOSE_USBIO
OPTIONS_SINGLE=		JIMTCL
OPTIONS_SINGLE_JIMTCL=	JIMTCL_EXTERNAL JIMTCL_INTERNAL

ADAPTERS_DESC=		Hardware adapters/programmers/debuggers support
BITBANG_REMOTE_DESC=	Remote bitbang driver
CAPSTONE_DESC=		Use Capstone disassembly library
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

CAPSTONE_LIB_DEPENDS=		libcapstone.so:devel/capstone
CAPSTONE_CONFIGURE_WITH=	capstone

# Internal (built-in) or external Jim Tcl interpreter
JIMTCL_EXTERNAL_LIB_DEPENDS=		libjim.so:lang/jimtcl
JIMTCL_EXTERNAL_USES=			localbase:ldflags
JIMTCL_INTERNAL_CONFIGURE_ENABLE=	internal-jimtcl

# Adapters depending on libftdi
LIBFTDI_LIB_DEPENDS=		libftdi1.so:devel/libftdi1
LIBFTDI_CONFIGURE_ENABLE=	openjtag presto usb_blaster

# Adapters depending on libhidapi
LIBHIDAPI_LIB_DEPENDS=		libhidapi.so:comms/hidapi
LIBHIDAPI_CONFIGURE_ENABLE=	cmsis_dap kitprog nulink

# Adapters depending on libusb
LIBUSB_CONFIGURE_ENABLE=	angie armjtagew cmsis_dap_v2 esp_usb_jtag \
				ft232r ftdi opendous osbdm rlink stlink ti_icdi \
				ulink usb_blaster_2 usbprog vsllink xds110

# Parallel port based adapters
PARPORT_CONFIGURE_ENABLE=	parport

# Serial port based adapters
SERIAL_CONFIGURE_ENABLE=	buspirate

# Debug options
VERBOSE_JTAGIO_CONFIGURE_ENABLE=	verbose
VERBOSE_USBCOMM_CONFIGURE_ENABLE=	verbose-usb-comms
VERBOSE_USBIO_CONFIGURE_ENABLE=		verbose-usb-io

.include <bsd.port.mk>
