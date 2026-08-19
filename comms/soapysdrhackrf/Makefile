PORTNAME=	SoapyHackRF
DISTVERSIONPREFIX=	soapy-hackrf-
DISTVERSION=	0.3.4
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Soapy SDR module for Hack RF
WWW=		https://github.com/pothosware/SoapyHackRF

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhackrf.so:comms/hackrf \
		libSoapySDR.so:misc/soapysdr

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	pothosware
USE_LDCONFIG=	yes

PLIST_FILES=	lib/SoapySDR/modules0.8/libHackRFSupport.so

.include <bsd.port.mk>
