# $FreeBSD$

PORTNAME=	folsom
PORTVERSION=	0.8.2
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang based metrics system inspired by Coda Hale's metrics

LICENSE=	APACHE20

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	boundary

ERL_BUILD_DEPS=	devel/erlang-bear
ERL_RUN_DEPS:=	${ERL_BUILD_DEPS}

.include <bsd.port.mk>
