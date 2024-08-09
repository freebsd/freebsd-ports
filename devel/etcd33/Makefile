PORTNAME=	etcd
PORTVERSION=	3.3.23
DISTVERSIONPREFIX=	v
PORTREVISION=	24
CATEGORIES=	devel
PKGNAMEPREFIX=	coreos-
PKGNAMESUFFIX=	33

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly-available key value store and service discovery
WWW=		https://github.com/coreos/etcd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	coreos
GH_TUPLE=	beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		cheggaaa:pb:v1.0.2:cheggaaa_pb/vendor/gopkg.in/cheggaaa/pb.v1 \
		coreos:bbolt:v1.3.3:coreos_bbolt/vendor/github.com/coreos/bbolt \
		coreos:etcd:v3.3.22:coreos_etcd/vendor/github.com/coreos/etcd \
		coreos:go-semver:v0.2.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:e64a0ec8b42a:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		coreos:pkg:97fdf19511ea:coreos_pkg/vendor/github.com/coreos/pkg \
		cpuguy83:go-md2man:23709d084719:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man \
		dgrijalva:jwt-go:v3.0.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:cbcb75029529:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:869f871628b6:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:59133d7f0dd7:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:fe76b779f299:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:c06e80d9300e:golang_time/vendor/golang.org/x/time \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:go-genproto:c66870c02cf8:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.0.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:4201258b820c:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc-ecosystem:go-grpc-middleware:v1.0.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:0dafe0d496ea:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc-ecosystem:grpc-gateway:v1.3.1:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.23.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jonboulle:clockwork:v0.1.0:jonboulle_clockwork/vendor/github.com/jonboulle/clockwork \
		json-iterator:go:v1.1.7:json_iterator_go/vendor/github.com/json-iterator/go \
		kr:pty:v1.1.1:kr_pty/vendor/github.com/kr/pty \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		mattn:go-runewidth:v0.0.2:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:c182affec369:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		olekukonko:tablewriter:a0225b3f23b5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		prometheus:client_golang:5cec1d0429b0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:6f3806018612:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:e3fb1a1acd76:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:a6e9df898b13:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		russross:blackfriday:4048872b16cc:russross_blackfriday/vendor/github.com/russross/blackfriday \
		sirupsen:logrus:v1.0.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		soheilhy:cmux:v0.1.4:soheilhy_cmux/vendor/github.com/soheilhy/cmux \
		spf13:cobra:1c44ec8d3f15:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.0:spf13_pflag/vendor/github.com/spf13/pflag \
		tmc:grpc-websocket-proxy:89b8d40f7ca8:tmc_grpc_websocket_proxy/vendor/github.com/tmc/grpc-websocket-proxy \
		uber-go:atomic:v1.6.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.5.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.10.0:uber_go_zap/vendor/go.uber.org/zap \
		urfave:cli:v1.18.0:urfave_cli/vendor/github.com/urfave/cli \
		xiang90:probing:07dd2e8dfe18:xiang90_probing/vendor/github.com/xiang90/probing

GO_PKGNAME=	github.com/coreos/etcd
GO_TARGET=	. ./etcdctl

CONFLICTS_INSTALL=	coreos-etcd[0-9][0-9]

PLIST_FILES=	bin/etcd \
		bin/etcdctl
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install etcd README file

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
