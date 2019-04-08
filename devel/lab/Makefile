# $FreeBSD$

PORTNAME=	lab
PORTVERSION=	0.15.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Lab makes it simple to work with repositories on GitLab

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.10,1:lang/go

OPTIONS_DEFINE=	GIT_SUBVERSION

GIT_SUBVERSION_DESC=	Use devel/git-subversion as backend
GIT_SUBVERSION_RUN_DEPENDS=	git-subversion>0:devel/git-subversion
GIT_SUBVERSION_RUN_DEPENDS_OFF=	git:devel/git

USE_GITHUB=	yes

GH_TUPLE=	zaquestion:${PORTNAME}:${DISTVERSIONPREFIX}${PORTVERSION}:DEFAULT/src/github.com/zaquestion/${PORTNAME} \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		armon:consul-api:eb2c6b5:armon_consul_api/vendor/github.com/armon/consul-api \
		avast:retry-go:5469272:avast_retry_go/vendor/github.com/avast/retry-go \
		coreos:go-etcd:v2.0.0:coreos_go_etcd/vendor/github.com/coreos/go-etcd \
		cpuguy83:go-md2man:v1.0.8:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gdamore:encoding:b23993c:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:2f25810:gdamore_tcell/vendor/github.com/gdamore/tcell \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.4.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c2843e0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:d888771:golang_net/vendor/golang.org/x/net \
		golang:oauth2:e64efc7:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.2.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:e225da7:golang_sync/vendor/golang.org/x/sync \
		golang:sys:d0b11bd:golang_sys/vendor/golang.org/x/sys \
		golang:text:17ff2d5:golang_text/vendor/golang.org/x/text \
		golang:tools:e65039e:golang_tools/vendor/golang.org/x/tools \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		googleapis:gax-go:v2.0.4:googleapis_gax_go/vendor/github.com/googleapis/gax-go/v2 \
		gopherjs:gopherjs:d547d1d:gopherjs_gopherjs/vendor/github.com/gopherjs/gopherjs \
		hashicorp:golang-lru:v0.5.0:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:ef8a98b:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jtolds:gls:v4.2.1:jtolds_gls/vendor/github.com/jtolds/gls \
		kr:fs:v0.1.0:kr_fs/vendor/github.com/kr/fs \
		lucasb-eyer:go-colorful:2312723:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		lunixbochs:vtclean:2d01aac:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		magiconair:properties:v1.7.6:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-runewidth:v0.0.2:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:00c29f5:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		onsi:gomega:v1.4.3:onsi_gomega/vendor/github.com/onsi/gomega \
		pelletier:go-toml:v1.1.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pkg:sftp:v1.10.0:pkg_sftp/vendor/github.com/pkg/sftp \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:tview:f855bee:rivo_tview/vendor/github.com/rivo/tview \
		rsteube:cobra:v0.0.1-zsh-completion-custom:rsteube_cobra/vendor/github.com/spf13/cobra \
		russross:blackfriday:v1.5.1:russross_blackfriday/vendor/github.com/russross/blackfriday \
		smartystreets:assertions:b2de0cb:smartystreets_assertions/vendor/github.com/smartystreets/assertions \
		smartystreets:goconvey:044398e:smartystreets_goconvey/vendor/github.com/smartystreets/goconvey \
		spf13:afero:v1.1.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.2.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:7c0cea3:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.1:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:1573881:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:objx:v0.1.1:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.2.2:stretchr_testify/vendor/github.com/stretchr/testify \
		tcnksm:go-gitconfig:v0.1.2:tcnksm_go_gitconfig/vendor/github.com/tcnksm/go-gitconfig \
		xanzy:go-gitlab:7bc4155:xanzy_go_gitlab/vendor/github.com/xanzy/go-gitlab \
		xordataexchange:crypt:v0.0.2:xordataexchange_crypt/vendor/github.com/xordataexchange/crypt

PLIST_FILES=	bin/lab

do-build:
	@cd ${WRKSRC}/src/github.com/zaquestion/${PORTNAME}; \
		${SETENV} ${MAKE_ENV} CGO_ENABLED=0 ${BUILD_ENV} \
		GOPATH=${WRKSRC} go build \
		-ldflags "-X \"main.version=${PORTVERSION}\""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
