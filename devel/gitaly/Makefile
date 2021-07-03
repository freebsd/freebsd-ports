PORTNAME=	gitaly
DISTVERSION=	14.0.2
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# define dependencies that are required for build and run under MY_DEPENDS
MY_DEPENDS=	git>=2.32.0:devel/git \
		rubygem-bundler>=2.1.4:sysutils/rubygem-bundler \
		rubygem-rugged>=1.1<2:devel/rubygem-rugged \
		rubygem-github-linguist>=7.12.1<8:textproc/rubygem-github-linguist \
		rubygem-gitlab-markup>=1.7.1<1.8.0:textproc/rubygem-gitlab-markup \
		rubygem-activesupport61>=6.0.3.6<6.2:devel/rubygem-activesupport61 \
		rubygem-rdoc>=6.1<7.0:devel/rubygem-rdoc \
		rubygem-gitlab-gollum-lib>=4.2.7.10.gitlab.1<4.2.8:www/rubygem-gitlab-gollum-lib \
		rubygem-gitlab-gollum-rugged_adapter>=0.4.4.4.gitlab.1<0.4.5.0:www/rubygem-gitlab-gollum-rugged_adapter \
		rubygem-grpc>=1.30.2<2:net/rubygem-grpc \
		rubygem-sentry-raven>=3.0<4:devel/rubygem-sentry-raven \
		rubygem-faraday>=1.0.1<2:www/rubygem-faraday \
		rubygem-rbtrace>=0.4.14:devel/rubygem-rbtrace \
		rubygem-gitlab-labkit>=0.18<0.19:devel/rubygem-gitlab-labkit \
		rubygem-licensee>=9.14.1<9.15:devel/rubygem-licensee \
		rubygem-google-protobuf>=3.17.3<3.18:devel/rubygem-google-protobuf
BUILD_DEPENDS=	gem:devel/ruby-gems \
		bash>0:shells/bash \
		${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS} \
		gitlab-shell>=9.3.0:devel/gitlab-shell
LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		gmake go:modules,no_targets pkgconfig
USE_RUBY=	yes

MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
# make sure to pass go build options into make process
MAKE_ENV+=	${GO_ENV}

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find this here: https://gitlab.com/gitlab-org/gitaly/-/tags
GL_COMMIT=	34dc9341390a799d67b5d0dbc7f0adaf5954f672

# for go dependencies
USE_GITHUB=	nodefault
# generated with: make gomod-vendor
# 97dd
GH_TUPLE=	\
		DataDog:datadog-go:v4.4.0:datadog_datadog_go/vendor/github.com/DataDog/datadog-go \
		DataDog:dd-trace-go:v1.30.0:datadog_dd_trace_go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		Microsoft:go-winio:v0.4.19:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		alexbrainman:sspi:4729b3d4d858:alexbrainman_sspi/vendor/github.com/alexbrainman/sspi \
		avast:retry-go:v2.4.2:avast_retry_go/vendor/github.com/avast/retry-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		client9:reopen:v1.0.0:client9_reopen/vendor/github.com/client9/reopen \
		cloudflare:tableflip:v1.2.2:cloudflare_tableflip/vendor/github.com/cloudflare/tableflip \
		containerd:cgroups:2819c83ced99:containerd_cgroups/vendor/github.com/containerd/cgroups \
		coreos:go-systemd:v22.0.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		dpotapov:go-spnego:c2c609116ad0:dpotapov_go_spnego/vendor/github.com/dpotapov/go-spnego \
		getsentry:sentry-go:v0.10.0:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		git-lfs:git-lfs:2e1d981afbe3:git_lfs_git_lfs/vendor/github.com/git-lfs/git-lfs \
		git-lfs:gitobj:v2.0.1:git_lfs_gitobj_v2/vendor/github.com/git-lfs/gitobj/v2 \
		git-lfs:go-netrc:e0e9ca483a18:git_lfs_go_netrc/vendor/github.com/git-lfs/go-netrc \
		git-lfs:wildmatch:v1.0.4:git_lfs_wildmatch/vendor/github.com/git-lfs/wildmatch \
		go-gorp:gorp:v1.7.2:go_gorp_gorp/vendor/gopkg.in/gorp.v1 \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		godbus:dbus:v5.0.3:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:be400aefbc4c:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:83fdc39ff7b5:golang_lint/vendor/golang.org/x/lint \
		golang:net:d523dce5a7f4:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5e61552d6c78:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:f1c623a9e750:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.5:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:c14fb6ef47c3:google_go_genproto/vendor/google.golang.org/genproto \
		google:pprof:cbba55b83ad5:google_pprof/vendor/github.com/google/pprof \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.45.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.81.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc:grpc-go:v1.38.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-uuid:v1.0.1:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:yamux:a95892c5f864:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:gokrb5:v5.3.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v5 \
		jcmturner:rpc:v0.0.2:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v0 \
		kelseyhightower:envconfig:v1.3.0:kelseyhightower_envconfig/vendor/github.com/kelseyhightower/envconfig \
		lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
		libgit2:git2go:v31.4.12:libgit2_git2go_v31/vendor/github.com/libgit2/git2go/v31 \
		lightstep:lightstep-tracer-common:a8dfcb80d3a7:lightstep_lightstep_tracer_common_gogo/vendor/github.com/lightstep/lightstep-tracer-common \
		lightstep:lightstep-tracer-go:v0.24.0:lightstep_lightstep_tracer_go/vendor/github.com/lightstep/lightstep-tracer-go \
		mattn:go-isatty:v0.0.9:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		oklog:ulid:v2.0.2:oklog_ulid_v2/vendor/github.com/oklog/ulid/v2 \
		olekukonko:tablewriter:v0.0.2:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		olekukonko:ts:78ecb04241c0:olekukonko_ts/vendor/github.com/olekukonko/ts \
		opencontainers:runtime-spec:v1.0.2:opencontainers_runtime_spec/vendor/github.com/opencontainers/runtime-spec \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		otiai10:curr:v1.0.0:otiai10_curr/vendor/github.com/otiai10/curr \
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
		sebest:xff:671bd2870b3a:sebest_xff/vendor/github.com/sebest/xff \
		shirou:gopsutil:v2.20.1:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		ssgelm:cookiejarparser:v1.0.1:ssgelm_cookiejarparser/vendor/github.com/ssgelm/cookiejarparser \
		stretchr:objx:v0.1.1:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tinylib:msgp:v1.1.2:tinylib_msgp/vendor/github.com/tinylib/msgp \
		uber-go:atomic:v1.5.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:goleak:v1.1.10:uber_go_goleak/vendor/go.uber.org/goleak \
		uber:jaeger-client-go:v2.27.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.4.1:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib

GL_TUPLE=	gitlab-org:gitlab-shell:3f9890ef73dced430d86801a1efc0e93ec50890e:gitlab_org_gitlab_shell/vendor/gitlab.com/gitlab-org/gitlab-shell \
		gitlab-org:labkit:bdc29f9e957c46d7b0a4747a4662879c7189bf08:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit

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

.include <bsd.port.mk>

