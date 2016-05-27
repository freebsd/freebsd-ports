# $FreeBSD$

PORTNAME=	calecto
PORTVERSION=	0.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Adapter for the Calendar library in Ecto

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	lau

MIX_BUILD_DEPS= databases/elixir-ecto \
		devel/elixir-calendar
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
