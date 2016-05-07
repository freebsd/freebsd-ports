# $FreeBSD$

PORTNAME=	recon
PORTVERSION=	2.3.1
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Collection of functions and scripts to debug Erlang in production

LICENSE=	BSD3CLAUSE

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	ferd

ERL_DOCS=	README.md doc/*
REBAR_TARGETS=	compile doc

post-build:
	@${RM} ${WRKSRC}/doc/packages-frame.html

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/script
	${INSTALL_DATA} ${WRKSRC}/script/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/script

.include <bsd.port.mk>
