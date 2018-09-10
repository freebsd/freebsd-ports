# $FreeBSD$

PORTNAME=	exjsx
PORTVERSION=	4.0.0
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	JSON library for Elixir

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	talentdeficit

MIX_BUILD_DEPS=	devel/erlang-jsx
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
