# $FreeBSD$

PORTNAME=	mariaex
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Database driver for MariaDB and MySQL written in Elixir

LICENSE=	APACHE20

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	xerions

MIX_BUILD_DEPS=	devel/elixir-decimal
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

.include <bsd.port.mk>
