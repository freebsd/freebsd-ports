PORTNAME=	syslog
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Erlang port driver for interacting with syslog

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	enc:devel/erlang-native-compiler

USES=		erlang:rebar3
USE_GITHUB=	yes
GH_ACCOUNT=	Vagabond
GH_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
