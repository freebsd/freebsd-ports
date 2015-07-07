# $FreeBSD$

PORTNAME=	exjsx
PORTVERSION=	3.2.0
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	JSON library for Elixir

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	talentdeficit

MIX_BUILD_DEPS=	devel/erlang-jsx
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
