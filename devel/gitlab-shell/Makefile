# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>

PORTNAME=	gitlab-shell
PORTVERSION=	13.19.1
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitLab Shell handles git commands for GitLab

LICENSE=	MIT

USES=		gmake go:modules,no_targets
MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
ALL_TARGET=	build

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-shell/tags
GL_COMMIT=	757aa7c0e0b8733c75c744f188b0136c1fe1830f

USERS=		git
GROUPS=		git

#INSTALL_TARGET=	install-strip

# for go dependencies
USE_GITHUB=	nodefault
# generated with: make gomod-vendor
# 66dd
GH_TUPLE=	\
		DataDog:datadog-go:v4.4.0:datadog_datadog_go/vendor/github.com/DataDog/datadog-go \
		DataDog:dd-trace-go:v1.30.0:datadog_dd_trace_go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		Microsoft:go-winio:v0.4.19:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		client9:reopen:v1.0.0:client9_reopen/vendor/github.com/client9/reopen \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:eec23a3978ad:golang_crypto/vendor/golang.org/x/crypto \
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
		grpc:grpc-go:v1.37.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:yamux:a95892c5f864:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		lightstep:lightstep-tracer-common:a8dfcb80d3a7:lightstep_lightstep_tracer_common_gogo/vendor/github.com/lightstep/lightstep-tracer-common \
		lightstep:lightstep-tracer-go:v0.24.0:lightstep_lightstep_tracer_go/vendor/github.com/lightstep/lightstep-tracer-go \
		mattn:go-shellwords:v1.0.11:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mikesmitty:edkey:3356ea4e686a:mikesmitty_edkey/vendor/github.com/mikesmitty/edkey \
		oklog:ulid:v2.0.2:oklog_ulid_v2/vendor/github.com/oklog/ulid/v2 \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		otiai10:copy:v1.4.2:otiai10_copy/vendor/github.com/otiai10/copy \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pires:go-proxyproto:v0.5.0:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.10.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.18.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sebest:xff:671bd2870b3a:sebest_xff/vendor/github.com/sebest/xff \
		shirou:gopsutil:v2.20.1:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tinylib:msgp:v1.1.2:tinylib_msgp/vendor/github.com/tinylib/msgp \
		uber-go:atomic:v1.5.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber:jaeger-client-go:v2.27.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v2.4.1:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib

GL_TUPLE=	gitlab-org:gitaly:e078d5bd7c5eb37caa222faa15010ce6decc6aa6:gitlab_org_gitaly_v14/vendor/gitlab.com/gitlab-org/gitaly/v14 \
		gitlab-org:labkit:b36f912635e66d2d043f57d0d2618fdc51002b87:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit

VARLOGDIR=	/var/log/gitlab-shell

PLIST_FILES+=	"@dir(git,,755) ${VARLOGDIR}"

post-patch:
	${MV} ${WRKSRC}/config.yml.example ${WRKSRC}/config.yml.sample
	${CP} ${WRKSRC}/config.yml.sample ${WRKSRC}/config.yml
	${REINPLACE_CMD} -e 's|VERSION_STRING :=.*|VERSION_STRING := v${PORTVERSION}|g' ${WRKSRC}/Makefile

pre-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} build)

pre-install:
	${RM} -rf ${WRKSRC}/config.yml
	#${RM} -rf ${WRKSRC}/go_build

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for x in .codeclimate.yml .gitignore .gitlab-ci.yml .ruby-version CHANGELOG CONTRIBUTING.md Gemfile Gemfile.lock LICENSE README.md VERSION config.yml.sample
	${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DATADIR}/
.endfor
.for x in bin spec support .gitlab
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
