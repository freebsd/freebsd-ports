# $FreeBSD$

PORTNAME=	SoapyAirspy
DISTVERSIONPREFIX=	soapy-airspy-
DISTVERSION=	0.1.2
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Soapy SDR plugin for the Airspy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libairspy.so:comms/airspy \
		libSoapySDR.so:misc/soapysdr

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	pothosware

PLIST_FILES=	lib/SoapySDR/modules0.7/libairspySupport.so

.include <bsd.port.mk>
