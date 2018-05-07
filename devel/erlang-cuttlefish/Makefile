# $FreeBSD$

PORTNAME=	cuttlefish
PORTVERSION=	2.0.11
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Configuration library for Erlang

LICENSE=	APACHE20

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	basho

REBAR_TARGETS=	compile escriptize
ERL_BUILD_DEPS=	devel/erlang-getopt \
		devel/erlang-lager \
		devel/erlang-neotoma
ERL_RUN_DEPS:=	${ERL_BUILD_DEPS}

.include <bsd.port.mk>
