# Created by: vanilla@
# $FreeBSD$

PORTNAME=	plv8js
PORTVERSION=	1.4.1
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	postgresql-
DISTNAME=	plv8-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	PL/v8js procedural language for PostgreSQL database

LIB_DEPENDS+=	libv8.so:${PORTSDIR}/lang/v8

USES=		gmake perl5 zip pgsql:9.1+
USE_PERL5=	build
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
