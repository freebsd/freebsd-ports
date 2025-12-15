PORTNAME=	revive
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.0
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Extensible static code analysis framework for Go
WWW=		https://revive.run

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

_BUILD_VERSION=	${DISTVERSION}
_BUILD_COMMIT=	e1d05f7

GO_MODULE=	github.com/mgechev/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X ${GO_MODULE}/cli.version=${_BUILD_VERSION} \
		-X ${GO_MODULE}/cli.commit=${_BUILD_COMMIT}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CODE_OF_CONDUCT.md CONTRIBUTING.md DEVELOPING.md README.md \
		RULES_DESCRIPTIONS.md
PORTEXAMPLES=	defaults.toml untyped.toml

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
