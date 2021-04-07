PORTNAME=	providers
PORTVERSION=	1.7.0
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Erlang providers library used by relx

LICENSE=	LGPL3

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	tsloughter

ERL_BUILD_DEPS=	devel/erlang-getopt
ERL_RUN_DEPS:=	${ERL_BUILD_DEPS}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
