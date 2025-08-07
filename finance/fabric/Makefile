PORTNAME=	fabric
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
PORTREVISION=	7
CATEGORIES=	finance
PKGNAMESUFFIX=	-hyperledger

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Enterprise-grade permissioned distributed ledger framework
WWW=		https://wiki.hyperledger.org/display/fabric

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc # compilation fails on non-64-bit systems: fabric-amcl/core/FP256BN/FP.go:111:19: cannot convert MConst (constant 30564559323915749 of type Chunk) to type int

USES=		go:1.23,modules
USE_GITHUB=	yes
GH_ACCOUNT=	hyperledger

# the upstream claims that it is too difficult to add the /v2 suffix to the GoLang module URL: https://github.com/hyperledger/fabric/issues/2929
GH_TUPLE=	\
		AdaLogics:go-fuzz-headers:ced1acdcaa24:adalogics_go_fuzz_headers/vendor/github.com/AdaLogics/go-fuzz-headers \
		Azure:go-ansiterm:d185dfc1b5a1:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		IBM:idemix:72941a5f41cd:ibm_idemix/vendor/github.com/IBM/idemix \
		IBM:mathlib:44ee0eb539da:ibm_mathlib/vendor/github.com/IBM/mathlib \
		Knetic:govaluate:9aa49832a739:knetic_govaluate/vendor/github.com/Knetic/govaluate \
		Microsoft:go-winio:v0.6.1:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.11.4:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		VictoriaMetrics:fastcache:v1.9.0:victoriametrics_fastcache/vendor/github.com/VictoriaMetrics/fastcache \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:61d1e3462e30:alecthomas_units/vendor/github.com/alecthomas/units \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bits-and-blooms:bitset:v1.13.0:bits_and_blooms_bitset/vendor/github.com/bits-and-blooms/bitset \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheggaaa:pb:v1.0.29:cheggaaa_pb/vendor/github.com/cheggaaa/pb \
		cloudfoundry:clock:v1.0.0:cloudfoundry_clock/vendor/code.cloudfoundry.org/clock \
		consensys:bavard:v0.1.13:consensys_bavard/vendor/github.com/consensys/bavard \
		consensys:gnark-crypto:v0.13.0:consensys_gnark_crypto/vendor/github.com/consensys/gnark-crypto \
		containerd:containerd:v1.6.26:containerd_containerd/vendor/github.com/containerd/containerd \
		containerd:log:v0.1.0:containerd_log/vendor/github.com/containerd/log \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.5.0:docker_go_units/vendor/github.com/docker/go-units \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		etcd-io:etcd:v3.5.14:etcd_io_etcd/vendor/go.etcd.io/etcd/client/pkg/v3 \
		felixge:httpsnoop:v1.0.1:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fsnotify:fsnotify:v1.7.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		fsouza:go-dockerclient:v1.10.0:fsouza_go_dockerclient/vendor/github.com/fsouza/go-dockerclient \
		go-kit:kit:v0.10.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-logfmt:logfmt:v0.5.1:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-logr:logr:v1.4.2:go_logr_logr/vendor/github.com/go-logr/logr \
		go-task:slim-sprig:v3.0.0:go_task_slim_sprig_v3/vendor/github.com/go-task/slim-sprig/v3 \
		go-viper:mapstructure:v2.0.0:go_viper_mapstructure_v2/vendor/github.com/go-viper/mapstructure/v2 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:v0.26.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.20.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.28.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:v0.8.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.24.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.17.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.24.0:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.6.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:ef581f913117:google_go_genproto/vendor/google.golang.org/genproto/googleapis/rpc \
		google:pprof:fa2c70bbbfe5:google_pprof/vendor/github.com/google/pprof \
		gorilla:handlers:v1.5.1:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc:grpc-go:v1.66.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hyperledger-labs:SmartBFT:852e5be5889b:hyperledger_labs_smartbft/vendor/github.com/hyperledger-labs/SmartBFT \
		hyperledger:aries-bbs-go:761671ea73bc:hyperledger_aries_bbs_go/vendor/github.com/hyperledger/aries-bbs-go \
		hyperledger:fabric-amcl:9e02669dceb2:hyperledger_fabric_amcl/vendor/github.com/hyperledger/fabric-amcl \
		hyperledger:fabric-chaincode-go:v2.0.0:hyperledger_fabric_chaincode_go_v2/vendor/github.com/hyperledger/fabric-chaincode-go/v2 \
		hyperledger:fabric-config:v0.3.0:hyperledger_fabric_config/vendor/github.com/hyperledger/fabric-config \
		hyperledger:fabric-lib-go:25edd1eaf5f5:hyperledger_fabric_lib_go/vendor/github.com/hyperledger/fabric-lib-go \
		hyperledger:fabric-protos-go-apiv2:v0.3.3:hyperledger_fabric_protos_go_apiv2/vendor/github.com/hyperledger/fabric-protos-go-apiv2 \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kilic:bls12-381:v0.1.0:kilic_bls12_381/vendor/github.com/kilic/bls12-381 \
		klauspost:compress:v1.17.6:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:pkcs11:v1.1.1:miekg_pkcs11/vendor/github.com/miekg/pkcs11 \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mmcloughlin:addchain:v0.4.0:mmcloughlin_addchain/vendor/github.com/mmcloughlin/addchain \
		moby:docker-image-spec:v1.3.1:moby_docker_image_spec/vendor/github.com/moby/docker-image-spec \
		moby:moby:v26.1.5:moby_moby/vendor/github.com/docker/docker \
		moby:patternmatcher:v0.6.0:moby_patternmatcher/vendor/github.com/moby/patternmatcher \
		moby:sys:sequential/v0.5.0:moby_sys_sequential \
		moby:sys:user/v0.1.0:moby_sys_user/vendor/github.com/moby/sys \
		moby:term:3f7ff695adc6:moby_term/vendor/github.com/moby/term \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		onsi:ginkgo:v2.20.2:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		onsi:gomega:v1.34.2:onsi_gomega/vendor/github.com/onsi/gomega \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.1.0-rc6:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		pelletier:go-toml:v2.2.2:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.11.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.3.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.8.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.34.2:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rogpeppe:go-internal:v1.11.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rsc:tmplfunc:v0.0.3:rsc_tmplfunc/vendor/rsc.io/tmplfunc \
		sagikazarmark:locafero:v0.6.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.11.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cobra:v1.5.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.20.0-alpha.6:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:objx:v0.5.2:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.9.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		sykesm:zap-logfmt:v0.0.4:sykesm_zap_logfmt/vendor/github.com/sykesm/zap-logfmt \
		syndtr:goleveldb:64b5b1c73954:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		tedsuo:ifrit:dd274de71113:tedsuo_ifrit/vendor/github.com/tedsuo/ifrit \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.27.0:uber_go_zap/vendor/go.uber.org/zap

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
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/sequential
	@${RLN} ${WRKSRC_moby_sys_sequential}/sequential ${WRKSRC}/vendor/github.com/moby/sys/sequential
	@${MKDIR} ${WRKSRC}/vendor/github.com/spf13
	@${RLN} ${WRKSRC_fsnotify_fsnotify} ${WRKSRC}/vendor/github.com/spf13/cast

.include <bsd.port.mk>
