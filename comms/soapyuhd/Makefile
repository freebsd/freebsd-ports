# $FreeBSD$

PORTNAME=	SoapyUHD
DISTVERSIONPREFIX=	soapy-uhd-
DISTVERSION=	0.3.6
PORTREVISION=	3
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Soapy SDR plugin for the Airspy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libSoapySDR.so:misc/soapysdr \
		libuhd.so:comms/uhd

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	pothosware

PLIST_FILES=	lib/SoapySDR/modules0.7/libuhdSupport.so \
		lib/uhd/modules/libsoapySupport.so

.include <bsd.port.mk>
