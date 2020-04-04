# $FreeBSD$

PORTNAME=	exredis
PORTVERSION=	0.2.5
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Redis client for Elixir

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	artemeff

MIX_BUILD_DEPS=	databases/erlang-eredis
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
