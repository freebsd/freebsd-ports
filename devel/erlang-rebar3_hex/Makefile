# $FreeBSD$

PORTNAME=	rebar3_hex
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Rebar3 Hex library

LICENSE=	BSD3CLAUSE

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	hexpm

ERL_BUILD_DEPS=	devel/erlang-jsx
ERL_RUN_DEPS:=	${ERL_BUILD_DEPS}

.include <bsd.port.mk>
