# $FreeBSD$

PORTNAME=	gen_rpc
PORTVERSION=	2.1.0
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Scalable RPC library for Erlang

LICENSE=	APACHE20

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	priestjim

ERL_BUILD_DEPS=	devel/erlang-hut \
		devel/erlang-ssl_verify_fun
ERL_RUN_DEPS:=  ${ERL_BUILD_DEPS}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
