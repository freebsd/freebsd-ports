PORTNAME=	goreleaser
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
CATEGORIES=	devel

MAINTAINER=	fuz@fuz.su
COMMENT=	Deliver Go binaries as fast and easily as possible

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules
GO_MODULE=	github.com/goreleaser/goreleaser
GO_BUILDFLAGS=	-ldflags="-X main.version=${DISTVERSION} -X 'main.builtBy=FreeBSD ports'"

# TODO: generate documentation
PLIST_FILES=	bin/goreleaser \
		etc/bash_completion.d/goreleaser \
		share/fish/vendor_completions.d/goreleaser.fish \
		share/zsh/site-functions/_goreleaser

post-install:
	@${ECHO_MSG} '=> installing shell completion files'
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${GO_WRKDIR_BIN}/goreleaser completion bash \
	    >${STAGEDIR}${PREFIX}/etc/bash_completion.d/goreleaser
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${GO_WRKDIR_BIN}/goreleaser completion fish \
	    >${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/goreleaser.fish
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${GO_WRKDIR_BIN}/goreleaser completion zsh \
	    >${STAGEDIR}${PREFIX}/share/zsh/site-functions/_goreleaser

.include <bsd.port.mk>
