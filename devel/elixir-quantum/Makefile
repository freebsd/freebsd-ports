# $FreeBSD$

PORTNAME=	quantum
PORTVERSION=	2.2.5
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Cron-like job scheduler for Elixir

LICENSE=	APACHE20

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	c-rack
GH_PROJECT=	quantum-elixir

ELIXIR_APP_NAME=quantum
MIX_BUILD_DEPS=	devel/elixir-calendar \
		devel/elixir-crontab \
		devel/elixir-gen_stage \
		devel/elixir-timex \
		devel/elixir-tzdata
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

.include <bsd.port.mk>
