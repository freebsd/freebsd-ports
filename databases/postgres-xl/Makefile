# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	postgres-xl
DISTVERSION=	9.5r1.5
CATEGORIES=	databases
MASTER_SITES=	http://files.postgres-xl.org/

MAINTAINER=	amutu@amutu.com
COMMENT=	Scalable open source PostgreSQL-based database cluster

LICENSE=	PostgreSQL

BUILD_DEPENDS=	bash:shells/bash

CONFLICTS=	postgresql[^${PORTVERSION:R:R}]?-client* \
		postgresql${COMPONENT}-[^${PORTVERSION:R:R}].* \
		postgresql9[^${PORTVERSION:R:E}]-client* \
		postgresql${COMPONENT}-9.[^${PORTVERSION:R:E}].*

USES=		gmake readline
USE_LDCONFIG=	yes
LLD_UNSAFE=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-world

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so \
		${STAGEDIR}${PREFIX}/bin/* \
		${STAGEDIR}${PREFIX}/lib/postgresql/*.so \
		${STAGEDIR}${PREFIX}/lib/postgresql/pgxs/src/test/regress/*

.include <bsd.port.mk>
