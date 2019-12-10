# $FreeBSD$

PORTNAME=	gen_rpc
PORTVERSION=	2.1.0
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Scalable RPC library for Erlang

LICENSE=	APACHE20

BROKEN=		fails to build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-01-10

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	priestjim

ERL_BUILD_DEPS=	devel/erlang-hut \
		devel/erlang-ssl_verify_fun
ERL_RUN_DEPS:=  ${ERL_BUILD_DEPS}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
