# $FreeBSD$

PORTNAME=	lab
PORTVERSION=	0.16.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Lab makes it simple to work with repositories on GitLab

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules

USE_GITHUB=	yes

GH_TUPLE=	zaquestion:${PORTNAME}:${DISTVERSIONPREFIX}${PORTVERSION}:DEFAULT \
		avast:retry-go:5469272a8171:avast_retry_go/vendor/github.com/avast/retry-go \
		cpuguy83:go-md2man:v1.0.8:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gdamore:encoding:b23993cbb635:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:2f258105ca8c:gdamore_tcell/vendor/github.com/gdamore/tcell \
		go-yaml:yaml:v2.2.1:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.3.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:0709b304e793:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:03003ca0c849:golang_net/vendor/golang.org/x/net \
		golang:oauth2:f42d05182288:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.2.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:33540a1f6037:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		hashicorp:hcl:ef8a98b0bbce:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		lucasb-eyer:go-colorful:231272389856:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		lunixbochs:vtclean:2d01aacdc34a:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		magiconair:properties:v1.7.6:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-runewidth:v0.0.2:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:00c29f56e238:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.1.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:tview:f855bee0205c:rivo_tview/vendor/github.com/rivo/tview \
		rsteube:cobra:v0.0.1-zsh-completion-custom:rsteube_cobra/vendor/github.com/spf13/cobra \
		russross:blackfriday:v1.5.1:russross_blackfriday/vendor/github.com/russross/blackfriday \
		spf13:afero:v1.1.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.2.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:7c0cea34c8ec:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.1:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:15738813a09d:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.2.2:stretchr_testify/vendor/github.com/stretchr/testify \
		tcnksm:go-gitconfig:v0.1.2:tcnksm_go_gitconfig/vendor/github.com/tcnksm/go-gitconfig \
		xanzy:go-gitlab:7bc4155e8bf8:xanzy_go_gitlab/vendor/github.com/xanzy/go-gitlab

GO_BUILDFLAGS=	-ldflags="-X main.version=${PORTVERSION}"

PLIST_FILES=	bin/lab

.include <bsd.port.mk>
