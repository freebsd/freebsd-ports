PORTNAME=	treefmt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.1
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	One CLI to format the code tree
WWW=		https://treefmt.com/ \
		https://github.com/numtide/treefmt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	numtide
GH_TUPLE=	\
		BurntSushi:toml:v1.4.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		adrg:xdg:v0.5.3:adrg_xdg/vendor/github.com/adrg/xdg \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		charmbracelet:lipgloss:v0.10.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:log:v0.4.0:charmbracelet_log/vendor/github.com/charmbracelet/log \
		davecgh:go-spew:d8f796af33cc:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		etcd-io:bbolt:v1.3.11:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fsnotify:fsnotify:v1.7.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-logfmt:logfmt:v0.6.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		golang:exp:8a7402abbf56:golang_exp/vendor/golang.org/x/exp \
		golang:sync:v0.9.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.27.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.25.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.18.0:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.15:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:reflow:v0.3.0:muesli_reflow/vendor/github.com/muesli/reflow \
		muesli:termenv:v0.15.2:muesli_termenv/vendor/github.com/muesli/termenv \
		mvdan:sh:v3.10.0:mvdan_sh/vendor/mvdan.cc/sh/v3 \
		otiai10:copy:v1.14.0:otiai10_copy/vendor/github.com/otiai10/copy \
		pelletier:go-toml:v2.2.2:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pmezard:go-difflib:5d4384ee4fb2:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rogpeppe:go-internal:v1.13.1:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		sagikazarmark:locafero:v0.4.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sagikazarmark:slog-shim:v0.1.0:sagikazarmark_slog_shim/vendor/github.com/sagikazarmark/slog-shim \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.11.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.6.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.8.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.19.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.10.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.9.0:uber_go_multierr/vendor/go.uber.org/multierr

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
