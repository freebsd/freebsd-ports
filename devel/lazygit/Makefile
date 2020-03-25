# $FreeBSD$

PORTNAME=	lazygit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.4
CATEGORIES=	devel

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Simple terminal UI for git commands

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	jesseduffield
GH_TUPLE=	\
		cloudfoundry:jibber_jabber:bcc4c8345a21:cloudfoundry_jibber_jabber/vendor/github.com/cloudfoundry/jibber_jabber \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		emirpasic:gods:v1.12.0:emirpasic_gods/vendor/github.com/emirpasic/gods \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-errors:errors:v1.0.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v2.2.7:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang-collections:collections:604e922904d3:golang_collections_collections/vendor/github.com/golang-collections/collections \
		golang:crypto:e9b2fee46413:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:c0dbc17a3553:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:ac6580df4449:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.3.1:google_go_cmp/vendor/github.com/google/go-cmp \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		integrii:flaggy:v1.4.0:integrii_flaggy/vendor/github.com/integrii/flaggy \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		jesseduffield:gocui:7765949e1c8a:jesseduffield_gocui/vendor/github.com/jesseduffield/gocui \
		jesseduffield:pty:v1.2.1:jesseduffield_pty/vendor/github.com/jesseduffield/pty \
		jesseduffield:termbox-go:1d31d1faa3c9:jesseduffield_termbox_go/vendor/github.com/jesseduffield/termbox-go \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		kevinburke:ssh_config:01f96b0aa0cd:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.11:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.8:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mgutz:str:v1.2.0:mgutz_str/vendor/github.com/mgutz/str \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:gox:v1.0.1:mitchellh_gox/vendor/github.com/mitchellh/gox \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		nicksnyder:go-i18n:v2.0.3:nicksnyder_go_i18n/vendor/github.com/nicksnyder/go-i18n/v2 \
		onsi:ginkgo:v1.10.3:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.7.1:onsi_gomega/vendor/github.com/onsi/gomega \
		pelletier:go-toml:v1.6.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		sergi:go-diff:v1.0.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shibukawa:configdir:e180dbdc8da0:shibukawa_configdir/vendor/github.com/shibukawa/configdir \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.6.1:spf13_viper/vendor/github.com/spf13/viper \
		spkg:bom:59b7046e48ad:spkg_bom/vendor/github.com/spkg/bom \
		src-d:gcfg:v1.4.0:src_d_gcfg/vendor/github.com/src-d/gcfg \
		src-d:go-billy:v4.3.2:src_d_go_billy/vendor/gopkg.in/src-d/go-billy.v4 \
		src-d:go-git:v4.13.1:src_d_go_git/vendor/gopkg.in/src-d/go-git.v4 \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tcnksm:go-gitconfig:v0.1.2:tcnksm_go_gitconfig/vendor/github.com/tcnksm/go-gitconfig \
		xanzy:ssh-agent:v0.2.1:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
