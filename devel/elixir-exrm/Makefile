# $FreeBSD$

PORTNAME=	exrm
PORTVERSION=	0.17.2
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Automatically generate releases for Elixir projects

LICENSE=	MIT

BUILD_DEPENDS=	elixir:${PORTSDIR}/lang/elixir \
		elixir-conform>=0:${PORTSDIR}/devel/elixir-conform
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	bitwalker

do-build:
	@${LN} -s ${WRKSRC}/_build/prod/lib/${PORTNAME}/ebin ${WRKSRC}/ebin
	@cd ${WRKSRC} && MIX_ENV=prod mix compile

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/priv
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/ebin
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/lib
	cd ${WRKSRC}/priv && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/priv

.include <bsd.port.mk>
