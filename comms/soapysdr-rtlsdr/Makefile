PORTNAME=	SoapyRTLSDR
DISTVERSIONPREFIX=	soapy-rtl-sdr-
DISTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Soapy SDR module for RTLSDR

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libSoapySDR.so:misc/soapysdr \
		librtlsdr.so:comms/rtl-sdr

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	pothosware

PLIST_FILES=	lib/SoapySDR/modules0.8/librtlsdrSupport.so

.include <bsd.port.mk>
