# Created by: vanilla@
# $FreeBSD$

PORTNAME=	plv8js
PORTVERSION=	1.4.2
CATEGORIES=	databases
MASTER_SITES=	http://api.pgxn.org/dist/plv8/${PORTVERSION}/
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-
DISTNAME=	plv8-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	PL/v8js procedural language for PostgreSQL database

LICENSE=	PostgreSQL

LIB_DEPENDS+=	libv8.so:${PORTSDIR}/lang/v8

WANT_PGSQL_VER=	9.1+
USES=		gmake perl5 zip pgsql:${WANT_PGSQL_VER}
USE_PERL5=	build
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
