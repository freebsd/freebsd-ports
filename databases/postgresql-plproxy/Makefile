# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	plproxy
DISTVERSIONPREFIX=	plproxy_
DISTVERSION=	2_9
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PL/Proxy - Function-based sharding for PostgreSQL

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		bison gmake pgsql

LLD_UNSAFE=	yes

USE_GITHUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/plproxy.so

.include <bsd.port.mk>
