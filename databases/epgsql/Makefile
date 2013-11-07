# $FreeBSD$

PORTNAME=	epgsql
PORTVERSION=	1.4
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang PostgreSQL Database Client

LICENSE=	BSD

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	wg
GH_PROJECT=	epgsql
GH_COMMIT=	6dd2d26
GH_TAGNAME=	${PORTVERSION}
ALL_TARGET=	app

PORTDOCS=	*

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}/include
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}/src

.include <bsd.port.mk>
