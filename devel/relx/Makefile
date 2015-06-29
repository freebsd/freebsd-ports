# $FreeBSD$

PORTNAME=	relx
PORTVERSION=	3.0.0
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	devel
MASTER_SITES+=	http://olgeni.olgeni.com/~olgeni/distfiles/:deps \
		LOCAL/olgeni:deps
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		relx-cache-2.tar.gz:deps

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Sane, simple release creation for Erlang

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang \
		rebar3>=0:${PORTSDIR}/devel/rebar3 \
		erlang-bbmustache>=0:${PORTSDIR}/devel/erlang-bbmustache \
		erlang-erlware_commons>=0:${PORTSDIR}/devel/erlang-erlware_commons \
		erlang-getopt>=0:${PORTSDIR}/devel/erlang-getopt \
		erlang-providers>=0:${PORTSDIR}/devel/erlang-providers \
		erlang-jsx>=0:${PORTSDIR}/devel/erlang-jsx \
		erlang-rebar3_hex>=0:${PORTSDIR}/devel/erlang-rebar3_hex \
		erlang-ssl_verify_hostname>=0:${PORTSDIR}/devel/erlang-ssl_verify_hostname
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	erlware

# rebar3 insists on downloading dependencies, and some kind of package
# index into the user's HOME. We need to trick it into behaving by
# providing both before building.

post-extract:
	@${LN} -s cache ${WRKDIR}/.cache

pre-build:
	@${MKDIR} ${WRKSRC}/_build/default/lib
	@${MKDIR} ${WRKSRC}/_build/default/plugins
.for lib in bbmustache erlware_commons getopt providers
	@${LN} -s ${PREFIX}/lib/erlang/lib/$(lib)-* ${WRKSRC}/_build/default/lib/$(lib)
.endfor
.for plugin in jsx rebar3_hex ssl_verify_hostname
	@${LN} -s ${PREFIX}/lib/erlang/lib/$(plugin)-* ${WRKSRC}/_build/default/plugins/$(plugin)
.endfor

do-build:
	@${RM} ${WRKSRC}/rebar.lock
	@cd ${WRKSRC} && HOME=${WRKDIR} rebar3 compile
	@${RM} ${WRKSRC}/rebar.lock
	@cd ${WRKSRC} && HOME=${WRKDIR} rebar3 escriptize

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/include
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/_build/default/lib/relx/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	cd ${WRKSRC}/priv && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv
	${INSTALL_SCRIPT} ${WRKSRC}/_build/default/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
