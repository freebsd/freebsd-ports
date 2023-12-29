PORTNAME=	fabric
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.5
CATEGORIES=	finance
PKGNAMESUFFIX=	-hyperledger

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Enterprise-grade permissioned distributed ledger framework
WWW=		https://wiki.hyperledger.org/display/fabric

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	hyperledger

# the upstream claims that it is too difficult to add the /v2 suffix to the GoLang module URL: https://github.com/hyperledger/fabric/issues/2929
GH_TUPLE=	\
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		DataDog:zstd:v1.4.5:datadog_zstd/vendor/github.com/DataDog/zstd \
		IBM:idemix:701e7610d405:ibm_idemix/vendor/github.com/IBM/idemix \
		IBM:mathlib:0a7378db6912:ibm_mathlib/vendor/github.com/IBM/mathlib \
		Knetic:govaluate:9aa49832a739:knetic_govaluate/vendor/github.com/Knetic/govaluate \
		Microsoft:go-winio:v0.5.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.8.25:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		Shopify:sarama:v1.20.1:shopify_sarama/vendor/github.com/Shopify/sarama \
		VictoriaMetrics:fastcache:v1.9.0:victoriametrics_fastcache/vendor/github.com/VictoriaMetrics/fastcache \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:d1bdfacee922:alecthomas_units/vendor/github.com/alecthomas/units \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bits-and-blooms:bitset:v1.2.1:bits_and_blooms_bitset/vendor/github.com/bits-and-blooms/bitset \
		census-instrumentation:opencensus-go:v0.22.4:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheggaaa:pb:v1.0.29:cheggaaa_pb/vendor/github.com/cheggaaa/pb \
		cloudfoundry:clock:v1.0.0:cloudfoundry_clock/vendor/code.cloudfoundry.org/clock \
		consensys:gnark-crypto:v0.6.0:consensys_gnark_crypto/vendor/github.com/consensys/gnark-crypto \
		containerd:cgroups:v1.0.3:containerd_cgroups/vendor/github.com/containerd/cgroups \
		containerd:containerd:v1.5.18:containerd_containerd/vendor/github.com/containerd/containerd \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.5.0:docker_go_units/vendor/github.com/docker/go-units \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		etcd-io:etcd:v3.5.9:etcd_io_etcd/vendor/go.etcd.io/etcd/client/pkg/v3 \
		etcd-io:etcd:v3.5.9:etcd_io_etcd_1/vendor/go.etcd.io/etcd/pkg/v3 \
		etcd-io:etcd:v3.5.9:etcd_io_etcd_2/vendor/go.etcd.io/etcd/raft/v3 \
		etcd-io:etcd:v3.5.9:etcd_io_etcd_3/vendor/go.etcd.io/etcd/server/v3 \
		felixge:httpsnoop:v1.0.1:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		fsouza:go-dockerclient:v1.7.3:fsouza_go_dockerclient/vendor/github.com/fsouza/go-dockerclient \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-kit:kit:v0.10.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-logfmt:logfmt:v0.5.1:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:v0.1.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mod:86c51ed26bb4:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.7.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:v0.5.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.7.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.12:golang_tools/vendor/golang.org/x/tools \
		google:go-genproto:76db0878b65f:google_go_genproto/vendor/google.golang.org/genproto \
		gorilla:handlers:v1.5.1:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc:grpc-go:v1.53.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-version:v1.4.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hyperledger:fabric-amcl:2670f91851c8:hyperledger_fabric_amcl/vendor/github.com/hyperledger/fabric-amcl \
		hyperledger:fabric-chaincode-go:7bc6fa0dd58b:hyperledger_fabric_chaincode_go/vendor/github.com/hyperledger/fabric-chaincode-go \
		hyperledger:fabric-config:v0.1.0:hyperledger_fabric_config/vendor/github.com/hyperledger/fabric-config \
		hyperledger:fabric-lib-go:v1.0.0:hyperledger_fabric_lib_go/vendor/github.com/hyperledger/fabric-lib-go \
		hyperledger:fabric-protos-go:v0.2.0:hyperledger_fabric_protos_go/vendor/github.com/hyperledger/fabric-protos-go \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:pkcs11:v1.1.1:miekg_pkcs11/vendor/github.com/miekg/pkcs11 \
		mitchellh:mapstructure:v1.4.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mmcloughlin:addchain:v0.4.0:mmcloughlin_addchain/vendor/github.com/mmcloughlin/addchain \
		moby:moby:v20.10.24:moby_moby/vendor/github.com/docker/docker \
		moby:sys:mount/v0.2.0:moby_sys_mount/vendor/github.com/moby/sys \
		moby:sys:mountinfo/v0.6.2:moby_sys_mountinfo \
		moby:term:df9cb8a40635:moby_term/vendor/github.com/moby/term \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		onsi:ginkgo:v2.1.3:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		onsi:gomega:v1.19.0:onsi_gomega/vendor/github.com/onsi/gomega \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.2:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v1.1.5:opencontainers_runc/vendor/github.com/opencontainers/runc \
		pelletier:go-toml:v1.8.1:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pierrec:lz4:v2.6.0:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.11.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.3.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.8.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.28.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:cf1acfcdf475:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		rogpeppe:go-internal:v1.9.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		sirupsen:logrus:v1.9.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.3.1:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:objx:v0.5.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.8.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		sykesm:zap-logfmt:v0.0.4:sykesm_zap_logfmt/vendor/github.com/sykesm/zap-logfmt \
		syndtr:goleveldb:64b5b1c73954:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		tedsuo:ifrit:dd274de71113:tedsuo_ifrit/vendor/github.com/tedsuo/ifrit \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.6.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.19.0:uber_go_zap/vendor/go.uber.org/zap

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
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/mountinfo
	@${RLN} ${WRKSRC_moby_sys_mountinfo}/mountinfo ${WRKSRC}/vendor/github.com/moby/sys/mountinfo

.include <bsd.port.mk>
