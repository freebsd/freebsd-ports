PORTNAME=	SoapyRedPitaya
DISTVERSIONPREFIX=	soapy-redpitaya-
DISTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SoapySDR Red Pitaya module

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libSoapySDR.so:misc/soapysdr

USES=		cmake compiler:c++11-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	pothosware

PLIST_FILES=	lib/SoapySDR/modules0.8/libRedPitaya.so

.include <bsd.port.mk>
