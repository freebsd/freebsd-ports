PORTNAME=	ticker
DISTVERSIONPREFIX=	v
DISTVERSION=	4.5.0
CATEGORIES=	finance

MAINTAINER=	fuz@fuz.su
COMMENT=	Terminal stock ticker with live updates and position tracking

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	achannarasappa
GH_TUPLE=	acarl005:stripansi:5a71ef0e047d:acarl005_stripansi/vendor/github.com/acarl005/stripansi \
		achannarasappa:term-grid:v0.2.4:achannarasappa_term_grid/vendor/github.com/achannarasappa/term-grid \
		adrg:xdg:v0.4.0:adrg_xdg/vendor/github.com/adrg/xdg \
		charmbracelet:bubbles:v0.10.3:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v0.20.0:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:lipgloss:v0.5.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		containerd:console:v1.0.3:containerd_console/vendor/github.com/containerd/console \
		fsnotify:fsnotify:v1.5.1:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.66.4:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-resty:resty:v2.7.0:go_resty_resty_v2/vendor/github.com/go-resty/resty/v2 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:net:cd36cc0744dd:golang_net/vendor/golang.org/x/net \
		golang:sys:3681064d5158:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jarcoal:httpmock:v1.0.7:jarcoal_httpmock/vendor/github.com/jarcoal/httpmock \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		magiconair:properties:v1.8.5:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.4.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		muesli:ansi:c9f0611b6c70:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:44cd13922739:muesli_termenv/vendor/github.com/muesli/termenv \
		onsi:ginkgo:v1.16.5:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:ginkgo:v2.1.2:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		onsi:gomega:v1.17.0:onsi_gomega/vendor/github.com/onsi/gomega \
		pelletier:go-toml:v1.9.4:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		spf13:afero:v1.8.1:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.4.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.3.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.10.1:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		xeipuuv:gojsonpointer:4e3ac2762d5f:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		xeipuuv:gojsonreference:bd5ef7bd5415:xeipuuv_gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
		xeipuuv:gojsonschema:v1.2.0:xeipuuv_gojsonschema/vendor/github.com/xeipuuv/gojsonschema

GO_BUILDFLAGS=	-ldflags="-X github.com/achannarasappa/ticker/cmd.Version=${DISTVERSIONPREFIX}${PKGVERSION}"

PLIST_FILES=	bin/ticker
PORTDOCS=	README.md \
		docs/debug-guide.md \
		docs/ticker-all-options.png \
		docs/ticker-currency.png \
		docs/ticker.gif
OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
.for doc in ${PORTDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${doc:H}
	${INSTALL_MAN} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}/${doc:H}/
.endfor

.include <bsd.port.mk>
