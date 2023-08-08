PORTNAME=	recon
DISTVERSION=	2.5.3
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Collection of functions and scripts to debug Erlang in production
WWW=		https://ferd.github.io/recon/

LICENSE=	BSD3CLAUSE

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	ferd

ERL_DOCS=	README.md doc/*
REBAR_TARGETS=	compile doc

OPTIONS_DEFINE=	DOCS

post-build:
	@${RM} ${WRKSRC}/doc/packages-frame.html

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/script
	${INSTALL_DATA} ${WRKSRC}/script/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/script

.include <bsd.port.mk>
