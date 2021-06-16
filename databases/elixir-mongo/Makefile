PORTNAME=	elixir-mongo
PORTVERSION=	0.5.4
CATEGORIES=	databases

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Database driver for MongoDB written in Elixir

LICENSE=	MIT

DEPRECATED=	Upsupported by upstream
EXPIRATION_DATE=	2021-06-23

BROKEN=		does not build: Compilation error in file lib/mongo.ex

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	checkiz

ELIXIR_APP_NAME=mongo

MIX_BUILD_DEPS=	devel/elixir-bson
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
