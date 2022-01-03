PORTNAME=	rebar3
PORTVERSION=	3.18.0
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES+=	https://repo.hex.pm/tarballs/:hex
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Build tool for Erlang

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/erl:lang/erlang \
		${LOCALBASE}/bin/git:devel/git
RUN_DEPENDS=	${LOCALBASE}/bin/erl:lang/erlang

OPTIONS_DEFINE=	BASH ZSH EXAMPLES
OPTIONS_DEFAULT=BASH ZSH

USES=		cpe
CPE_VENDOR=	erlang
USE_GITHUB=	yes
GH_ACCOUNT=	erlang

NO_ARCH=	yes
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/rebar3.1.gz
PORTEXAMPLES=	rebar.config.sample

BASH_PLIST_FILES=	share/bash-completion/completions/rebar3
ZSH_PLIST_FILES=	share/zsh/site-functions/_rebar3

# from rebar.config
REBAR_DEPS=	bbmustache-1.12.2 \
		certifi-2.8.0 \
		cf-0.3.1 \
		cth_readable-1.5.1 \
		erlware_commons-1.5.0 \
		eunit_formatters-0.5.0 \
		getopt-1.0.1 \
		providers-1.9.0 \
		relx-4.6.0 \
		ssl_verify_fun-1.1.6

.for _dep in ${REBAR_DEPS}
DISTFILES+=	${_dep}.tar:hex
.endfor

# The '_checkouts' part is to avoid attempts to fetch files from the
# network during the build.
post-extract:
.for _dep in ${REBAR_DEPS}
	${MKDIR} ${WRKSRC}/_build/default/lib/${_dep:C/-.*//}
	${TAR} xOf ${DISTDIR}/${_dep}.tar contents.tar.gz |\
		${TAR} xfz - -C ${WRKSRC}/_build/default/lib/${_dep:C/-.*//}
	${MKDIR} ${WRKSRC}/_checkouts/${_dep:C/-.*//}
	${TAR} xOf ${DISTDIR}/${_dep}.tar contents.tar.gz |\
		${TAR} xfz - -C ${WRKSRC}/_checkouts/${_dep:C/-.*//}
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
	${INSTALL_MAN} ${WRKSRC}/manpages/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

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
