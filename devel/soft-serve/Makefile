PORTNAME=	soft-serve
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Self-hosted Git server for the command line

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	charmbracelet
GH_TUPLE=	Microsoft:go-winio:v0.5.1:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:70ae35bab23f:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		acomagu:bufpipe:v1.0.3:acomagu_bufpipe/vendor/github.com/acomagu/bufpipe \
		alecthomas:chroma:v0.10.0:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		anmitsu:go-shlex:38f4b401e2be:anmitsu_go_shlex/vendor/github.com/anmitsu/go-shlex \
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		caarlos0:env:v6.9.1:caarlos0_env_v6/vendor/github.com/caarlos0/env/v6 \
		caarlos0:sshmarshal:v0.1.0:caarlos0_sshmarshal/vendor/github.com/caarlos0/sshmarshal \
		charmbracelet:bubbles:88562515cf7b:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v0.20.0:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:glamour:v0.4.0:charmbracelet_glamour/vendor/github.com/charmbracelet/glamour \
		charmbracelet:keygen:v0.3.0:charmbracelet_keygen/vendor/github.com/charmbracelet/keygen \
		charmbracelet:lipgloss:v0.4.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:wish:v0.5.0:charmbracelet_wish/vendor/github.com/charmbracelet/wish \
		containerd:console:v1.0.3:containerd_console/vendor/github.com/containerd/console \
		dlclark:regexp2:v1.4.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		emirpasic:gods:v1.12.0:emirpasic_gods/vendor/github.com/emirpasic/gods \
		gliderlabs:ssh:v0.3.4:gliderlabs_ssh/vendor/github.com/gliderlabs/ssh \
		go-git:gcfg:v1.5.0:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.3.1:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:b4368b2a2ca4:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gogs:git-module:v1.6.0:gogs_git_module/vendor/github.com/gogs/git-module \
		golang:crypto:efcb8507fb70:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:cd36cc0744dd:golang_net/vendor/golang.org/x/net \
		golang:sys:5a964db01320:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		kevinburke:ssh_config:v1.1.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		matryer:is:v1.4.0:matryer_is/vendor/github.com/matryer/is \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mcuadros:go-version:92cdf37c5b75:mcuadros_go_version/vendor/github.com/mcuadros/go-version \
		microcosm-cc:bluemonday:v1.0.17:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		muesli:ansi:c9f0611b6c70:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:mango:v0.1.0:muesli_mango/vendor/github.com/muesli/mango \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:roff:v0.1.0:muesli_roff/vendor/github.com/muesli/roff \
		muesli:termenv:44cd13922739:muesli_termenv/vendor/github.com/muesli/termenv \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sahilm:fuzzy:v0.1.0:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		spf13:cobra:v1.4.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		xanzy:ssh-agent:v0.3.1:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		yuin:goldmark-emoji:v1.0.1:yuin_goldmark_emoji/vendor/github.com/yuin/goldmark-emoji \
		yuin:goldmark:v1.4.4:yuin_goldmark/vendor/github.com/yuin/goldmark

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
