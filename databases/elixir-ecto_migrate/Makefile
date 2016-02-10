# $FreeBSD$

PORTNAME=	ecto_migrate
PORTVERSION=	0.6.3
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Automatic migrations for Ecto

LICENSE=	APACHE20

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	xerions

MIX_BUILD_DEPS=	databases/elixir-ecto
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

.include <bsd.port.mk>
