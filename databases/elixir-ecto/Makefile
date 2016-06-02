# $FreeBSD$

PORTNAME=	ecto
PORTVERSION=	1.1.8
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Database wrapper and language integrated query for Elixir

LICENSE=	APACHE20

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	elixir-lang

OPTIONS_DEFINE=	POSTGREX MARIAEX
OPTIONS_SUB=	yes
POSTGREX_DESC=	PostgreSQL adapter support
MARIAEX_DESC=	MySQL adapter support

MIX_BUILD_NAME=	shared
MIX_BUILD_DEPS=	devel/elixir-decimal \
		devel/elixir-poison \
		devel/erlang-poolboy

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPOSTGREX}
MIX_BUILD_DEPS+=databases/elixir-postgrex
.endif

.if ${PORT_OPTIONS:MMARIAEX}
MIX_BUILD_DEPS+=databases/elixir-mariaex
.endif

MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

.include <bsd.port.mk>
