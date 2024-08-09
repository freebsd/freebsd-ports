PORTNAME=	glab
DISTVERSIONPREFIX=	v
DISTVERSION=	1.38.0
PORTREVISION=	5
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	GitLab CLI tool bringing GitLab to your command line
WWW=		https://gitlab.com/gitlab-org/cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:1.21,modules

_BUILD_VERSION=		${DISTVERSION}
_BUILD_PLATFORM=	${OPSYS:tl}
_BUILD_DATE=		$$(date +%Y-%m-%d)

GO_MODULE=	gitlab.com/gitlab-org/cli
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.buildDate=${_BUILD_DATE} \
		-X main.version=${_BUILD_VERSION} \
		-X main.platform=${_BUILD_PLATFORM}"

PORTDOCS=	CONTRIBUTING.md README.md SECURITY.md

OPTIONS_DEFINE=		COMPLETIONS DOCS MANPAGES
OPTIONS_DEFAULT=	COMPLETIONS MANPAGES
OPTIONS_SUB=		yes

COMPLETIONS_DESC=		Build and install bash, fish and zsh shell completions
COMPLETIONS_PLIST_FILES=	share/bash-completion/completions/${PORTNAME} \
				share/fish/vendor_completions.d/${PORTNAME}.fish \
				share/zsh/site-functions/_${PORTNAME}

post-install-COMPLETIONS-on:
.for _shell in bash fish zsh
	${GO_WRKDIR_BIN}/${PORTNAME} completion -s ${_shell} \
		>${STAGEDIR}${PREFIX}/${COMPLETIONS_PLIST_FILES:M*${_shell}*}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} run \
		./cmd/gen-docs --manpage --path ${STAGEDIR}${PREFIX}/share/man/man1)

.include <bsd.port.mk>
