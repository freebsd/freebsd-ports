PORTNAME=	SoapyAirspy
DISTVERSIONPREFIX=	soapy-airspy-
DISTVERSION=	0.2.0
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Soapy SDR plugin for the Airspy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libairspy.so:comms/airspy \
		libSoapySDR.so:misc/soapysdr

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	pothosware

PLIST_FILES=	lib/SoapySDR/modules0.8/libairspySupport.so

.include <bsd.port.mk>
