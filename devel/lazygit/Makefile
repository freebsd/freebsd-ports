# $FreeBSD$

PORTNAME=	lazygit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.4
CATEGORIES=	devel

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Simple terminal UI for git commands

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	jesseduffield
GH_TUPLE=	\
		aws:aws-sdk-go:v1.15.21:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		cloudfoundry:jibber_jabber:bcc4c8345a21:cloudfoundry_jibber_jabber/vendor/github.com/cloudfoundry/jibber_jabber \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		emirpasic:gods:v1.9.0:emirpasic_gods/vendor/github.com/emirpasic/gods \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-errors:errors:v1.0.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-ini:ini:v1.38.2:go_ini_ini/vendor/github.com/go-ini/ini \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v2.2.1:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang-collections:collections:604e922904d3:golang_collections_collections/vendor/github.com/golang-collections/collections \
		golang:crypto:e1dfcc566284:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:f4e77d36d62c:golang_net/vendor/golang.org/x/net \
		golang:sys:ecd444e8653b:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		hashicorp:go-cleanhttp:d5fe4b57a186:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-getter:4bda8fa99001:hashicorp_go_getter/vendor/github.com/hashicorp/go-getter \
		hashicorp:go-safetemp:b1a1dbde6fdc:hashicorp_go_safetemp/vendor/github.com/hashicorp/go-safetemp \
		hashicorp:go-version:v1.0.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:ef8a98b0bbce:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		integrii:flaggy:v1.2.2:integrii_flaggy/vendor/github.com/integrii/flaggy \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		jesseduffield:go-getter:906e15686e63:jesseduffield_go_getter/vendor/github.com/jesseduffield/go-getter \
		jesseduffield:gocui:3cf1932858a3:jesseduffield_gocui/vendor/github.com/jesseduffield/gocui \
		jesseduffield:pty:02db52c7e406:jesseduffield_pty/vendor/github.com/jesseduffield/pty \
		jesseduffield:roll:695be2e62b00:jesseduffield_roll/vendor/github.com/jesseduffield/roll \
		jesseduffield:rollrus:dd028cb0bfd7:jesseduffield_rollrus/vendor/github.com/jesseduffield/rollrus \
		jesseduffield:termbox-go:1e272ff78dcb:jesseduffield_termbox_go/vendor/github.com/jesseduffield/termbox-go \
		jmespath:go-jmespath:0b12d6b521d8:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		kardianos:osext:ae77be60afb1:kardianos_osext/vendor/github.com/kardianos/osext \
		kevinburke:ssh_config:9fc7bb800b55:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		magiconair:properties:v1.8.0:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.3:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.2:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mgutz:str:v1.2.0:mgutz_str/vendor/github.com/mgutz/str \
		mitchellh:go-homedir:58046073cbff:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-testing-interface:a61a99592b77:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:mapstructure:f15292f7a699:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		nicksnyder:go-i18n:v2.0.2:nicksnyder_go_i18n/vendor/github.com/nicksnyder/go-i18n/v2 \
		pelletier:go-buffruneio:v0.2.0:pelletier_go_buffruneio/vendor/github.com/pelletier/go-buffruneio \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		sergi:go-diff:v1.0.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shibukawa:configdir:e180dbdc8da0:shibukawa_configdir/vendor/github.com/shibukawa/configdir \
		sirupsen:logrus:v1.3.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.1.1:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.2.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:14d3d4c51834:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.2:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.1.0:spf13_viper/vendor/github.com/spf13/viper \
		spkg:bom:59b7046e48ad:spkg_bom/vendor/github.com/spkg/bom \
		src-d:gcfg:v1.3.0:src_d_gcfg/vendor/github.com/src-d/gcfg \
		src-d:go-billy:v4.2.0:src_d_go_billy/vendor/gopkg.in/src-d/go-billy.v4 \
		src-d:go-git:43d17e14b714:src_d_go_git/vendor/gopkg.in/src-d/go-git.v4 \
		stretchr:testify:v1.2.2:stretchr_testify/vendor/github.com/stretchr/testify \
		tcnksm:go-gitconfig:v0.1.2:tcnksm_go_gitconfig/vendor/github.com/tcnksm/go-gitconfig \
		ulikunitz:xz:v0.5.4:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		xanzy:ssh-agent:v0.2.0:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
