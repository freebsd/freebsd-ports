PORTNAME=	ticker
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.5
PORTREVISION=	4
CATEGORIES=	finance

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Terminal stock ticker with live updates and position tracking
WWW=		https://github.com/achannarasappa/ticker

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
GH_ACCOUNT=	achannarasappa

GO_BUILDFLAGS=	-ldflags="-X github.com/achannarasappa/ticker/v4/cmd.Version=${DISTVERSIONPREFIX}${PKGVERSION}"
GO_MODULE=	github.com/achannarasappa/ticker/v5

PLIST_FILES=	bin/ticker \
		etc/bash_completion.d/ticker \
		share/fish/vendor_completions.d/ticker.fish \
		share/zsh/site_functions/_ticker
PORTDOCS=	README.md \
		docs/debug-guide.md \
		docs/ticker-all-options.png \
		docs/ticker-currency.png \
		docs/ticker.gif
OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${ECHO_MSG} "====> Installing documentation"
.for doc in ${PORTDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${doc:H}
	${INSTALL_MAN} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}/${doc:H}/
.endfor

post-install:
	@${ECHO_MSG} "====> Installing shell completion files"
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${GO_WRKDIR_BIN}/ticker completion bash \
	    >${STAGEDIR}${PREFIX}/etc/bash_completion.d/ticker
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${GO_WRKDIR_BIN}/ticker completion fish \
	    >${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/ticker.fish
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site_functions
	${GO_WRKDIR_BIN}/ticker completion zsh \
	    >${STAGEDIR}${PREFIX}/share/zsh/site_functions/_ticker

.include <bsd.port.mk>
