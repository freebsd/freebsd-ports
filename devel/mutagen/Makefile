# $FreeBSD$

PORTNAME=	mutagen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.2
CATEGORIES=	devel net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Continuous multidirectional synchronization for remote development

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	havoc-io
GH_TUPLE=	\
		bmatcuk:doublestar:85a7880:doublestar/vendor/github.com/bmatcuk/doublestar \
		BurntSushi:toml:3012a1d:toml/vendor/github.com/BurntSushi/toml \
		dustin:go-humanize:9f541cc:go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:3f9d52f:color/vendor/github.com/fatih/color \
		havoc-io:gopass:9a121be:gopass/vendor/github.com/havoc-io/gopass \
		golang:crypto:3cb0727:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:461777f:net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.1:protobuf/vendor/github.com/golang/protobuf \
		golang:sys:f49334f85ddc:golang_sys/vendor/golang.org/x/sys \
		golang:text:17ff2d5:golang_text/vendor/golang.org/x/text \
		google:go-genproto:02b4e95:go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.1:uuid/vendor/github.com/google/uuid \
		grpc:grpc-go:v1.19.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		kubernetes:apimachinery:2b1284ed4c93:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:klog:8139d8cb77af:kubernetes_klog/vendor/k8s.io/klog \
		mattn:go-colorable:v0.1.1:go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.7:go_isatty/vendor/github.com/mattn/go-isatty \
		pkg:errors:v0.8.1:errors/vendor/github.com/pkg/errors \
		shibukawa:extstat:4113c04:extstat/vendor/github.com/shibukawa/extstat \
		spf13:cobra:v0.0.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag

GO_TARGET=	./cmd/mutagen \
		./cmd/mutagen-agent \
		./pkg/daemon/locktest

PLIST_FILES=	bin/mutagen \
		bin/mutagen-agent \
		bin/locktest

.include <bsd.port.mk>
