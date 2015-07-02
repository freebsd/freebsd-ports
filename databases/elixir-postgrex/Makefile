# $FreeBSD$

PORTNAME=	postgrex
PORTVERSION=	0.8.4
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Database driver for PostgreSQL written in Elixir

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	ericmj

MIX_BUILD_NAME=	shared
MIX_BUILD_DEPS=	devel/elixir-decimal
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include "${PORTSDIR}/lang/elixir/bsd.elixir.mk"
.include <bsd.port.mk>
