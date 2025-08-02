PORTNAME=	rebar3
PORTVERSION=	3.25.1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES+=	https://repo.hex.pm/tarballs/:hex
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Build tool for Erlang
WWW=		https://www.rebar3.org/

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/erl:lang/erlang \
		${LOCALBASE}/bin/git:devel/git
RUN_DEPENDS=	${LOCALBASE}/bin/erl:lang/erlang

USES=		cpe
CPE_VENDOR=	erlang
USE_GITHUB=	yes
GH_ACCOUNT=	erlang

NO_ARCH=	yes
PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/rebar3.1.gz
PORTEXAMPLES=	rebar.config.sample

OPTIONS_DEFINE=		BASH EXAMPLES ZSH
OPTIONS_DEFAULT=	BASH ZSH

BASH_PLIST_FILES=	share/bash-completion/completions/rebar3
ZSH_PLIST_FILES=	share/zsh/site-functions/_rebar3

do-build:
	@cd ${WRKSRC} && HOME=${WRKDIR} ./bootstrap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/manpages/*.1 ${STAGEDIR}${PREFIX}/share/man/man1/

do-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/apps/rebar/priv/shell-completion/bash/rebar3 \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/rebar3

do-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/apps/rebar/priv/shell-completion/zsh/_rebar3 \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/rebar.config.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
