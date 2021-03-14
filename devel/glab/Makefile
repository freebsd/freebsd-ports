# $FreeBSD$

PORTNAME=	glab
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16.0
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Open-source GitLab command line tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	profclems
GH_TUPLE=	AlecAivazis:survey:v2.2.9:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		MakeNowJust:heredoc:v1.0.0:makenowjust_heredoc/vendor/github.com/MakeNowJust/heredoc \
		acarl005:stripansi:5a71ef0e047d:acarl005_stripansi/vendor/github.com/acarl005/stripansi \
		alecthomas:assert:405dbfeb8e38:alecthomas_assert/vendor/github.com/alecthomas/assert \
		alecthomas:chroma:v0.7.3:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		alecthomas:colour:60882d9e2721:alecthomas_colour/vendor/github.com/alecthomas/colour \
		alecthomas:repr:117648cd9897:alecthomas_repr/vendor/github.com/alecthomas/repr \
		briandowns:spinner:v1.12.0:briandowns_spinner/vendor/github.com/briandowns/spinner \
		charmbracelet:glamour:1246d13c1684:charmbracelet_glamour/vendor/github.com/charmbracelet/glamour \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.2.0:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.1:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:a7d1128ccaa0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:4bcb84eeeb78:golang_sys/vendor/golang.org/x/sys \
		golang:term:2321bbc49cbf:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:goterm:fc88cf888a3f:google_goterm/vendor/github.com/google/goterm \
		google:renameio:v0.1.0:google_renameio/vendor/github.com/google/renameio \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		gosuri:uilive:v0.0.4:gosuri_uilive/vendor/github.com/gosuri/uilive \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-retryablehttp:v0.6.4:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-version:v1.2.1:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jarcoal:httpmock:v1.0.8:jarcoal_httpmock/vendor/github.com/jarcoal/httpmock \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		lunixbochs:vtclean:v1.0.0:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.10:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		microcosm-cc:bluemonday:v1.0.2:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		muesli:reflow:v0.1.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.6.0:muesli_termenv/vendor/github.com/muesli/termenv \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		otiai10:copy:v1.5.0:otiai10_copy/vendor/github.com/otiai10/copy \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:tview:745e4ceeb711:rivo_tview/vendor/github.com/rivo/tview \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		sergi:go-diff:v1.0.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tidwall:pretty:v1.1.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		xanzy:go-gitlab:v0.47.0:xanzy_go_gitlab/vendor/github.com/xanzy/go-gitlab \
		yuin:goldmark:v1.2.0:yuin_goldmark/vendor/github.com/yuin/goldmark

_BUILD_VERSION=	${DISTVERSION}
_BUILD_DATE=	$$(date +%d/%m/%Y)

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.version=${_BUILD_VERSION} \
		-X main.build=${_BUILD_DATE}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

pre-build:
	${LN} -sf ${WRKSRC_muesli_termenv}/termenv_linux.go ${WRKSRC_muesli_termenv}/termenv_freebsd.go

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
