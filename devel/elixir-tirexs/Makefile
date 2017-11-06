# $FreeBSD$

PORTNAME=	tirexs
PORTVERSION=	0.8.15
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ElasticSearch client library for Elixir

LICENSE=	APACHE20

IGNORE=		does not build with Elixir 1.5

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	Zatvobor

MIX_BUILD_DEPS=	devel/elixir-exjsx
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
