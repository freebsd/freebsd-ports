# $FreeBSD$

PORTNAME=	rebar3
PORTVERSION=	20150830
CATEGORIES=	devel
MASTER_SITES+=	LOCAL/olgeni:deps \
		http://olgeni.olgeni.com/~olgeni/distfiles/:deps \
		https://s3.amazonaws.com/s3.hex.pm/tarballs/:hex
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		rebar3-cache-1${EXTRACT_SUFX}:deps
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		rebar3-cache-1${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Build tool for Erlang

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang \
		${LOCALBASE}/bin/git:${PORTSDIR}/devel/git
RUN_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang

OPTIONS_DEFINE=	BASH ZSH

USE_GITHUB=	yes
GH_ACCOUNT=	rebar
GH_TAGNAME=	bfd40d5

PLIST_FILES=	bin/${PORTNAME}
PORTEXAMPLES=	rebar.config.sample

BASH_PLIST_FILES=	share/bash-completion/completions/rebar3
ZSH_PLIST_FILES=	share/zsh/site-functions/_rebar3

# from rebar.config
REBAR_DEPS=	bbmustache-1.0.4 \
		erlware_commons-0.15.0 \
		getopt-0.8.2 \
		providers-1.4.1 \
		relx-3.5.0 \
		ssl_verify_hostname-1.0.5

.for _dep in ${REBAR_DEPS}
DISTFILES+=	${_dep}.tar:hex
.endfor

.include <bsd.port.options.mk>

post-extract:
	@${LN} -s cache ${WRKDIR}/.cache
.for _dep in ${REBAR_DEPS}
	@${MKDIR} ${WRKSRC}/_build/default/lib/${_dep:C/-.*//}
	@${TAR} xOf ${DISTDIR}/${_dep}.tar contents.tar.gz |\
		${TAR} xfz - -C ${WRKSRC}/_build/default/lib/${_dep:C/-.*//}
.endfor

do-build:
	@${RM} ${WRKSRC}/rebar.lock
	@cd ${WRKSRC} && HOME=${WRKDIR} ./bootstrap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MBASH}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/priv/shell-completion/bash/rebar3 \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/rebar3
.endif
.if ${PORT_OPTIONS:MZSH}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/priv/shell-completion/zsh/_rebar3 \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/rebar.config.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
