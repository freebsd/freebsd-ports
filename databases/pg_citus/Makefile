# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	citus
PORTVERSION=	6.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	pg_

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Horizontally scale Postgresql using sharding and replication

LICENSE=	AGPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	citusdata

USES=		gmake pgsql:9.5+ autoreconf readline
WANT_PGSQL=	lib server
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
MAKE_ARGS=	INSTALL="${INSTALL} -c"

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:textproc/flex
MAKE_ARGS+=	FLEX=${LOCALBASE}/bin/flex
.endif

.include <bsd.port.post.mk>
