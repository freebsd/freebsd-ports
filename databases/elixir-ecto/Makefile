# $FreeBSD$

PORTNAME=	ecto
PORTVERSION=	0.13.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Database wrapper and language integrated query for Elixir

LICENSE=	APACHE20

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	elixir-lang

MIX_BUILD_NAME=	shared
MIX_BUILD_DEPS=	devel/elixir-decimal \
		devel/erlang-poolboy
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
