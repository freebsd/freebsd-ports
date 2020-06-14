# $FreeBSD$

PORTNAME=	gh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	devel

MAINTAINER=	vulcan@wired.sh
COMMENT=	GitHub command-line tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	cli
GH_PROJECT=	${GH_ACCOUNT}
GH_TUPLE=	AlecAivazis:survey:v2.0.7:alecaivazis_survey/vendor/github.com/AlecAivazis/survey/v2 \
		MakeNowJust:heredoc:v1.0.0:makenowjust_heredoc/vendor/github.com/MakeNowJust/heredoc \
		alecthomas:chroma:34d9c7143bf5:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		briandowns:spinner:v1.11.1:briandowns_spinner/vendor/github.com/briandowns/spinner \
		charmbracelet:glamour:301d3bcf3058:charmbracelet_glamour/vendor/github.com/charmbracelet/glamour \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man/v2 \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:2ff61e1afc86:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml_1/vendor/gopkg.in/yaml.v2 \
		golang:crypto:06a226fb4e37:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:0ba52f642ac2:golang_net/vendor/golang.org/x/net \
		golang:sys:85ca7c5b95cd:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.4.1:google_go_cmp/vendor/github.com/google/go-cmp \
		google:goterm:fc88cf888a3f:google_goterm/vendor/github.com/google/goterm \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		hashicorp:go-version:v1.2.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		henvic:httpretty:v0.0.5:henvic_httpretty/vendor/github.com/henvic/httpretty \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		microcosm-cc:bluemonday:v1.0.2:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		muesli:reflow:v0.1.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.4.0:muesli_termenv/vendor/github.com/muesli/termenv \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		russross:blackfriday:v2.0.1:russross_blackfriday/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:githubv4:bbc966b061dd:shurcool_githubv4/vendor/github.com/shurcooL/githubv4 \
		shurcooL:graphql:d48a9a75455f:shurcool_graphql/vendor/github.com/shurcooL/graphql \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		spf13:cobra:v1.0.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify \
		yuin:goldmark:v1.1.24:yuin_goldmark/vendor/github.com/yuin/goldmark

_BUILD_DATE=	$$(date +%Y-%m-%d)
_BUILD_VERSION=	${DISTVERSION}

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/command.Version=${_BUILD_VERSION} \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/command.BuildDate=${_BUILD_DATE}"

_DOCS=		README.md docs/gh-vs-hub.md docs/releasing.md \
		docs/command-line-syntax.md docs/source.md
PORTDOCS=	${_DOCS:T}

OPTIONS_DEFINE=		COMPLETIONS DOCS MANPAGES
OPTIONS_DEFAULT=	COMPLETIONS MANPAGES
OPTIONS_SUB=		yes

COMPLETIONS_DESC=	Build and install shell completions for bash, fish and zsh
MANPAGES_DESC=		Build and install auto-generated manpages

do-build-COMPLETIONS-on:
.for SHELL in bash fish zsh
	${GO_WRKDIR_BIN}/${PORTNAME} completion -s ${SHELL} > ${GO_WRKSRC}/${SHELL}
.endfor

do-build-MANPAGES-on:
	cd ${GO_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} run ${GO_BUILDFLAGS} ./cmd/gen-docs --man-page --doc-path docs/man 2>/dev/null

post-install-COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${GO_WRKSRC}/bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${GO_WRKSRC}/fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${GO_WRKSRC}/zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${GO_WRKSRC} && ${INSTALL_DATA} ${_DOCS} ${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${GO_WRKSRC}/docs/man/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
