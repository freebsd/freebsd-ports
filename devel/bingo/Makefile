# $FreeBSD$

PORTNAME=	bingo
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0-128
DISTVERSIONSUFFIX=	-gac95a38
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Go language server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.11,1:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	saibing

# generated with gomod-deps below
GH_TUPLE=	apache:thrift:v0.12.0:thrift/vendor/git.apache.org/thrift.git \
		coreos:go-systemd:9002847aa142:go_systemd/vendor/github.com/coreos/go-systemd \
		dominikh:go-tools:c2f93a96b099:go_tools/vendor/honnef.co/go/tools \
		fsnotify:fsnotify:v1.4.7:fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-check:check:788fd7840127:check/vendor/gopkg.in/check.v1 \
		go-stack:stack:v1.8.0:stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:v2.2.2:yaml/vendor/gopkg.in/yaml.v2 \
		go4org:go4:00e24f1b2599:go4/vendor/go4.org \
		gogo:protobuf:v1.2.0:protobuf/vendor/github.com/gogo/protobuf \
		golang:mock:v1.2.0:mock/vendor/github.com/golang/mock \
		golang:net:915654e7eabc:net/vendor/golang.org/x/net \
		golang:oauth2:5dab4167f31c:oauth2/vendor/golang.org/x/oauth2 \
		golang:sys:a457fd036447:sys/vendor/golang.org/x/sys \
		golang:time:85acf8d2951c:time/vendor/golang.org/x/time \
		google:go-genproto:bd9b4fb69e2f:go_genproto/vendor/google.golang.org/genproto \
		google:google-api-go-client:v0.1.0:google_api_go_client/vendor/google.golang.org/api \
		googleapis:gax-go:v2.0.2:gax_go/vendor/github.com/googleapis/gax-go \
		gopherjs:gopherjs:d547d1d9531e:gopherjs/vendor/github.com/gopherjs/gopherjs \
		gorilla:websocket:v1.4.0:websocket/vendor/github.com/gorilla/websocket \
		gregjones:httpcache:c63ab54fda8f:httpcache/vendor/github.com/gregjones/httpcache \
		grpc-ecosystem:grpc-gateway:v1.6.4:grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.18.0:grpc_go/vendor/google.golang.org/grpc \
		inconshreveable:log15:67afb5ed74ec:log15/vendor/gopkg.in/inconshreveable/log15.v2 \
		mattn:go-colorable:v0.0.9:go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.4:go_isatty/vendor/github.com/mattn/go-isatty \
		microcosm-cc:bluemonday:v1.0.2:bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		openzipkin:zipkin-go:v0.1.5:zipkin_go/vendor/github.com/openzipkin/zipkin-go \
		pierrec:lz4:v2.0.7:lz4/vendor/github.com/pierrec/lz4 \
		pmezard:go-difflib:v1.0.0:go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v0.9.2:client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:common:67670fe90761:common/vendor/github.com/prometheus/common \
		russross:blackfriday:v2.0.0:blackfriday/vendor/github.com/russross/blackfriday \
		saibing:tools:v1.7.3:tools/vendor/golang.org/x/tools \
		Shopify:sarama:v1.20.1:sarama/vendor/github.com/Shopify/sarama \
		shurcooL:sanitized_anchor_name:v1.0.0:sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		slimsag:godocmd:a1005ad29fe3:godocmd/vendor/github.com/slimsag/godocmd \
		sourcegraph:jsonrpc2:549eb959f029:jsonrpc2/vendor/github.com/sourcegraph/jsonrpc2 \
		sqs:pbtypes:v1.0.0:pbtypes/vendor/sourcegraph.com/sqs/pbtypes \
		stretchr:objx:v0.1.1:objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.3.0:testify/vendor/github.com/stretchr/testify

PLIST_FILES=	bin/bingo

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} go build -mod=vendor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bingo ${STAGEDIR}${PREFIX}/bin

# XXX: Check if useful for other ports and maybe put it in a USES=gomod
gomod-deps: patch
	@${AWK} -f ${FILESDIR}/gomod.awk ${WRKSRC}/go.mod

.include <bsd.port.mk>
