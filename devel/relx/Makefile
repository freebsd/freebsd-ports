# $FreeBSD$

PORTNAME=	relx
PORTVERSION=	3.20.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
MASTER_SITES+=	LOCAL/olgeni:deps \
		http://olgeni.olgeni.com/~olgeni/distfiles/:deps \
		https://s3.amazonaws.com/s3.hex.pm/tarballs/:hex
DISTFILES=	relx-cache-12.tar.gz:deps
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		relx-cache-12.tar.gz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Sane, simple release creation for Erlang

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/erl:lang/erlang \
		rebar3>=0:devel/rebar3
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	VERSION="${PORTVERSION}"

# Use either erlware or tsloughter, depending on who actually
# published the package on hex.pm
USE_GITHUB=	yes
GH_ACCOUNT=	erlware

REBAR_DEPS=	bbmustache-1.0.4 \
		cf-0.2.1 \
		erlware_commons-0.21.0 \
		getopt-0.8.2 \
		providers-1.6.0

.for _dep in ${REBAR_DEPS}
DISTFILES+=	${_dep}.tar:hex
.endfor

# rebar3 insists on downloading dependencies, and some kind of package
# index into the user's HOME. We need to trick it into behaving by
# providing both before building.

post-extract:
.for _dep in ${REBAR_DEPS}
	@${MKDIR} ${WRKSRC}/_build/default/lib/${_dep:C/-.*//}
	@${TAR} xOf ${DISTDIR}/${_dep}.tar contents.tar.gz |\
		${TAR} xfz - -C ${WRKSRC}/_build/default/lib/${_dep:C/-.*//}
.endfor

post-patch:
	@${REINPLACE_CMD} -i '' -e 's/{ *vsn,.*}/{vsn, "${PORTVERSION}"}/' \
		${WRKSRC}/src/${PORTNAME}.app.src

do-build:
	@${RM} ${WRKSRC}/rebar.lock
	@cd ${WRKSRC} && HOME=${WRKDIR} rebar3 compile
	@${RM} ${WRKSRC}/rebar.lock
	@cd ${WRKSRC} && HOME=${WRKDIR} rebar3 escriptize

post-build:
	@${LN} -s ${WRKSRC}/_build/dev/lib/${PORTNAME}/ebin ${WRKSRC}

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
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
