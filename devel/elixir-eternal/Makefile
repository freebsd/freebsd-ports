# $FreeBSD$

PORTNAME=	eternal
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Elixir supervisor for ETS tables

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	whitfin

MIX_BUILD_DEPS=	devel/elixir-deppie
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
