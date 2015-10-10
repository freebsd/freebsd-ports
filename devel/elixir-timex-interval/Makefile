# $FreeBSD$

PORTNAME=	timex-interval
PORTVERSION=	0.6.0
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Date/time interval library for Elixir

LICENSE=	APACHE20

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	atabary

ELIXIR_APP_NAME=timex_interval
MIX_BUILD_DEPS=	devel/elixir-timex
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

.include <bsd.port.mk>
