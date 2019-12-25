# $FreeBSD$

PORTNAME=	mutagen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.2
CATEGORIES=	devel net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Continuous multidirectional synchronization for remote development

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	havoc-io
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Microsoft:go-winio:3fe4fa31662f:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		bmatcuk:doublestar:v1.1.1:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eknkc:basex:v1.0.0:eknkc_basex/vendor/github.com/eknkc/basex \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:b43e412143f9:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:5b532d6fd5ef:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:f3200d17e092:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:f0ce4c0180be:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		google:go-genproto:24fa4b261c55:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		grpc:grpc-go:v1.25.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:yamux:2f1d1f20f75d:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		hectane:go-acl:e28f47eff0c4:hectane_go_acl/vendor/github.com/hectane/go-acl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kubernetes:apimachinery:6a84e37a896d:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:klog:v0.3.0:kubernetes_klog/vendor/k8s.io/klog \
		mattn:go-colorable:v0.1.1:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.7:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mutagen-io:fsevents:10556809b434:mutagen_io_fsevents/vendor/github.com/mutagen-io/fsevents \
		mutagen-io:gopass:9a121bec1ae7:mutagen_io_gopass/vendor/github.com/mutagen-io/gopass \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		shibukawa:extstat:4113c04d0977:shibukawa_extstat/vendor/github.com/shibukawa/extstat \
		spf13:cobra:b04b5bfc50cb:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag

GO_TARGET=	./cmd/mutagen \
		./cmd/mutagen-agent

PLIST_FILES=	bin/mutagen \
		bin/mutagen-agent

.include <bsd.port.mk>
