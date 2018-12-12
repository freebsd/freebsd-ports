# Created by: vanilla@
# $FreeBSD$

PORTNAME=	plv8
PORTVERSION=	1.4.8
PORTREVISION=	4
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-
PKGNAMESUFFIX=	js

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PL/v8js procedural language for PostgreSQL database

LICENSE=	PostgreSQL

LIB_DEPENDS+=	libv8.so:lang/v8

USES=		compiler:c++11-lang gmake perl5 pgsql:9.1+
USE_PERL5=	build
USE_GITHUB=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
