# $FreeBSD$

PORTNAME=	swarm
DISTVERSION=	3.3.1
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Clustering, registration, and distribution for Elixir

LICENSE=	MIT

DEPRECATED=	Depends on broken and expiring devel/elixir-gen_state_machine
EXPIRATION_DATE=	2020-01-10

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	bitwalker

MIX_BUILD_DEPS=	devel/elixir-gen_state_machine \
		devel/elixir-libring \
		devel/elixir-poison
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
