PORTNAME=	SoapyRTLSDR
DISTVERSIONPREFIX=	soapy-rtl-sdr-
DISTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Soapy SDR module for RTLSDR
WWW=		https://github.com/pothosware/SoapyRTLSDR

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libSoapySDR.so:misc/soapysdr \
		librtlsdr.so:comms/rtl-sdr

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	pothosware
USE_LDCONFIG=	yes

PLIST_FILES=	lib/SoapySDR/modules0.9/librtlsdrSupport.so

.include <bsd.port.mk>
