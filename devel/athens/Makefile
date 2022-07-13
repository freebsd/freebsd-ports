PORTNAME=	athens
PORTVERSION=	0.11.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Proxy server for the Go Modules download API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
BUILD_DATE=	2021-05-20-00:00:00-UTC

GH_TUPLE=	gomods:${PORTNAME}:${DISTVERSIONPREFIX}${PORTVERSION}:DEFAULT \
		Azure:azure-pipeline-go:v0.2.2:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.10.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		DataDog:datadog-go:281ae9f2d895:datadog_datadog_go/vendor/github.com/DataDog/datadog-go \
		DataDog:dd-trace-go:v1.10.0:datadog_dd_trace_go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		DataDog:opencensus-go-exporter-datadog:e6c7f767dc57:datadog_opencensus_go_exporter_datadog/vendor/github.com/DataDog/opencensus-go-exporter-datadog \
		agext:levenshtein:v1.2.1:agext_levenshtein/vendor/github.com/agext/levenshtein \
		ajg:form:523a5da1a92f:ajg_form/vendor/github.com/ajg/form \
		apache:thrift:v0.12.0:apache_thrift/vendor/github.com/apache/thrift \
		apparentlymart:go-textseg:v1.0.0:apparentlymart_go_textseg/vendor/github.com/apparentlymart/go-textseg \
		aws:aws-sdk-go:v1.32.7:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:3a771d992973:beorn7_perks/vendor/github.com/beorn7/perks \
		bsm:redislock:v0.4.2:bsm_redislock/vendor/github.com/bsm/redislock \
		census-ecosystem:opencensus-go-exporter-jaeger:v0.1.0:census_ecosystem_opencensus_go_exporter_jaeger/vendor/contrib.go.opencensus.io/exporter/jaeger \
		census-ecosystem:opencensus-go-exporter-prometheus:v0.1.0:census_ecosystem_opencensus_go_exporter_prometheus/vendor/contrib.go.opencensus.io/exporter/prometheus \
		census-ecosystem:opencensus-go-exporter-stackdriver:v0.6.0:census_ecosystem_opencensus_go_exporter_stackdriver/vendor/contrib.go.opencensus.io/exporter/stackdriver \
		census-instrumentation:opencensus-go:v0.22.3:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		codegangsta:negroni:v1.0.0:codegangsta_negroni/vendor/github.com/codegangsta/negroni \
		coreos:go-systemd:39ca1b05acc7:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		coreos:pkg:3ac0863d7acf:coreos_pkg/vendor/github.com/coreos/pkg \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dominikh:go-tools:v0.0.1-2020.1.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		etcd-io:etcd:784daa04988c:etcd_io_etcd/vendor/go.etcd.io/etcd \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-playground:assert:v1.2.1:go_playground_assert/vendor/gopkg.in/go-playground/assert.v1 \
		go-playground:locales:v0.12.1:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.16.0:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v9.20.2:go_playground_validator/vendor/gopkg.in/go-playground/validator.v9 \
		go-redis:redis:v7.2.0:go_redis_redis_v7/vendor/github.com/go-redis/redis/v7 \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:v2.2.4:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:envy:v1.6.7:gobuffalo_envy/vendor/github.com/gobuffalo/envy \
		gobuffalo:httptest:v1.0.4:gobuffalo_httptest/vendor/github.com/gobuffalo/httptest \
		gogo:protobuf:v1.2.0:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:e9b2fee46413:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:6cc2880d07d6:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:910be7a94367:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.2.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:5a598a2470a0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:43a5402ce75a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:d5e6a3e2c0ae:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		golang:tools:023911ca70b2:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.1:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:0452cf42e150:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.15.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:bigquery/v1.4.0:googleapis_google_cloud_go_bigquery \
		googleapis:google-cloud-go:storage/v1.5.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.52.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:mux:v1.6.2:gorilla_mux/vendor/github.com/gorilla/mux \
		grpc:grpc-go:v1.26.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:hcl2:640445e16309:hashicorp_hcl2/vendor/github.com/hashicorp/hcl2 \
		jmespath:go-jmespath:v0.3.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		joho:godotenv:v1.3.0:joho_godotenv/vendor/github.com/joho/godotenv \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		kelseyhightower:envconfig:v1.3.0:kelseyhightower_envconfig/vendor/github.com/kelseyhightower/envconfig \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kylelemons:godebug:v1.1.0:kylelemons_godebug/vendor/github.com/kylelemons/godebug \
		lib:pq:v1.7.0:lib_pq/vendor/github.com/lib/pq \
		markbates:hmax:v1.0.0:markbates_hmax/vendor/github.com/markbates/hmax \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:6dee0af9227d:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.4:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		minio:minio-go:v6.0.43:minio_minio_go_v6/vendor/github.com/minio/minio-go/v6 \
		minio:sha256-simd:v0.1.1:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-wordwrap:ad45545899c7:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mongodb:mongo-go-driver:v1.0.0:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:3c4408c8b829:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:14fe0d1b01d4:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.2.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:bf6a532e95b1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify \
		technosophos:moniker:a5dbd03a2245:technosophos_moniker/vendor/github.com/technosophos/moniker \
		tidwall:pretty:65a9db5fad51:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tinylib:msgp:v1.0.2:tinylib_msgp/vendor/github.com/tinylib/msgp \
		uber-go:atomic:v1.3.2:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.1.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.9.1:uber_go_zap/vendor/go.uber.org/zap \
		unrolled:secure:0d6b5bb13069:unrolled_secure/vendor/github.com/unrolled/secure \
		xdg:scram:7eeb5667e42c:xdg_scram/vendor/github.com/xdg/scram \
		xdg:stringprep:v1.0.0:xdg_stringprep/vendor/github.com/xdg/stringprep \
		zclconf:go-cty:b18a157db9e2:zclconf_go_cty/vendor/github.com/zclconf/go-cty

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/bigquery
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_bigquery}/bigquery ${WRKSRC}/vendor/cloud.google.com/go/bigquery
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage

GO_TARGET=	./cmd/proxy
GO_BUILDFLAGS=	-ldflags " \
		-X github.com/gomods/${PORTNAME}/pkg/build.version=${PORTVERSION} \
		-X github.com/gomods/${PORTNAME}/pkg/build.buildDate=${BUILD_DATE}"

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/proxy ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
