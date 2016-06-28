# $FreeBSD$

PORTNAME=	parse_trans
PORTVERSION=	3.0.0
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Parse transform utilities for Erlang

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	uwiger

ERL_DOCS=	doc/*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
