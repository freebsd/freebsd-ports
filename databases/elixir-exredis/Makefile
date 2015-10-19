# $FreeBSD$

PORTNAME=	exredis
PORTVERSION=	0.2.1
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Redis client for Elixir

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	artemeff

MIX_BUILD_DEPS=	databases/erlang-eredis
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
