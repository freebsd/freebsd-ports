# $FreeBSD$

PORTNAME=	meck
PORTVERSION=	0.8.2
CATEGORIES=	devel
MASTER_SITES=	GHL

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang library for building mock modules

LICENSE=	APACHE20

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		rebar:${PORTSDIR}/devel/rebar
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	eproxus
GH_PROJECT=	meck
GH_COMMIT=	3599670
GH_TAGNAME=	${PORTVERSION}

PORTDOCS=	*

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/meck-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/meck-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/meck-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/meck-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/meck-${PORTVERSION}/src

.include <bsd.port.mk>
