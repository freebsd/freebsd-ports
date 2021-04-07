PORTNAME=	geo
PORTVERSION=	2.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Collection of GIS functions for Elixir

LICENSE=	MIT

OPTIONS_SUB=	yes
USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	bryanjos

MIX_BUILD_DEPS=	databases/elixir-ecto \
		databases/elixir-postgrex \
		devel/elixir-poison

MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
