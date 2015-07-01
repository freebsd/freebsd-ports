# $FreeBSD$

PORTNAME=	plug
PORTVERSION=	0.13.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Composable modules for Elixir web applications

LICENSE=	APACHE20

BUILD_DEPENDS=	elixir:${PORTSDIR}/lang/elixir
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	elixir-lang

do-build:
	@cd ${WRKSRC} && MIX_ENV=prod mix compile

post-build:
	@${LN} -s ${WRKSRC}/_build/prod/lib/${PORTNAME}/ebin ${WRKSRC}/ebin

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/lib
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/ebin
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/lib

.include <bsd.port.mk>
