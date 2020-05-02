# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	plpgsql_check
PORTVERSION=	1.9.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER_NODOT}-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PostgreSQL extension to check PL/pgSQL code

LICENSE=	UNKNOWN
LICENSE_NAME=	postcardware
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror dist-sell pkg-sell auto-accept

USES=		gmake pgsql

LLD_UNSAFE=	yes
WANT_PGSQL=	server

PLIST_SUB=	PORTVERSION=${PORTVERSION:R}

USE_GITHUB=	yes
GH_ACCOUNT=	okbob

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/plpgsql_check.so

.include <bsd.port.mk>
