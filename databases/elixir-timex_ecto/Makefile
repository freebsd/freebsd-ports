# $FreeBSD$

PORTNAME=	timex_ecto
PORTVERSION=	3.2.1
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Adapter for using Timex DateTimes with Ecto

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	bitwalker

MIX_BUILD_DEPS=	databases/elixir-ecto \
		devel/elixir-timex
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

.include <bsd.port.mk>
