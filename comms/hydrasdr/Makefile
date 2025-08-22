PORTNAME=	hydrasdr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
CATEGORIES=	comms hamradio

MAINTAINER=	unitrunker@gmail.com
COMMENT=	HydraSDR RFONE's host library and associated tools
WWW=		https://hydrasdr.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/hydrasdr-tools/LICENSE.md

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_PROJECT=	rfone_host
USE_LDCONFIG=	yes

CMAKE_OFF=	INSTALL_UDEV_RULES
CMAKE_ARGS=	-DLIBUSB_LIBRARIES="/usr/lib/libusb.so" \
		-DLIBUSB_INCLUDE_DIR="/usr/include"
OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD

SIMD_CFLAGS=	-DFREEBSD_USE_SIMD -msse -msse2 -mfpmath=sse -mmmx

CFLAGS_powerpc64=	-DNO_WARN_X86_INTRINSICS -mvsx
CFLAGS_powerpc64le=	-DNO_WARN_X86_INTRINSICS

.include <bsd.port.mk>
