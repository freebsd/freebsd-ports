# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rebar
PORTVERSION=	2.6.1
CATEGORIES=	devel

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Build-tool for Erlang that follows OTP principles

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/escript:lang/erlang
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	BASH ZSH

USE_GITHUB=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTEXAMPLES=	rebar.config.sample

BASH_PLIST_FILES=	share/bash-completion/completions/rebar
ZSH_PLIST_FILES=	share/zsh/site-functions/_rebar

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MBASH}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/priv/shell-completion/bash/rebar \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/rebar
.endif
.if ${PORT_OPTIONS:MZSH}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/priv/shell-completion/zsh/_rebar \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/rebar.config.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
