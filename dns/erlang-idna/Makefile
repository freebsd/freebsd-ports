PORTNAME=	idna
PORTVERSION=	5.1.2
CATEGORIES=	dns
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	IDNA implementation in pure Erlang

LICENSE=	MIT

USES=		erlang:rebar3
USE_GITHUB=	yes
GH_ACCOUNT=	benoitc
GH_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}

ERL_BUILD_DEPS=	devel/erlang-unicode_util_compat
ERL_RUN_DEPS:=	${ERL_BUILD_DEPS}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
