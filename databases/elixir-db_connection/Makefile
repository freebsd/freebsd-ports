# $FreeBSD$

PORTNAME=	db_connection
DISTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Database connection behaviour for Elixir

LICENSE=	APACHE20

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	elixir-ecto

MIX_BUILD_NAME=	shared
MIX_BUILD_DEPS=	devel/elixir-connection \
		devel/erlang-backoff
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

.include <bsd.port.mk>
