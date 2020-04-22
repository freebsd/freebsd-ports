# $FreeBSD$

PORTNAME=	simdjson
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	olevole@olevole.ru
COMMENT=	Parsing gigabytes of JSON per second

LICENSE=	APACHE20

BROKEN_i386=	does not build (error: unknown type name '__uint128_t')

USES=		cmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes

.include <bsd.port.mk>
