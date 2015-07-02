# $FreeBSD$

PORTNAME=	mariaex
PORTVERSION=	0.3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Database driver for MariaDB and MySQL written in Elixir

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	xerions

MIX_BUILD_DEPS=	devel/elixir-decimal
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include "${PORTSDIR}/lang/elixir/bsd.elixir.mk"
.include <bsd.port.mk>
