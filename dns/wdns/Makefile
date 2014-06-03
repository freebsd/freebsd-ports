# $FreeBSD$

PORTNAME=	wdns
PORTVERSION=	0.5
CATEGORIES=	dns
MASTER_SITES=	https://dl.farsightsecurity.com/dist/wdns/

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Low-level DNS library

LICENSE=	APACHE20

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libwdns.so.0.0.0

.include <bsd.port.mk>
