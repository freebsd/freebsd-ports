# $FreeBSD$

PORTNAME=	rebar3_hex
PORTVERSION=	0.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Rebar3 Hex library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		rebar:${PORTSDIR}/devel/rebar \
		erlang-erlware_commons>=0:${PORTSDIR}/devel/erlang-erlware_commons \
		erlang-ssl_verify_hostname>=0:${PORTSDIR}/devel/erlang-ssl_verify_hostname \
		erlang-jsx>=0:${PORTSDIR}/devel/erlang-jsx \
		erlang-providers>=0:${PORTSDIR}/devel/erlang-providers
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		erlang-erlware_commons>=0:${PORTSDIR}/devel/erlang-erlware_commons \
		erlang-ssl_verify_hostname>=0:${PORTSDIR}/devel/erlang-ssl_verify_hostname \
		erlang-jsx>=0:${PORTSDIR}/devel/erlang-jsx \
		erlang-providers>=0:${PORTSDIR}/devel/erlang-providers

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	hexpm

do-build:
	@cd ${WRKSRC} && rebar compile

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/priv/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src

.include <bsd.port.mk>
