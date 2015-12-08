# $FreeBSD$

PORTNAME=	exrm
PORTVERSION=	1.0.0rc7
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Automatically generate releases for Elixir projects

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	bitwalker
GH_TAGNAME=	1.0.0-rc7

MIX_BUILD_DEPS=	devel/relx
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
