PORTNAME=	gitaly
DISTVERSION=	14.6.3
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# Make sure the following patch is included:
# https://gitlab.com/gitlab-org/gitaly/-/merge_requests/4108
# it fixes segfaults reported here: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=259848

# define dependencies that are required for build and run under MY_DEPENDS
MY_DEPENDS=	git>=2.33.0:devel/git \
		rubygem-bundler>=2.1.4:sysutils/rubygem-bundler \
		rubygem-rugged>=1.2<2:devel/rubygem-rugged \
		rubygem-github-linguist>=7.12.1<8:textproc/rubygem-github-linguist \
		rubygem-gitlab-markup>=1.8.0<1.9.0:textproc/rubygem-gitlab-markup \
		rubygem-activesupport61>=6.1.4.1<6.1.5:devel/rubygem-activesupport61 \
		rubygem-rdoc>=6.3.2<7.0:devel/rubygem-rdoc \
		rubygem-gitlab-gollum-lib>=4.2.7.10.gitlab.1<4.2.8:www/rubygem-gitlab-gollum-lib \
		rubygem-gitlab-gollum-rugged_adapter>=0.4.4.4.gitlab.1<0.4.5.0:www/rubygem-gitlab-gollum-rugged_adapter \
		rubygem-grpc142>=1.42.0.pre1<2:net/rubygem-grpc142 \
		rubygem-sentry-raven>=3.0<4:devel/rubygem-sentry-raven \
		rubygem-faraday>=1.0.1<2:www/rubygem-faraday \
		rubygem-rbtrace>=0.4.14:devel/rubygem-rbtrace \
		rubygem-gitlab-labkit>=0.21.1<0.22:devel/rubygem-gitlab-labkit \
		rubygem-licensee>=9.14.1<9.15:devel/rubygem-licensee \
		rubygem-google-protobuf>=3.19.0<3.20:devel/rubygem-google-protobuf
BUILD_DEPENDS=	gem:devel/ruby-gems \
		bash>0:shells/bash \
		${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS} \
		gitlab-shell>=13.22.1:devel/gitlab-shell
LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cpe gmake go:modules,no_targets pkgconfig
USE_RUBY=	yes

CPE_VENDOR=	gitlab

MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
# make sure to pass go build options into make process
MAKE_ENV+=	${GO_ENV}

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find this here: https://gitlab.com/gitlab-org/gitaly/-/tags
GL_COMMIT=	b16fee14516980fedd9d67d5207cadf2165ab162

# for go dependencies
USE_GITHUB=	nodefault
# generated with: make gomod-vendor
# 137dd
GH_TUPLE=	\
		Azure:azure-pipeline-go:v0.2.3:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.13.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		Azure:go-autorest:79a63e70c4d8:azure_go_autorest_adal \
		Azure:go-autorest:autorest/v0.11.18:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:logger/v0.2.1:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		DataDog:datadog-go:v4.4.0:datadog_datadog_go/vendor/github.com/DataDog/datadog-go \
		DataDog:dd-trace-go:v1.30.0:datadog_dd_trace_go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		Microsoft:go-winio:v0.4.19:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		alexbrainman:sspi:4729b3d4d858:alexbrainman_sspi/vendor/github.com/alexbrainman/sspi \
		avast:retry-go:v2.4.2:avast_retry_go/vendor/github.com/avast/retry-go \
		aws:aws-sdk-go:v1.38.35:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		census-ecosystem:opencensus-go-exporter-stackdriver:v0.13.8:census_ecosystem_opencensus_go_exporter_stackdriver/vendor/contrib.go.opencensus.io/exporter/stackdriver \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		census-instrumentation:opencensus-proto:v0.3.0:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		client9:reopen:v1.0.0:client9_reopen/vendor/github.com/client9/reopen \
		cloudflare:tableflip:v1.2.2:cloudflare_tableflip/vendor/github.com/cloudflare/tableflip \
		containerd:cgroups:2819c83ced99:containerd_cgroups/vendor/github.com/containerd/cgroups \
		coreos:go-systemd:v22.3.1:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgryski:go-minhash:7fe510aff544:dgryski_go_minhash/vendor/github.com/dgryski/go-minhash \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		dpotapov:go-spnego:c2c609116ad0:dpotapov_go_spnego/vendor/github.com/dpotapov/go-spnego \
		ekzhu:minhash-lsh:5c06ee8586a1:ekzhu_minhash_lsh/vendor/github.com/ekzhu/minhash-lsh \
		emirpasic:gods:v1.12.0:emirpasic_gods/vendor/github.com/emirpasic/gods \
		form3tech-oss:jwt-go:v3.2.2:form3tech_oss_jwt_go/vendor/github.com/form3tech-oss/jwt-go \
		getsentry:sentry-go:v0.10.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		git-lfs:git-lfs:2e1d981afbe3:git_lfs_git_lfs/vendor/github.com/git-lfs/git-lfs \
		git-lfs:gitobj:v2.0.1:git_lfs_gitobj_v2/vendor/github.com/git-lfs/gitobj/v2 \
		git-lfs:go-netrc:e0e9ca483a18:git_lfs_go_netrc/vendor/github.com/git-lfs/go-netrc \
		git-lfs:wildmatch:v1.0.4:git_lfs_wildmatch/vendor/github.com/git-lfs/wildmatch \
		go-enry:go-license-detector:v4.3.0:go_enry_go_license_detector_v4/vendor/github.com/go-enry/go-license-detector/v4 \
		go-git:gcfg:v1.5.0:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.1.0:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.3.0:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-gorp:gorp:v1.7.2:go_gorp_gorp/vendor/gopkg.in/gorp.v1 \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		godbus:dbus:v5.0.4:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:38f3c27a63bf:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:e8c3332aa8e5:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:83fdc39ff7b5:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.4.2:golang_mod/vendor/golang.org/x/mod \
		golang:net:0714010a04ed:golang_net/vendor/golang.org/x/net \
		golang:oauth2:81ed05c6b58c:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:4dd72447c267:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:time:f8bda1e9f3ba:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cloud:v0.23.0:google_go_cloud/vendor/gocloud.dev \
		google:go-cmp:v0.5.5:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:4a47615972c2:google_go_genproto/vendor/google.golang.org/genproto \
		google:pprof:cbba55b83ad5:google_pprof/vendor/github.com/google/pprof \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		google:wire:v0.5.0:google_wire/vendor/github.com/google/wire \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.46.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:storage/v1.15.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.81.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc:grpc-go:v1.38.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-uuid:v1.0.1:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:yamux:a95892c5f864:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		hhatto:gorst:ca9f730cac5b:hhatto_gorst/vendor/github.com/hhatto/gorst \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:gokrb5:v5.3.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v5 \
		jcmturner:rpc:v0.0.2:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v0 \
		jdkato:prose:v1.1.0:jdkato_prose/vendor/github.com/jdkato/prose \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		kelseyhightower:envconfig:v1.3.0:kelseyhightower_envconfig/vendor/github.com/kelseyhightower/envconfig \
		kevinburke:ssh_config:4977a11b4351:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		lib:pq:v1.10.1:lib_pq/vendor/github.com/lib/pq \
		libgit2:git2go:v32.0.5:libgit2_git2go_v32/vendor/github.com/libgit2/git2go/v32 \
		lightstep:lightstep-tracer-common:a8dfcb80d3a7:lightstep_lightstep_tracer_common_gogo/vendor/github.com/lightstep/lightstep-tracer-common \
		lightstep:lightstep-tracer-go:v0.24.0:lightstep_lightstep_tracer_go/vendor/github.com/lightstep/lightstep-tracer-go \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		montanaflynn:stats:eeaced052adb:montanaflynn_stats/vendor/github.com/montanaflynn/stats \
		neurosnap:sentences:v1.0.6:neurosnap_sentences/vendor/gopkg.in/neurosnap/sentences.v1 \
		oklog:ulid:v2.0.2:oklog_ulid_v2/vendor/github.com/oklog/ulid/v2 \
		olekukonko:tablewriter:v0.0.2:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		olekukonko:ts:78ecb04241c0:olekukonko_ts/vendor/github.com/olekukonko/ts \
		opencontainers:runtime-spec:v1.0.2:opencontainers_runtime_spec/vendor/github.com/opencontainers/runtime-spec \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pelletier:go-toml:v1.8.1:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.10.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.18.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rubenv:sql-migrate:06338513c237:rubenv_sql_migrate/vendor/github.com/rubenv/sql-migrate \
		rubyist:tracerx:787959303086:rubyist_tracerx/vendor/github.com/rubyist/tracerx \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		sebest:xff:671bd2870b3a:sebest_xff/vendor/github.com/sebest/xff \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shirou:gopsutil:v2.20.1:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shogo82148:go-shuffle:59829097ff3b:shogo82148_go_shuffle/vendor/github.com/shogo82148/go-shuffle \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		ssgelm:cookiejarparser:v1.0.1:ssgelm_cookiejarparser/vendor/github.com/ssgelm/cookiejarparser \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tinylib:msgp:v1.1.2:tinylib_msgp/vendor/github.com/tinylib/msgp \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:goleak:v1.1.10:uber_go_goleak/vendor/go.uber.org/goleak \
		uber:jaeger-client-go:v2.27.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.4.1:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib \
		xanzy:ssh-agent:v0.3.0:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		gonum:gonum:v0.8.2:gonum/vendor/gonum.org/v1/gonum

GL_TUPLE=	gitlab-org:gitlab-shell:50da611814d256c77e689977265ec7e07633a4dc:gitlab_org_gitlab_shell/vendor/gitlab.com/gitlab-org/gitlab-shell \
		gitlab-org:labkit:397363e2404ac0276b1959373a1c1c2bc1610d67:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit

# 13dd
post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/config.toml.example
	${MV} ${WRKSRC}/config.toml.example ${WRKSRC}/config.toml.sample

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${FIND} ${WRKSRC} -name '*.orig' -delete
	${FIND} ${WRKSRC} -name "Gemfile.lock" -delete
	(cd ${WRKSRC}/_build/bin/ && ${COPYTREE_SHARE} .  ${STAGEDIR}${DATADIR}/bin && \
	cd ${WRKSRC} && ${COPYTREE_SHARE} config.toml.sample  ${STAGEDIR}${DATADIR}) && \
	cd ${WRKSRC}/ruby && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/ruby

post-install:
	${FIND} -s ${STAGEDIR}${DATADIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #; \
		/gitlab-shell-hook$$/ s#^#@(,,755) #; \
		s#${DATADIR_REL}/ruby/bin#@(,,555) ${DATADIR_REL}/ruby/bin#; \
		s#${DATADIR_REL}/bin#@(,,555) ${DATADIR_REL}/bin#; ' >> ${TMPPLIST}

.include <bsd.port.mk>


