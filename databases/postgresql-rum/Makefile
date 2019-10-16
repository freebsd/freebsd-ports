# $FreeBSD$

PORTNAME=	rum
PORTVERSION=	1.3.6
PORTREVISION=	0
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Inverted index with additional information in posting lists

LICENSE=	PostgreSQL

USES=		gmake pgsql:9.6+

LLD_UNSAFE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	postgrespro

WANT_PGSQL=	server

do-build:
	cd ${WRKSRC} && ${MAKE_CMD} USE_PGXS=1

do-install:
	cd ${WRKSRC} && ${MAKE_CMD} USE_PGXS=1 DESTDIR=${STAGEDIR} install

.include <bsd.port.mk>
