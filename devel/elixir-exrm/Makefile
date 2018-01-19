# $FreeBSD$

PORTNAME=	exrm
DISTVERSION=	1.0.8
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Automatically generate releases for Elixir projects

LICENSE=	MIT

IGNORE=		does not build with Elixir 1.6
DEPRECATED=	No longer maintained upstream
EXPIRATION_DATE=2018-02-18

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	bitwalker

MIX_BUILD_DEPS=	devel/relx
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
