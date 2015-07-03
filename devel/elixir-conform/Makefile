# $FreeBSD$

PORTNAME=	conform
PORTVERSION=	0.14.5
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Easy release configuration for Elixir apps

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	bitwalker

MIX_BUILD_DEPS=	devel/erlang-neotoma
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
