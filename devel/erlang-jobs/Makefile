# $FreeBSD$

PORTNAME=	jobs
PORTVERSION=	0.5
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Job scheduler and load regulation for Erlang

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	uwiger

ERL_BUILD_DEPS=	devel/erlang-parse_trans
ERL_RUN_DEPS:=	${ERL_BUILD_DEPS}
ERL_DOCS=	doc/*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
