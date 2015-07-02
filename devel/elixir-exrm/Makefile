# $FreeBSD$

PORTNAME=	exrm
PORTVERSION=	0.17.3
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Automatically generate releases for Elixir projects

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	bitwalker

MIX_BUILD_DEPS=	devel/relx \
		devel/elixir-conform
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include "${PORTSDIR}/lang/elixir/bsd.elixir.mk"
.include <bsd.port.mk>
