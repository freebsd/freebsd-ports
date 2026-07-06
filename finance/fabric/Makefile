PORTNAME=	fabric
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.5
CATEGORIES=	finance
PKGNAMESUFFIX=	-hyperledger

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Enterprise-grade permissioned distributed ledger framework
WWW=		https://wiki.hyperledger.org/display/fabric \
		https://github.com/hyperledger/fabric

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc # compilation fails on non-64-bit systems: fabric-amcl/core/FP256BN/FP.go:111:19: cannot convert MConst (constant 30564559323915749 of type Chunk) to type int

USES=		go:1.26+,modules
USE_GITHUB=	yes
GH_ACCOUNT=	hyperledger

GH_TUPLE=	\
		IBM:idemix:72941a5f41cd:ibm_idemix/vendor/github.com/IBM/idemix \
		IBM:mathlib:a138079496c3:ibm_mathlib/vendor/github.com/IBM/mathlib \
		Knetic:govaluate:9aa49832a739:knetic_govaluate/vendor/github.com/Knetic/govaluate \
		Masterminds:semver:v3.4.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Microsoft:go-winio:v0.6.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		VictoriaMetrics:fastcache:v1.12.2:victoriametrics_fastcache/vendor/github.com/VictoriaMetrics/fastcache \
		VividCortex:ewma:v1.2.0:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:61d1e3462e30:alecthomas_units/vendor/github.com/alecthomas/units \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bits-and-blooms:bitset:v1.20.0:bits_and_blooms_bitset/vendor/github.com/bits-and-blooms/bitset \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheggaaa:pb:v3.1.5:cheggaaa_pb_v3/vendor/github.com/cheggaaa/pb \
		cloudfoundry:clock:v1.15.0:cloudfoundry_clock/vendor/code.cloudfoundry.org/clock \
		consensys:gnark-crypto:v0.19.2:consensys_gnark_crypto/vendor/github.com/consensys/gnark-crypto \
		containerd:errdefs:pkg/v0.3.0:containerd_errdefs_pkg \
		containerd:errdefs:v1.0.0:containerd_errdefs/vendor/github.com/containerd/errdefs \
		coreos:go-semver:v0.3.1:coreos_go_semver/vendor/github.com/coreos/go-semver \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		distribution:reference:v0.6.0:distribution_reference/vendor/github.com/distribution/reference \
		docker:go-connections:v0.7.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.5.0:docker_go_units/vendor/github.com/docker/go-units \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		etcd-io:etcd:api/v3.6.10:etcd_io_etcd_v3/vendor/go.etcd.io/etcd/api/v3 \
		etcd-io:etcd:client/pkg/v3.6.10:etcd_io_etcd_v3_1/vendor/go.etcd.io/etcd/client/pkg/v3 \
		etcd-io:etcd:pkg/v3.6.10:etcd_io_etcd_v3_2/vendor/go.etcd.io/etcd/pkg/v3 \
		etcd-io:etcd:server/v3.6.10:etcd_io_etcd_v3_3/vendor/go.etcd.io/etcd/server/v3 \
		etcd-io:raft:v3.6.0:etcd_io_raft_v3/vendor/go.etcd.io/raft/v3 \
		expr-lang:expr:v1.17.8:expr_lang_expr/vendor/github.com/expr-lang/expr \
		fatih:color:v1.15.0:fatih_color/vendor/github.com/fatih/color \
		felixge:httpsnoop:v1.0.4:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fsnotify:fsnotify:v1.8.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-kit:kit:v0.13.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-kit:log:v0.2.1:go_kit_log/vendor/github.com/go-kit/log \
		go-logfmt:logfmt:v0.5.1:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-logr:logr:v1.4.3:go_logr_logr/vendor/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/github.com/go-logr/stdr \
		go-task:slim-sprig:v3.0.0:go_task_slim_sprig_v3/vendor/github.com/go-task/slim-sprig/v3 \
		go-viper:mapstructure:v2.4.0:go_viper_mapstructure_v2/vendor/github.com/go-viper/mapstructure/v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:v0.52.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.36.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.55.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:v0.20.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.45.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.37.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.45.0:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.7.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:3dc84a4a5aaa:google_go_genproto_api/vendor/google.golang.org/genproto \
		google:pprof:545e8a4df936:google_pprof/vendor/github.com/google/pprof \
		gorilla:handlers:v1.5.2:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		grpc-ecosystem:grpc-gateway:v2.26.3:grpc_ecosystem_grpc_gateway_v2/vendor/github.com/grpc-ecosystem/grpc-gateway/v2 \
		grpc:grpc-go:v1.81.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hyperledger-labs:SmartBFT:v1.0.1:hyperledger_labs_smartbft/vendor/github.com/hyperledger-labs/SmartBFT \
		hyperledger:aries-bbs-go:761671ea73bc:hyperledger_aries_bbs_go/vendor/github.com/hyperledger/aries-bbs-go \
		hyperledger:fabric-amcl:9e02669dceb2:hyperledger_fabric_amcl/vendor/github.com/hyperledger/fabric-amcl \
		hyperledger:fabric-chaincode-go:v2.3.0:hyperledger_fabric_chaincode_go_v2/vendor/github.com/hyperledger/fabric-chaincode-go/v2 \
		hyperledger:fabric-config:v0.3.0:hyperledger_fabric_config/vendor/github.com/hyperledger/fabric-config \
		hyperledger:fabric-lib-go:v1.1.3:hyperledger_fabric_lib_go/vendor/github.com/hyperledger/fabric-lib-go \
		hyperledger:fabric-protos-go-apiv2:v0.3.7:hyperledger_fabric_protos_go_apiv2/vendor/github.com/hyperledger/fabric-protos-go-apiv2 \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kilic:bls12-381:v0.1.0:kilic_bls12_381/vendor/github.com/kilic/bls12-381 \
		klauspost:compress:v1.17.9:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.19:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.15:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miekg:pkcs11:v1.1.1:miekg_pkcs11/vendor/github.com/miekg/pkcs11 \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moby:docker-image-spec:v1.3.1:moby_docker_image_spec/vendor/github.com/moby/docker-image-spec \
		moby:moby:api/v1.54.2:moby_moby_api/vendor/github.com/moby/moby \
		moby:moby:client/v0.4.1:moby_moby_client \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/github.com/munnerz/goautoneg \
		onsi:ginkgo:v2.29.0:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		onsi:gomega:v1.41.0:onsi_gomega/vendor/github.com/onsi/gomega \
		open-telemetry:opentelemetry-go-contrib:instrumentation/net/http/otelhttp/v0.68.0:open_telemetry_opentelemetry_go_contrib_otelhttp/vendor/go.opentelemetry.io/contrib \
		open-telemetry:opentelemetry-go-instrumentation:sdk/v1.2.1:open_telemetry_opentelemetry_go_instrumentation_sdk/vendor/go.opentelemetry.io/auto \
		open-telemetry:opentelemetry-go:metric/v1.43.0:open_telemetry_opentelemetry_go_metric \
		open-telemetry:opentelemetry-go:trace/v1.43.0:open_telemetry_opentelemetry_go_trace \
		open-telemetry:opentelemetry-go:v1.43.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.1.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		pelletier:go-toml:v2.2.3:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.20.5:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.1:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.62.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.15.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.36.11:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rogpeppe:go-internal:v1.14.1:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		sagikazarmark:locafero:v0.7.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.12.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.7.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.10.2:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.10:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.20.1:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:objx:v0.5.2:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.11.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		sykesm:zap-logfmt:v0.0.4:sykesm_zap_logfmt/vendor/github.com/sykesm/zap-logfmt \
		syndtr:goleveldb:126854af5e6d:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		tedsuo:ifrit:7862c310ad26:tedsuo_ifrit/vendor/github.com/tedsuo/ifrit \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.28.0:uber_go_zap/vendor/go.uber.org/zap \
		yaml:go-yaml:v3.0.4:yaml_go_yaml/vendor/go.yaml.in/yaml/v3 \
		yaml:go-yaml:v4.0.0-rc.4:yaml_go_yaml_1/vendor/go.yaml.in/yaml/v4

GO_ENV+=	GOTOOLCHAIN=local+path

PROGS=		configtxgen \
		configtxlator \
		cryptogen \
		discover \
		ledgerutil \
		orderer \
		osnadmin \
		peer

GO_TARGET=	${PROGS:S/^/.\/cmd\//}
PLIST_FILES=	${PROGS:S/^/bin\//}

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/containerd/errdefs/pkg
	@${RLN} ${WRKSRC_containerd_errdefs_pkg}/pkg ${WRKSRC}/vendor/github.com/containerd/errdefs/pkg
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/moby/client
	@${RLN} ${WRKSRC_moby_moby_client}/client ${WRKSRC}/vendor/github.com/moby/moby/client
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/otel/metric
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_metric}/metric ${WRKSRC}/vendor/go.opentelemetry.io/otel/metric
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/otel/trace
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_trace}/trace ${WRKSRC}/vendor/go.opentelemetry.io/otel/trace

.include <bsd.port.mk>
