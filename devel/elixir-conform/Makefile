# $FreeBSD$

PORTNAME=	conform
PORTVERSION=	0.14.4
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Easy release configuration for Elixir apps

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	elixir:${PORTSDIR}/lang/elixir \
		erlang-neotoma>=0:${PORTSDIR}/devel/erlang-neotoma
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	VERSION="${PORTVERSION}"

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	bitwalker

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
