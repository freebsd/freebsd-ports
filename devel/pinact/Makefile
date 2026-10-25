PORTNAME=	pinact
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.2
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	CLI to pin GitHub Actions and Reusable Workflows
WWW=		https://github.com/suzuki-shunsuke/pinact

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/suzuki-shunsuke/${PORTNAME}/v5
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

post-configure:
	@${CP} ${GO_WRKSRC}/vendor/github.com/suzuki-shunsuke/ghtkn-go-sdk/ghtkn/browser/browser_linux.go \
		${GO_WRKSRC}/vendor/github.com/suzuki-shunsuke/ghtkn-go-sdk/ghtkn/browser/browser_freebsd.go

post-build-COMPLETIONS-on:
.for shell in bash fish zsh
	${GO_WRKDIR_BIN}/pinact completion ${shell} > \
		${GO_WRKSRC}/${PORTNAME}.${shell}
.endfor

post-install-COMPLETIONS-on:
	@${MKDIR} ${COMPLETIONS_PLIST_FILES:H:S|^|${STAGEDIR}${PREFIX}/|}
.for shell in bash fish zsh
	${INSTALL_DATA} ${GO_WRKSRC}/${PORTNAME}.${shell} \
		${COMPLETIONS_PLIST_FILES:M*${shell}*:S|^|${STAGEDIR}${PREFIX}/|}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
