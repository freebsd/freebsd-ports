# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>

PORTNAME=	gitlab-shell
PORTVERSION=	13.24.0
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitLab Shell handles git commands for GitLab

LICENSE=	MIT

USES=		gmake go:modules

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-shell/tags
GL_COMMIT=	3e853cfd74643495d4facab6c8b2fc75becdb5fe

USERS=		git
GROUPS=		git

#INSTALL_TARGET=	install-strip

# for go dependencies
USE_GITHUB=	nodefault
# generated with: make gomod-vendor
# 73dd
GH_TUPLE=	\
		DataDog:datadog-go:v4.4.0:datadog_datadog_go/vendor/github.com/DataDog/datadog-go \
		DataDog:dd-trace-go:v1.32.0:datadog_dd_trace_go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		DataDog:sketches-go:v1.0.0:datadog_sketches_go/vendor/github.com/DataDog/sketches-go \
		Microsoft:go-winio:v0.5.0:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		aws:aws-sdk-go:v1.38.35:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		census-ecosystem:opencensus-go-exporter-stackdriver:v0.13.8:census_ecosystem_opencensus_go_exporter_stackdriver/vendor/contrib.go.opencensus.io/exporter/stackdriver \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		census-instrumentation:opencensus-proto:v0.3.0:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		client9:reopen:v1.0.0:client9_reopen/vendor/github.com/client9/reopen \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:69e39bad7dc2:golang_net/vendor/golang.org/x/net \
		golang:oauth2:6f1e6394065a:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:4dd72447c267:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:time:f8bda1e9f3ba:golang_time/vendor/golang.org/x/time \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.6:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:db860fec028c:google_go_genproto/vendor/google.golang.org/genproto \
		google:pprof:f964ff605595:google_pprof/vendor/github.com/google/pprof \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.54.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.1.0:googleapis_google_cloud_go_trace/vendor/cloud.google.com/go \
		googleapis:google-cloud-go:v0.92.2:googleapis_google_cloud_go \
		grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc:grpc-go:v1.40.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:yamux:a95892c5f864:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		lightstep:lightstep-tracer-common:a8dfcb80d3a7:lightstep_lightstep_tracer_common_gogo/vendor/github.com/lightstep/lightstep-tracer-common \
		lightstep:lightstep-tracer-go:v0.25.0:lightstep_lightstep_tracer_go/vendor/github.com/lightstep/lightstep-tracer-go \
		mattn:go-shellwords:v1.0.11:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mikesmitty:edkey:3356ea4e686a:mikesmitty_edkey/vendor/github.com/mikesmitty/edkey \
		oklog:ulid:v2.0.2:oklog_ulid_v2/vendor/github.com/oklog/ulid/v2 \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		otiai10:copy:v1.4.2:otiai10_copy/vendor/github.com/otiai10/copy \
		philhofer:fwd:v1.1.1:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pires:go-proxyproto:v0.6.1:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.26.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sebest:xff:671bd2870b3a:sebest_xff/vendor/github.com/sebest/xff \
		shirou:gopsutil:v3.21.2:shirou_gopsutil_v3/vendor/github.com/shirou/gopsutil \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tinylib:msgp:v1.1.2:tinylib_msgp/vendor/github.com/tinylib/msgp \
		tklauser:go-sysconf:v0.3.4:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.2.1:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber:jaeger-client-go:v2.29.1:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.4.1:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib

GL_TUPLE=	\
		gitlab-org:gitaly:2e398afa0490ccdf5a82e1a7c7d824ae491eba16:gitlab_org_gitaly_v14/vendor/gitlab.com/gitlab-org/gitaly/v14 \
		gitlab-org:golang-crypto:5be136049a80e23e6ae1498c1303b93fb5445cf0:gitlab_org_golang_crypto/vendor/golang.org/x/crypto \
		gitlab-org:labkit:3c92d42f21ffe0f8b022626411f76fa89087464d:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit

_BUILD_DATE=	$$(date -u "+%Y-%m-%d-%H%M UTC")

GO_BUILDFLAGS=	-tags="tracer_static,tracer_static_jaeger,continuous_profiler_stackdriver" \
		-ldflags=" \
		-X 'main.Version=v${PORTVERSION}' \
		-X 'main.BuildTime=${_BUILD_DATE}'"
GO_TARGET=	./cmd/gitlab-shell \
		./cmd/gitlab-shell-authorized-keys-check \
		./cmd/gitlab-shell-authorized-principals-check \
		./cmd/gitlab-sshd \
		./cmd/check

VARLOGDIR=	/var/log/gitlab-shell

PLIST_FILES+=	"@dir(git,,755) ${VARLOGDIR}"

# 2dd
# Very custom here, easy copy not possible from go-mod-vendor
post-extract:
	${RM} -r ${WRKSRC}/vendor/cloud.google.com/go
	${MKDIR} ${WRKSRC}/vendor/cloud.google.com/go
	@${RLN} ${WRKSRC_googleapis_google_cloud_go}/profiler ${WRKSRC}/vendor/cloud.google.com/go
	${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/internal
	@${RLN} ${WRKSRC_googleapis_google_cloud_go}/internal ${WRKSRC}/vendor/cloud.google.com/go
	@${RLN} ${WRKSRC_googleapis_google_cloud_go}/compute ${WRKSRC}/vendor/cloud.google.com/go

post-patch:
	${MV} ${WRKSRC}/config.yml.example ${WRKSRC}/config.yml.sample
	${CP} ${WRKSRC}/config.yml.sample ${WRKSRC}/config.yml
	${REINPLACE_CMD} -e 's|VERSION_STRING :=.*|VERSION_STRING := v${PORTVERSION}|g' ${WRKSRC}/Makefile

pre-install:
	${RM} -rf ${WRKSRC}/config.yml

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${FIND} ${WRKSRC} -name '*.orig' -delete
	(cd ${WRKDIR}/bin/ && ${COPYTREE_BIN} .  ${STAGEDIR}${DATADIR}/bin)
.for x in CHANGELOG LICENSE README.md VERSION config.yml.sample
	${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DATADIR}/
.endfor
.for x in support
	@${MKDIR} ${STAGEDIR}${DATADIR}/${x}
	(cd ${WRKSRC}/${x} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${x})
.endfor
	@${MKDIR} ${STAGEDIR}${VARLOGDIR}

post-install:
	${FIND} -s ${STAGEDIR}${DATADIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #; \
		s#${DATADIR_REL}/bin#@(,,555) ${DATADIR_REL}/bin#; ' >> ${TMPPLIST}

.include <bsd.port.mk>
