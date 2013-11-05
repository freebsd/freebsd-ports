# $FreeBSD$

PORTNAME=	epgsql
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	GH

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang PostgreSQL Database Client

LICENSE=	BSD

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	wg
GH_PROJECT=	epgsql
GH_COMMIT=	6dd2d26
GH_TAGNAME=	${PORTVERSION}
USE_GMAKE=	yes
ALL_TARGET=	app

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS OPSCODE
OPSCODE_DESC=	Use a fork by opscode for chef
# XXX databases/erl-sqerl requires patched epgsql available at
# https://github.com/opscode/epgsql
OPTIONS_DEFAULT=	OPSCODE

.include <bsd.port.options.mk>

do-patch:
.if ${PORT_OPTIONS:MOPSCODE}
	${PATCH} -p1 -d ${WRKSRC} < files/opscode.patch
	${RM} ${WRKSRC}/src/*.orig
.endif

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${MKDIR} ${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}
	@${MKDIR} ${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}/ebin
	@${MKDIR} ${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}/include
	@${MKDIR} ${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/src/* ${PREFIX}/lib/erlang/lib/epgsql-${PORTVERSION}/src

.include <bsd.port.mk>
