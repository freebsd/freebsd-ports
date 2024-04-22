PORTNAME=	rtl-433
PORTVERSION=	23.11
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Generic RF data receiver and decoder for ISM band devices
WWW=		https://github.com/merbanan/rtl_433

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librtlsdr.so:comms/rtl-sdr \
		libSoapySDR.so:misc/soapysdr

USES=		cmake pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	merbanan
GH_PROJECT=	rtl_433
USE_RC_SUBR=	rtl_433

post-install:
	${INSTALL} ${WRKSRC}/conf/rtl_433.example.conf ${STAGEDIR}${PREFIX}/etc/rtl_433.conf

.include <bsd.port.mk>
