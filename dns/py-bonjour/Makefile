# $FreeBSD$

PORTNAME=	pybonjour
PORTVERSION=	1.1.1
CATEGORIES=	dns python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Python interface to bonjour

LICENSE=	MIT

BROKEN=		Unfetchable (google code has gone away)
DEPRECATED=	Unfetchable for more than six months (google code has gone away)
EXPIRATION_DATE=	2017-04-30

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_SINGLE=			ZEROCONF
OPTIONS_SINGLE_ZEROCONF=	AVAHI MDNSRESPONDER
OPTIONS_DEFAULT=		MDNSRESPONDER
AVAHI_LIB_DEPENDS=		libdns_sd.so:net/avahi-libdns
MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder

.include <bsd.port.mk>
