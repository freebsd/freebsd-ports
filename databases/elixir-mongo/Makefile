# $FreeBSD$

PORTNAME=	mongo
PORTVERSION=	0.5.1
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Database driver for MongoDB written in Elixir

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	checkiz
GH_PROJECT=	elixir-${PORTNAME}

MIX_BUILD_DEPS=	devel/elixir-bson
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
