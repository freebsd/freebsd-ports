# $FreeBSD$

PORTNAME=	goldrush
PORTVERSION=	0.1.9
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Fast event stream processing library for Erlang

LICENSE=	ISCL

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	DeadZen

post-build:
	@${RM} -r ${WRKSRC}/priv

.include <bsd.port.mk>
