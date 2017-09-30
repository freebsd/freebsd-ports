# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	citus
PORTVERSION=	7.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	pg_

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Horizontally scale Postgresql using sharding and replication

LICENSE=	AGPLv3

USES=		gmake pgsql:9.6+ autoreconf readline
WANT_PGSQL=	lib server
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	citusdata

INSTALL_TARGET=	install-strip
MAKE_ARGS=	INSTALL="${INSTALL} -c"

.include <bsd.port.mk>
