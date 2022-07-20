PORTNAME=	rtl-433
PORTVERSION=	21.12
CATEGORIES=	comms hamradio

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Generic RF data receiver and decoder for ISM band devices

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librtlsdr.so:comms/rtl-sdr

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	merbanan
GH_PROJECT=	rtl_433

.include <bsd.port.mk>
