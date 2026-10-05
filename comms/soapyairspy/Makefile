PORTNAME=	SoapyAirspy
DISTVERSIONPREFIX=	soapy-airspy-
DISTVERSION=	0.2.0
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Soapy SDR plugin for the Airspy
WWW=		https://github.com/pothosware/SoapyAirspy/wiki

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libairspy.so:comms/airspy \
		libSoapySDR.so:misc/soapysdr

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	pothosware

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/pothosware/SoapyAirspy/issues/33

PLIST_FILES=	lib/SoapySDR/modules0.8/libairspySupport.so

.include <bsd.port.mk>
