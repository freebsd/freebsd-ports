# $FreeBSD$

PORTNAME=	gen_rpc
PORTVERSION=	1.0.2
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Scalable RPC library for Erlang

LICENSE=	APACHE20

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	priestjim

ERL_BUILD_DEPS= devel/erlang-lager
ERL_RUN_DEPS:=  ${ERL_BUILD_DEPS}

.include <bsd.port.mk>
