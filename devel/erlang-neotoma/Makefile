# $FreeBSD$

PORTNAME=	neotoma
PORTVERSION=	1.7.2
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang library and packrat parser-generator

LICENSE=	MIT

BUILD_DEPENDS=	erl:${PORTSDIR}/lang/erlang
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_FILES+=	neotoma
SUB_LIST+=	PORTNAME=${PORTNAME} \
		PORTVERSION=${PORTVERSION}

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	seancribbs

post-patch:
	@${REINPLACE_CMD} -e "s/%%PORTVERSION%%/${PORTVERSION}/" ${WRKSRC}/src/neotoma.app.src
	@${RM} ${WRKSRC}/src/*.bak ${WRKSRC}/src/*.orig

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.textile ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/priv/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_SCRIPT} ${WRKSRC}/neotoma ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}
	${INSTALL_SCRIPT} ${WRKDIR}/neotoma ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
