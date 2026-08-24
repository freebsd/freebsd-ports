PORTNAME=	airspyhf
DISTVERSION=	1.6.8-7
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User mode driver for Airspy HF+ SDR
WWW=		https://github.com/airspy/airspyhf

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.BSD

USES=		cmake compiler:c11 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	airspy
GH_TAGNAME=	24fe8ffc

CMAKE_ARGS=	-DLIBUSB_LIBRARIES="/usr/lib/libusb.so"
CMAKE_OFF=	INSTALL_UDEV_RULES

OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD

SIMD_CFLAGS=	-DFREEBSD_USE_SIMD -msse -msse2 -mfpmath=sse -mmmx

.include <bsd.port.mk>
