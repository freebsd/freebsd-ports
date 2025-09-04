PORTNAME=	visp-go
DISTVERSION=	g20210723
PORTREVISION=	30
CATEGORIES=	audio

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Vi-like Spotify client for terminal users
WWW=		https://visp.site

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	ambientsound
GH_PROJECT=	${PORTNAME:C/-go//}
GH_TAGNAME=	2585747
GH_TUPLE=	beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.2.0:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		go-chi:chi:v1.5.4:go_chi_chi/vendor/github.com/go-chi/chi \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.4:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:04defd469f4e:golang_net/vendor/golang.org/x/net \
		golang:oauth2:d04028783cf1:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:2321bbc49cbf:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		gopherjs:gopherjs:d547d1d9531e:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-runewidth:v0.0.12:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v0.9.3:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:14fe0d1b01d4:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.4.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:5867b95ac084:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sirupsen:logrus:v1.2.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		smartystreets:assertions:b6c0e53d7304:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.6.1:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:objx:v0.1.1:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		zmb3:spotify:v1.3.0:zmb3_spotify/vendor/github.com/zmb3/spotify

_BUILD_VERSION=	${GH_TAGNAME}
_BUILD_DATE=	$$(date +%s)

GO_TARGET=	./cmd/${GH_PROJECT} ./cmd/${GH_PROJECT}-authproxy
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/version.Version=${_BUILD_VERSION}  \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/version.buildDate=${_BUILD_DATE}"

PORTSCOUT=	skipv:latest
SUB_FILES=	pkg-message
PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}
_DOCS=		CONTRIBUTING.md README.md code_of_conduct.md doc/commands.md \
		doc/intro.md doc/spotify.md doc/options.md doc/${GH_PROJECT}.md
PORTDOCS=	${_DOCS:T}

OPTIONS_DEFINE=	DOCS SPOTIFYD

SPOTIFYD_DESC=		Lightweight Spotify client daemon
SPOTIFYD_RUN_DEPENDS=	spotifyd:audio/spotifyd

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && \
		${INSTALL_DATA} ${_DOCS} \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
