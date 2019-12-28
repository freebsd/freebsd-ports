# $FreeBSD$

PORTNAME=	rebar3
PORTVERSION=	3.13.0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES+=	LOCAL/olgeni:deps \
		http://olgeni.olgeni.com/~olgeni/distfiles/:deps \
		https://repo.hex.pm/tarballs/:hex
DISTFILES=	rebar3-cache-${PORTVERSION}${EXTRACT_SUFX}:deps
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		rebar3-cache-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Build tool for Erlang

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/erl:lang/erlang \
		${LOCALBASE}/bin/git:devel/git
RUN_DEPENDS=	${LOCALBASE}/bin/erl:lang/erlang

OPTIONS_DEFINE=	BASH ZSH EXAMPLES
OPTIONS_DEFAULT=BASH ZSH

USE_GITHUB=	yes
GH_ACCOUNT=	rebar

NO_ARCH=	yes
PLIST_FILES=	bin/${PORTNAME}
PORTEXAMPLES=	rebar.config.sample

BASH_PLIST_FILES=	share/bash-completion/completions/rebar3
ZSH_PLIST_FILES=	share/zsh/site-functions/_rebar3

# from rebar.config
REBAR_DEPS=	bbmustache-1.8.0 \
		certifi-2.5.1 \
		cf-0.2.2 \
		cth_readable-1.4.6 \
		erlware_commons-1.3.1 \
		eunit_formatters-0.5.0 \
		getopt-1.0.1 \
		parse_trans-3.3.0 \
		providers-1.8.1 \
		relx-3.33.0 \
		ssl_verify_fun-1.1.5

.for _dep in ${REBAR_DEPS} ${REBAR_PLUGINS}
DISTFILES+=	${_dep}.tar:hex
.endfor

# convenience target to rebuild the rebar3 cache file
build-cache:
	cd ${WRKDIR} && ${TAR} -c -v -z -f rebar3-cache-${PORTVERSION}${EXTRACT_SUFX} .cache

post-extract:
	@${REINPLACE_CMD} -e 's/{ *vsn,.*}/{vsn, "${PORTVERSION}"}/' ${WRKSRC}/src/*.app.src
.for _dep in ${REBAR_DEPS}
	${MKDIR} ${WRKSRC}/_build/default/lib/${_dep:C/-.*//}
	${TAR} xOf ${DISTDIR}/${_dep}.tar contents.tar.gz |\
		${TAR} xfz - -C ${WRKSRC}/_build/default/lib/${_dep:C/-.*//}
.endfor
.for _dep in ${REBAR_PLUGINS}
	${MKDIR} ${WRKSRC}/_build/default/plugins/${_dep:C/-.*//}
	${TAR} xOf ${DISTDIR}/${_dep}.tar contents.tar.gz |\
		${TAR} xfz - -C ${WRKSRC}/_build/default/plugins/${_dep:C/-.*//}
.endfor
	@${MKDIR} ${WRKSRC}/_build/bootstrap/lib
	@${MKDIR} ${WRKSRC}/_build/bootstrap/plugins
.for _dep in ${REBAR_DEPS}
	${LN} -sf ${WRKSRC}/_build/default/lib/${_dep:C/-.*//} ${WRKSRC}/_build/bootstrap/lib/
.endfor
.for _dep in ${REBAR_PLUGINS}
	${LN} -sf ${WRKSRC}/_build/default/plugins/${_dep:C/-.*//} ${WRKSRC}/_build/bootstrap/plugins/
.endfor

do-build:
	@${RM} ${WRKSRC}/rebar.lock
	@cd ${WRKSRC} && HOME=${WRKDIR} ./bootstrap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

do-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/priv/shell-completion/bash/rebar3 \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/rebar3

do-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/priv/shell-completion/zsh/_rebar3 \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/rebar.config.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
