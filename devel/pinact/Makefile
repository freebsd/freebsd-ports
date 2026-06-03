PORTNAME=	pinact
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	CLI to pin GitHub Actions and Reusable Workflows
WWW=		https://github.com/suzuki-shunsuke/pinact

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules

GO_MODULE=	github.com/suzuki-shunsuke/${PORTNAME}/v4
GO_TARGET=	./cmd/pinact
GO_LDFLAGS=	-w -X main.version=${DISTVERSION}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CONTRIBUTING.md README.md USAGE.md

OPTIONS_DEFINE=	COMPLETIONS DOCS
OPTIONS_DEFAULT=COMPLETIONS

COMPLETIONS_DESC=	Build and/or install shell completions

COMPLETIONS_PLIST_FILES=etc/bash_completion.d/${PORTNAME} \
			share/fish/completions/${PORTNAME}.fish \
			share/zsh/site-functions/_${PORTNAME}

pre-build:
	@${CP} ${GO_WRKSRC}/vendor/github.com/suzuki-shunsuke/ghtkn-go-sdk/ghtkn/internal/browser/browser_linux.go \
		${GO_WRKSRC}/vendor/github.com/suzuki-shunsuke/ghtkn-go-sdk/ghtkn/internal/browser/browser_freebsd.go

post-build-COMPLETIONS-on:
.for shell in bash fish zsh
	${GO_WRKDIR_BIN}/pinact completion ${shell} > \
		${GO_WRKSRC}/${PORTNAME}.${shell}
.endfor

post-install-COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${GO_WRKSRC}/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
