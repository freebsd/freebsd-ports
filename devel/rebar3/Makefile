# $FreeBSD$

PORTNAME=	rebar3
PORTVERSION=	20150601
CATEGORIES=	devel
MASTER_SITES+=	http://olgeni.olgeni.com/~olgeni/distfiles/:deps \
		LOCAL/olgeni:deps
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} rebar3-deps-2.tar.gz:deps

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Build tool for Erlang

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang \
		${LOCALBASE}/bin/git:${PORTSDIR}/devel/git
RUN_DEPENDS=	${LOCALBASE}/bin/erl:${PORTSDIR}/lang/erlang

OPTIONS_DEFINE=	BASH ZSH

USE_GITHUB=	yes
GH_ACCOUNT=	rebar
GH_TAGNAME=	e09be18

PLIST_FILES=	bin/${PORTNAME}

BASH_PLIST_FILES=	share/bash-completion/completions/rebar3
ZSH_PLIST_FILES=	share/zsh/site-functions/_rebar3

.include <bsd.port.options.mk>

post-extract:
	@${CP} -R ${WRKDIR}/_build ${WRKSRC}/

do-build:
	@${RM} ${WRKSRC}/rebar.lock
	@cd ${WRKSRC} && ./bootstrap

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
