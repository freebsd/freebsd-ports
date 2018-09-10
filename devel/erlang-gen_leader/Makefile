# $FreeBSD$

PORTNAME=	gen_leader
PORTVERSION=	2014.10.20
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Leader election behavior for Erlang

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	garret-smith
GH_PROJECT=	gen_leader_revival
GH_TAGNAME=	a12a4e3

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
