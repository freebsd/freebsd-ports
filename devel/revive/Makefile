# $FreeBSD$

PORTNAME=	revive
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
CATEGORIES=	devel

MAINTAINER=	vulcan@wired.sh
COMMENT=	Extensible static code analysis framework for Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	mgechev
GH_TUPLE=	BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structtag:v1.2.0:fatih_structtag/vendor/github.com/fatih/structtag \
		golang:sys:33540a1f6037:golang_sys/vendor/golang.org/x/sys \
		golang:tools:807dcd883420:golang_tools/vendor/golang.org/x/tools \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.11:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mgechev:dots:c36f7dcfbb81:mgechev_dots/vendor/github.com/mgechev/dots \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CODE_OF_CONDUCT.md CONTRIBUTING.md DEVELOPING.md \
		PULL_REQUEST_TEMPLATE.md README.md RULES_DESCRIPTIONS.md
PORTEXAMPLES=	defaults.toml untyped.toml

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

do-test:
	@cd ${GO_WRKSRC} && ${SETENV} ${GO_ENV} ${GO_CMD} test ./...

.include <bsd.port.mk>
