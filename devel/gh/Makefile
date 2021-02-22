# $FreeBSD$

PORTNAME=	gh
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	GitHub's official command line tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	cli
GH_PROJECT=	${GH_ACCOUNT}
GH_TUPLE=	AlecAivazis:survey:v2.2.7:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		MakeNowJust:heredoc:v1.0.0:makenowjust_heredoc/vendor/github.com/MakeNowJust/heredoc \
		alecthomas:chroma:v0.7.3:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		briandowns:spinner:v1.11.1:briandowns_spinner/vendor/github.com/briandowns/spinner \
		charmbracelet:glamour:1246d13c1684:charmbracelet_glamour/vendor/github.com/charmbracelet/glamour \
		cli:browser:v1.0.0:cli_browser/vendor/github.com/cli/browser \
		cli:oauth:v0.8.0:cli_oauth/vendor/github.com/cli/oauth \
		cli:safeexec:v1.0.0:cli_safeexec/vendor/github.com/cli/safeexec \
		cli:shurcooL-graphql:0f7232a2bf7e:cli_shurcool_graphql/vendor/github.com/shurcooL/graphql \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		enescakir:emoji:v1.0.0:enescakir_emoji/vendor/github.com/enescakir/emoji \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:9e8e0b390897:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:ab3426394381:golang_net/vendor/golang.org/x/net \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:669c56c373c4:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		hashicorp:go-version:v1.2.1:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		henvic:httpretty:v0.0.6:henvic_httpretty/vendor/github.com/henvic/httpretty \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		microcosm-cc:bluemonday:v1.0.2:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		muesli:reflow:v0.1.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.7.4:muesli_termenv/vendor/github.com/muesli/termenv \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.1.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:githubv4:d292edc3691b:shurcool_githubv4/vendor/github.com/shurcooL/githubv4 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		spf13:cobra:v1.1.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		yuin:goldmark:v1.2.0:yuin_goldmark/vendor/github.com/yuin/goldmark

_BUILD_VERSION=	${DISTVERSION}
_BUILD_DATE=	$$(date +%Y-%m-%d)

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/internal/build.Version=${_BUILD_VERSION} \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/internal/build.Date=${_BUILD_DATE}"

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
