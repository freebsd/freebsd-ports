# $FreeBSD$

PORTNAME=	lazygit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.3
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
		go-errors:errors:v1.0.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v2.2.5:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang-collections:collections:604e922904d3:golang_collections_collections/vendor/github.com/golang-collections/collections \
		golang:crypto:e1110fd1c708:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:2180aed22343:golang_net/vendor/golang.org/x/net \
		golang:sys:59a1497f0cea:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		integrii:flaggy:v1.3.0:integrii_flaggy/vendor/github.com/integrii/flaggy \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		jesseduffield:gocui:b13bda319532:jesseduffield_gocui/vendor/github.com/jesseduffield/gocui \
		jesseduffield:pty:v1.2.1:jesseduffield_pty/vendor/github.com/jesseduffield/pty \
		jesseduffield:roll:695be2e62b00:jesseduffield_roll/vendor/github.com/jesseduffield/roll \
		jesseduffield:rollrus:dd028cb0bfd7:jesseduffield_rollrus/vendor/github.com/jesseduffield/rollrus \
		nsf:termbox-go:58d4fcbce2a7:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		kevinburke:ssh_config:01f96b0aa0cd:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.10:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.6:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mgutz:str:v1.2.0:mgutz_str/vendor/github.com/mgutz/str \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		nicksnyder:go-i18n:v2.0.2:nicksnyder_go_i18n/vendor/github.com/nicksnyder/go-i18n/v2 \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		sergi:go-diff:v1.0.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shibukawa:configdir:e180dbdc8da0:shibukawa_configdir/vendor/github.com/shibukawa/configdir \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.5.0:spf13_viper/vendor/github.com/spf13/viper \
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
