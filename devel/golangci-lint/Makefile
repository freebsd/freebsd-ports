PORTNAME=	golangci-lint
DISTVERSIONPREFIX=	v
DISTVERSION=	1.40.1
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Linters Runner for Go

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

_BUILD_VERSION=	${DISTVERSION}
_BUILD_COMMIT=	625445b
_BUILD_DATE=	$$(date -u "+%Y-%m-%dT%H:%M:%SZ")

GO_MODULE=	github.com/${PORTNAME:S/-lint//}/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.version=${_BUILD_VERSION} \
		-X main.commit=${_BUILD_COMMIT} \
		-X main.date=${_BUILD_DATE}"

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME} \
		share/zsh/site_functions/_${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md
PORTEXAMPLES=	.golangci.example.yml

OPTIONS_DEFINE=	DOCS EXAMPLES

post-build:
.for SHELL in bash zsh
	${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_WRKDIR_BIN}/${PORTNAME} completion \
		${SHELL} > ${WRKSRC}/${SHELL}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/zsh/site_functions

	${INSTALL_DATA} ${WRKSRC}/bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site_functions/_${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
