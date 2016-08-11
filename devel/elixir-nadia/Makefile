# $FreeBSD$

PORTNAME=	nadia
PORTVERSION=	0.4.0
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Telegram Bot API Wrapper written in Elixir

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	zhyu
GH_TAGNAME=	f91ed3f

MIX_BUILD_DEPS=	devel/elixir-poison \
		www/elixir-httpoison
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

.include <bsd.port.mk>
