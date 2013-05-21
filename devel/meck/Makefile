# $FreeBSD$

PORTNAME=	meck
PORTVERSION=	0.7.2
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang library for building mock modules

LICENSE=	AL2

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		rebar:${PORTSDIR}/devel/rebar
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	eproxus
GH_PROJECT=	meck
GH_COMMIT=	37715e6
GH_TAGNAME=	${PORTVERSION}

PORTDOCS=	*

.include <bsd.port.options.mk>

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.md ${DOCSDIR}
.endif
	@${MKDIR} ${PREFIX}/lib/erlang/lib/meck-${PORTVERSION}
	@${MKDIR} ${PREFIX}/lib/erlang/lib/meck-${PORTVERSION}/ebin
	@${MKDIR} ${PREFIX}/lib/erlang/lib/meck-${PORTVERSION}/src
	@${INSTALL_DATA} ${WRKSRC}/ebin/* ${PREFIX}/lib/erlang/lib/meck-${PORTVERSION}/ebin
	@${INSTALL_DATA} ${WRKSRC}/src/* ${PREFIX}/lib/erlang/lib/meck-${PORTVERSION}/src

.include <bsd.port.mk>
