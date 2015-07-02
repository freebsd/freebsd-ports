# $FreeBSD$

PORTNAME=	ecto
PORTVERSION=	0.13.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Database wrapper and language integrated query for Elixir

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	elixir-lang

MIX_BUILD_NAME=	shared
MIX_BUILD_DEPS=	devel/elixir-decimal \
		devel/erlang-poolboy
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include "${.CURDIR}/../../lang/elixir/bsd.elixir.mk"
.include <bsd.port.mk>
