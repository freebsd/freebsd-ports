# $FreeBSD$

PORTNAME=	exjsx
PORTVERSION=	3.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	JSON library for Elixir

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	talentdeficit

MIX_BUILD_DEPS=	devel/erlang-jsx
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include "${.CURDIR}/../../lang/elixir/bsd.elixir.mk"
.include <bsd.port.mk>
