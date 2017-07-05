# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	plpgsql_check
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	amutu@amutu.com
COMMENT=	PostgreSQL extension to check PL/pgSQL code

LICENSE=	UNKNOWN
LICENSE_NAME=	postcardware
LICENSE_TEXT=	If you like it - send a postcard to address: \
			Pavel Stehule \
			Skalice 12 \
			Benesov u Prahy \
			256 01 \
			Czech Republic \
		Use this code freely on own risk
LICENSE_PERMS=	dist-mirror pkg-mirror dist-sell pkg-sell auto-accept

USES=		gmake pgsql:9.2+
USE_GITHUB=	yes
GH_ACCOUNT=	okbob

WANT_PGSQL=	server

.include <bsd.port.mk>
