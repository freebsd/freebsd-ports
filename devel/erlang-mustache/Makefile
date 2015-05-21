# $FreeBSD$

PORTNAME=	mustache
PORTVERSION=	0.3.2
DISTVERSIONPREFIX=v
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Mustache template engine for Erlang

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	soranoba

ALL_TARGET=	compile

.include <bsd.port.options.mk>

post-extract:
	@${RM} ${WRKSRC}/rebar.lock

post-patch:
	@${REINPLACE_CMD} -e "s/%%PORTVERSION%%/${PORTVERSION}/" ${WRKSRC}/src/mustache.app.src
	@${RM} ${WRKSRC}/src/*.bak ${WRKSRC}/src/*.orig

post-build:
	${LN} -s ${WRKSRC}/_build/default/lib/mustache/ebin ${WRKSRC}

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src

.include <bsd.port.mk>
