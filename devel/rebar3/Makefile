# $FreeBSD$

PORTNAME=	rebar3
PORTVERSION=	20150630
CATEGORIES=	devel
MASTER_SITES+=	LOCAL/olgeni:pkg \
		http://olgeni.olgeni.com/~olgeni/distfiles/:pkg \
		https://s3.amazonaws.com/s3.hex.pm/tarballs/:hex
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		rebar3-packages-1${EXTRACT_SUFX}:pkg
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Build tool for Erlang

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang \
		${LOCALBASE}/bin/git:${PORTSDIR}/devel/git
RUN_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang

OPTIONS_DEFINE=	BASH ZSH

USE_GITHUB=	yes
GH_ACCOUNT=	rebar
GH_TAGNAME=	4f98106

PLIST_FILES=	bin/${PORTNAME}

BASH_PLIST_FILES=	share/bash-completion/completions/rebar3
ZSH_PLIST_FILES=	share/zsh/site-functions/_rebar3

REBAR_PACKAGES=	${WRKDIR}/.cache/rebar3/hex/com/amazonaws/s3/s3.hex.pm/tarballs/packages

# from rebar.config
REBAR_DEPS=	bbmustache-1.0.1 \
		erlware_commons-0.12.0 \
		getopt-0.8.2 \
		providers-1.4.1 \
		relx-3.0.0

.for _dep in ${REBAR_DEPS}
DISTFILES+=	${_dep}.tar:hex
.endfor

.include <bsd.port.options.mk>

post-extract:
	@${MKDIR} ${REBAR_PACKAGES}
	@${TAR} xfz ${DISTDIR}/rebar3-packages-1${EXTRACT_SUFX} -C ${REBAR_PACKAGES}
.for _dep in ${REBAR_DEPS}
	@${INSTALL_DATA} ${DISTDIR}/${_dep}.tar ${REBAR_PACKAGES}
.endfor
.for _dep in ${REBAR_DEPS}
	@${MKDIR} ${WRKSRC}/_build/default/lib/${_dep:C/-.*//}
	@${TAR} xOf ${DISTDIR}/${_dep}.tar contents.tar.gz |\
		${TAR} xfz - -C ${WRKSRC}/_build/default/lib/${_dep:C/-.*//}
.endfor

do-build:
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

.include <bsd.port.mk>
