# $FreeBSD$

PORTNAME=	timex
PORTVERSION=	3.1.24
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Complete date/time library for Elixir

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	bitwalker

MIX_BUILD_DEPS= devel/elixir-combine \
		devel/elixir-gettext \
		devel/elixir-tzdata \
		www/elixir-httpoison
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

.include <bsd.port.mk>
