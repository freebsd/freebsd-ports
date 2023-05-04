PORTNAME=	gh
DISTVERSIONPREFIX=	v
DISTVERSION=	2.28.0
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	GitHub's official command line tool
WWW=		https://cli.github.com

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	cli
GH_PROJECT=	${GH_ACCOUNT}
GH_TUPLE=	AlecAivazis:survey:v2.3.6:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		MakeNowJust:heredoc:v1.0.0:makenowjust_heredoc/vendor/github.com/MakeNowJust/heredoc \
		alecthomas:chroma:v0.10.0:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		alessio:shellescape:v1.4.1:alessio_shellescape/vendor/github.com/alessio/shellescape \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		briandowns:spinner:v1.18.1:briandowns_spinner/vendor/github.com/briandowns/spinner \
		cenkalti:backoff:v4.2.1:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		charmbracelet:glamour:e70ff2d969da:charmbracelet_glamour/vendor/github.com/charmbracelet/glamour \
		charmbracelet:lipgloss:v0.5.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		cli:browser:v1.1.0:cli_browser/vendor/github.com/cli/browser \
		cli:crypto:6be313f59b03:cli_crypto/vendor/golang.org/x/crypto \
		cli:go-gh:v2.0.0:cli_go_gh_v2/vendor/github.com/cli/go-gh/v2 \
		cli:oauth:v1.0.1:cli_oauth/vendor/github.com/cli/oauth \
		cli:safeexec:v1.0.1:cli_safeexec/vendor/github.com/cli/safeexec \
		cli:shurcooL-graphql:v0.0.3:cli_shurcool_graphql/vendor/github.com/cli/shurcooL-graphql \
		cpuguy83:go-md2man:v2.0.2:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		creack:pty:v1.1.18:creack_pty/vendor/github.com/creack/pty \
		danieljoos:wincred:v1.1.2:danieljoos_wincred/vendor/github.com/danieljoos/wincred \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:v1.4.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		gabriel-vasile:mimetype:v1.4.2:gabriel_vasile_mimetype/vendor/github.com/gabriel-vasile/mimetype \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.5.4:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		godbus:dbus:v5.1.0:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		golang:net:v0.8.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:6242fa91716a:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:v0.1.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.6.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.8.0:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.5.9:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:8632dd797987:google_go_genproto/vendor/google.golang.org/genproto \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.49.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-version:v1.3.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		inconshreveable:mousetrap:v1.0.1:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		itchyny:gojq:v0.12.8:itchyny_gojq/vendor/github.com/itchyny/gojq \
		itchyny:timefmt-go:v0.1.3:itchyny_timefmt_go/vendor/github.com/itchyny/timefmt-go \
		joho:godotenv:v1.5.1:joho_godotenv/vendor/github.com/joho/godotenv \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.18:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.14:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		microcosm-cc:bluemonday:v1.0.20:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mislav:httpretty:d31343e0d884:mislav_httpretty/vendor/github.com/henvic/httpretty \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.12.0:muesli_termenv/vendor/github.com/muesli/termenv \
		muhammadmuzzammil1998:jsonc:615b0916ca38:muhammadmuzzammil1998_jsonc/vendor/github.com/muhammadmuzzammil1998/jsonc \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		opentracing:opentracing-go:v1.1.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:tview:c4a7e501810d:rivo_tview/vendor/github.com/rivo/tview \
		rivo:uniseg:v0.4.2:rivo_uniseg/vendor/github.com/rivo/uniseg \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:githubv4:0b4e3294ff00:shurcool_githubv4/vendor/github.com/shurcooL/githubv4 \
		shurcooL:graphql:3cf50f8a0a29:shurcool_graphql/vendor/github.com/shurcooL/graphql \
		sourcegraph:jsonrpc2:v0.1.0:sourcegraph_jsonrpc2/vendor/github.com/sourcegraph/jsonrpc2 \
		spf13:cobra:v1.6.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:objx:v0.4.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.5:stretchr_testify/vendor/github.com/stretchr/testify \
		thlib:go-timezone-local:ef149e42d28e:thlib_go_timezone_local/vendor/github.com/thlib/go-timezone-local \
		yuin:goldmark-emoji:v1.0.1:yuin_goldmark_emoji/vendor/github.com/yuin/goldmark-emoji \
		yuin:goldmark:v1.4.13:yuin_goldmark/vendor/github.com/yuin/goldmark \
		zalando:go-keyring:v0.2.2:zalando_go_keyring/vendor/github.com/zalando/go-keyring

_BUILD_VERSION=	${DISTVERSION}
_BUILD_DATE=	$$(date +%Y-%m-%d)

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/v2/internal/build.Version=${_BUILD_VERSION} \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/v2/internal/build.Date=${_BUILD_DATE}"

_DOCS=		README.md docs/gh-vs-hub.md docs/releasing.md \
		docs/command-line-syntax.md docs/source.md \
		docs/install_linux.md docs/project-layout.md docs/triage.md
PORTDOCS=	${_DOCS:T}

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

do-build-MANPAGES-on:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} run ${GO_BUILDFLAGS} \
		./cmd/gen-docs --man-page --doc-path docs/man 2>/dev/null)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && \
		${INSTALL_DATA} ${_DOCS} \
		${STAGEDIR}${DOCSDIR})

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/docs/man/*.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
