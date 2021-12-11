PORTNAME=	soft-serve
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
CATEGORIES=	devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Self-hosted Git server for the command line

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	charmbracelet
GH_TUPLE=	Microsoft:go-winio:v0.4.16:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:04723f9f07d7:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		acomagu:bufpipe:v1.0.3:acomagu_bufpipe/vendor/github.com/acomagu/bufpipe \
		alecthomas:chroma:v0.8.2:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		anmitsu:go-shlex:38f4b401e2be:anmitsu_go_shlex/vendor/github.com/anmitsu/go-shlex \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		charmbracelet:bubbles:v0.9.0:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v0.19.1:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:glamour:v0.3.0:charmbracelet_glamour/vendor/github.com/charmbracelet/glamour \
		charmbracelet:keygen:v0.1.2:charmbracelet_keygen/vendor/github.com/charmbracelet/keygen \
		charmbracelet:lipgloss:v0.4.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:wish:v0.1.1:charmbracelet_wish/vendor/github.com/charmbracelet/wish \
		containerd:console:v1.0.2:containerd_console/vendor/github.com/containerd/console \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		emirpasic:gods:v1.12.0:emirpasic_gods/vendor/github.com/emirpasic/gods \
		gliderlabs:ssh:v0.3.3:gliderlabs_ssh/vendor/github.com/gliderlabs/ssh \
		go-git:gcfg:v1.5.0:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.3.1:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.4.2:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:32db794688a5:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:0fccb6fa2b5c:golang_net/vendor/golang.org/x/net \
		golang:sys:0f9fa26af87c:golang_sys/vendor/golang.org/x/sys \
		golang:term:f5beecf764ed:golang_term/vendor/golang.org/x/term \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		kevinburke:ssh_config:4977a11b4351:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-isatty:504425e14f74:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		meowgorithm:babyenv:v1.3.1:meowgorithm_babyenv/vendor/github.com/meowgorithm/babyenv \
		microcosm-cc:bluemonday:v1.0.6:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mikesmitty:edkey:3356ea4e686a:mikesmitty_edkey/vendor/github.com/mikesmitty/edkey \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		muesli:ansi:2e021307bc4b:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.9.0:muesli_termenv/vendor/github.com/muesli/termenv \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		xanzy:ssh-agent:v0.3.0:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		yuin:goldmark-emoji:v1.0.1:yuin_goldmark_emoji/vendor/github.com/yuin/goldmark-emoji \
		yuin:goldmark:v1.3.3:yuin_goldmark/vendor/github.com/yuin/goldmark

GO_TARGET=	./cmd/soft
USE_RC_SUBR=	soft-serve
SUB_LIST+=	CHOWN="${CHOWN}" \
		CUT="${CUT}" \
		DEFAULTHOST=0.0.0.0 \
		DEFAULTKEY=.ssh/soft_serve_server_ed25519 \
		DEFAULTPORT=23231 \
		DEFAULTREPO=.repos \
		DIRNAME="${DIRNAME}" \
		GITUSER="${USERS}" \
		MKDIR="${MKDIR}" \
		PW="${PW}" \
		SETENV="${SETENV}"
USERS=		git
GROUPS=		git
PLIST_FILES=	${DOCSDIR_REL}/README.md \
		bin/${PORTNAME}

.include <bsd.port.options.mk>

# Patch for 32-bit platforms
.if ${ARCH} == i386 || ${ARCH} == armv7 || ${ARCH} == armv6
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-vendor_github.com_charmbracelet_bubbletea_cancelreader__bsd.go
.endif

post-install:
		${MV} ${STAGEDIR}${PREFIX}/bin/soft ${STAGEDIR}${PREFIX}/bin/soft-serve
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
