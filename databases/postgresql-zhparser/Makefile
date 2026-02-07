PORTNAME=	zhparser
PORTVERSION=	2.3
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostgreSQL extension for full-text search of Chinese
WWW=		https://github.com/amutu/zhparser

LICENSE=	PostgreSQL

LIB_DEPENDS=	libscws.so:textproc/scws

USES=		gmake pgsql:11+
LLD_UNSAFE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	amutu

WANT_PGSQL=	server

MAKE_ENV=	SCWS_HOME=${PREFIX}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/zhparser.so

.include <bsd.port.mk>
