PORTNAME=	plpgsql_check
PORTVERSION=	2.8.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER_NODOT}-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PostgreSQL extension to check PL/pgSQL code
WWW=		https://github.com/okbob/plpgsql_check

LICENSE=	UNKNOWN
LICENSE_NAME=	postcardware
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

USES=		compiler:c11 gmake pgsql

LLD_UNSAFE=	yes
MAKE_ARGS=	CC="${CC}"
WANT_PGSQL=	server

PLIST_SUB=	PORTVERSION=${PORTVERSION:R}

USE_GITHUB=	yes
GH_ACCOUNT=	okbob

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/plpgsql_check.so

.include <bsd.port.mk>
