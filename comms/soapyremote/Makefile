PORTNAME=	SoapyRemote
DISTVERSIONPREFIX=	soapy-remote-
DISTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SoapySDR module to use any Soapy SDR remotely

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

LIB_DEPENDS=	libavahi-common.so:net/avahi-app \
		libSoapySDR.so:misc/soapysdr

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	pothosware

PLIST_FILES=	bin/SoapySDRServer \
		lib/SoapySDR/modules0.8/libremoteSupport.so \
		man/man1/SoapySDRServer.1.gz

.include <bsd.port.mk>
