# $FreeBSD$

PORTNAME=	ecto_migrate
PORTVERSION=	0.6.3
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Automatic migrations for Ecto

LICENSE=	APACHE20

BROKEN=		Does not build with latest Ecto
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2017-11-09

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	xerions

MIX_BUILD_DEPS=	databases/elixir-ecto
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

.include <bsd.port.mk>
