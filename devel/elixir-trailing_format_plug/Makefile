# $FreeBSD$

PORTNAME=	trailing_format_plug
PORTVERSION=	0.0.7
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Elixir plug to support rails-like trailing format in APIs

LICENSE=	APACHE20

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	mschae

MIX_BUILD_DEPS=	devel/elixir-plug
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
