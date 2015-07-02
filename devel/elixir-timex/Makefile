# $FreeBSD$

PORTNAME=	timex
PORTVERSION=	0.16.0
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Complete date/time library for Elixir

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	bitwalker

MIX_BUILD_DEPS=	devel/elixir-tzdata
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include "${.CURDIR}/../../lang/elixir/bsd.elixir.mk"
.include <bsd.port.mk>
