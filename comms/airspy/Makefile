PORTNAME=	airspy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.10
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	AirSpy's usemode driver and associated tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/airspy-tools/LICENSE.md

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_PROJECT=	airspyone_host
USE_LDCONFIG=	yes

CMAKE_OFF=	INSTALL_UDEV_RULES
CMAKE_ARGS=	-DLIBUSB_LIBRARIES="/usr/lib/libusb.so"

OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD

SIMD_CFLAGS=	-DFREEBSD_USE_SIMD -msse -msse2 -mfpmath=sse -mmmx

.include <bsd.port.mk>
