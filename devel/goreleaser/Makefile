PORTNAME=	goreleaser
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Deliver Go binaries as fast and easily as possible
WWW=		https://goreleaser.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:1.24,modules
GO_MODULE=	github.com/goreleaser/goreleaser/v2
GO_TARGET=	.:goreleaser
GO_BUILDFLAGS=	-ldflags="-X main.version=${PKGVERSION} -X 'main.builtBy=FreeBSD ports' ${STRIP}"

# TODO: generate documentation
PLIST_FILES=	bin/goreleaser \
		etc/bash_completion.d/goreleaser \
		share/fish/vendor_completions.d/goreleaser.fish \
		share/man/man1/goreleaser.1.gz \
		share/zsh/site-functions/_goreleaser

post-install:
	@${ECHO_MSG} '====> Installing man page'
	${GO_WRKDIR_BIN}/goreleaser man >${WRKDIR}/goreleaser.1
	${INSTALL_MAN} ${WRKDIR}/goreleaser.1 ${STAGEDIR}${PREFIX}/share/man/man1/goreleaser.1
	@${ECHO_MSG} '====> Installing shell completion files'
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
