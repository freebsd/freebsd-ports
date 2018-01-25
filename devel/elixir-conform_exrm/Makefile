# $FreeBSD$

PORTNAME=	conform_exrm
PORTVERSION=	1.0.0
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Conform plugin for ExRM

LICENSE=	MIT

IGNORE=		does not build with Elixir 1.6
DEPRECATED=	No longer maintained upstream
EXPIRATION_DATE=2018-02-18

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	bitwalker

MIX_BUILD_DEPS=	devel/elixir-conform \
		devel/elixir-exrm
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
