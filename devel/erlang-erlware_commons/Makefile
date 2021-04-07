PORTNAME=	erlware_commons
PORTVERSION=	1.1.0
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Erlang project focused on all aspects of reusable components

LICENSE=	MIT

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	erlware

ERL_BUILD_DEPS= devel/erlang-cf
ERL_RUN_DEPS:=  ${ERL_BUILD_DEPS}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
