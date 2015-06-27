# $FreeBSD$

PORTNAME=	cuttlefish
PORTVERSION=	2.0.3
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Configuration library for Erlang

LICENSE=	APACHE20

BUILD_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		erlang-lager>=2.1.1:${PORTSDIR}/devel/erlang-lager \
		erlang-getopt>=0.8.2:${PORTSDIR}/devel/erlang-getopt \
		erlang-neotoma>=1.7.2:${PORTSDIR}/devel/erlang-neotoma
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	VERSION="${PORTVERSION}"

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	basho

post-patch:
	@${REINPLACE_CMD} -e "s/%%PORTVERSION%%/${PORTVERSION}/" ${WRKSRC}/src/cuttlefish.app.src
	@${REINPLACE_CMD} -e "s@%%LOCALBASE%%@${LOCALBASE}@" ${WRKSRC}/src/cuttlefish_escript.erl
	@${RM} ${WRKSRC}/src/*.bak ${WRKSRC}/src/*.orig

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_SCRIPT} ${WRKSRC}/cuttlefish ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
