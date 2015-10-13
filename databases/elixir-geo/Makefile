# $FreeBSD$

PORTNAME=	geo
PORTVERSION=	0.17.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Collection of GIS functions for Elixir

LICENSE=	MIT

OPTIONS_SUB=	yes
USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	bryanjos

MIX_BUILD_DEPS=	databases/elixir-ecto \
		databases/elixir-postgrex \
		devel/elixir-poison

MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

.include <bsd.port.mk>
