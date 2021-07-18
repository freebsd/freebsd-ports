# Created by: Jov <amutu@amutu.com>

PORTNAME=	plpgsql_check
PORTVERSION=	1.17.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER_NODOT}-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PostgreSQL extension to check PL/pgSQL code

LICENSE=	UNKNOWN
LICENSE_NAME=	postcardware
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

USES=		compiler:c11 gmake pgsql:10+

LLD_UNSAFE=	yes
MAKE_ARGS=	CC="${CC}"
WANT_PGSQL=	server

PLIST_SUB=	PORTVERSION=${PORTVERSION:R}

USE_GITHUB=	yes
GH_ACCOUNT=	okbob

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/plpgsql_check.so

.include <bsd.port.mk>
