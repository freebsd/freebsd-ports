# $FreeBSD$

PORTNAME=	SoapyBladeRF
DISTVERSIONPREFIX=	soapy-bladerf-
DISTVERSION=	0.4.1
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Soapy SDR plugin for the Blade RF

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPLv2.1

LIB_DEPENDS=	libbladeRF.so:comms/bladerf \
		libSoapySDR.so:misc/soapysdr

USES=		cmake compiler:c++11-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	pothosware

PLIST_FILES=	lib/SoapySDR/modules0.7/libbladeRFSupport.so

.include <bsd.port.mk>
