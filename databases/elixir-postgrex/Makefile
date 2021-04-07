PORTNAME=	postgrex
PORTVERSION=	0.13.5
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Database driver for PostgreSQL written in Elixir

LICENSE=	APACHE20

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	elixir-ecto

MIX_BUILD_DEPS=	databases/elixir-db_connection \
		devel/elixir-connection \
		devel/elixir-decimal
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
