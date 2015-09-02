# $FreeBSD$

PORTNAME=	timex
PORTVERSION=	0.19.3
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Complete date/time library for Elixir

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	bitwalker

MIX_BUILD_DEPS= devel/elixir-combine \
		devel/elixir-tzdata
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
