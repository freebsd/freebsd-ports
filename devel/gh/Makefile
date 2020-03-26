# $FreeBSD$

PORTNAME=	gh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
CATEGORIES=	devel

MAINTAINER=	vulcan@wired.sh
COMMENT=	GitHub command-line tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	cli
GH_PROJECT=	cli
GH_TUPLE=	AlecAivazis:survey:v2.0.7:alecaivazis_survey/vendor/github.com/AlecAivazis/survey/v2 \
		alecthomas:chroma:34d9c7143bf5:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		briandowns:spinner:v1.9.0:briandowns_spinner/vendor/github.com/briandowns/spinner \
		charmbracelet:glamour:7e5c90143acc:charmbracelet_glamour/vendor/github.com/charmbracelet/glamour \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man/v2 \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:a6ecf24a6d71:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml_1/vendor/gopkg.in/yaml.v2 \
		golang:crypto:1ad67e1f0ef4:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:46282727080f:golang_net/vendor/golang.org/x/net \
		golang:sys:d5e6a3e2c0ae:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:goterm:fc88cf888a3f:google_goterm/vendor/github.com/google/goterm \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		hashicorp:go-version:v1.2.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		henvic:httpretty:v0.0.4:henvic_httpretty/vendor/github.com/henvic/httpretty \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.8:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		microcosm-cc:bluemonday:v1.0.2:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		muesli:reflow:v0.1.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.4.0:muesli_termenv/vendor/github.com/muesli/termenv \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		russross:blackfriday:v2.0.1:russross_blackfriday/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		spf13:cobra:v0.0.6:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		yuin:goldmark:v1.1.24:yuin_goldmark/vendor/github.com/yuin/goldmark

_BUILD_DATE=	$$(date +%Y-%m-%d)
_BUILD_VERSION=	${DISTVERSION}

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/command.Version=${_BUILD_VERSION} \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/command.BuildDate=${_BUILD_DATE}"

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME}.bash \
		share/fish/completions/${PORTNAME}.fish \
		share/zsh/site_functions/_${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-build:
.for shell in bash fish zsh
	${WRKDIR}/bin/${PORTNAME} completion -s ${shell} > ${WRKSRC}/${shell}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site_functions
	${INSTALL_DATA} ${WRKSRC}/zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site_functions/_${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${GO_WRKSRC} && ${SETENV} ${GO_ENV} ${GO_CMD} test ./...

.include <bsd.port.mk>
