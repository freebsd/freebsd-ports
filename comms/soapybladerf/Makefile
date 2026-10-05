PORTNAME=	SoapyBladeRF
DISTVERSIONPREFIX=	soapy-bladerf-
DISTVERSION=	0.4.2
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Soapy SDR plugin for the Blade RF
WWW=		https://github.com/pothosware/SoapyBladeRF/wiki

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPLv2.1

LIB_DEPENDS=	libbladeRF.so:comms/bladerf \
		libSoapySDR.so:misc/soapysdr

USES=		cmake compiler:c++11-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	pothosware

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/pothosware/SoapyBladeRF/issues/71

PLIST_FILES=	lib/SoapySDR/modules0.8/libbladeRFSupport.so

.include <bsd.port.mk>
