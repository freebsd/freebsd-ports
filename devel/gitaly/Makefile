# $FreeBSD$

PORTNAME=	gitaly
DISTVERSION=	13.5.4
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# define dependencies that are required for build and run under MY_DEPENDS
MY_DEPENDS=	git>=2.28:devel/git \
		rubygem-bundler>=1.17.3:sysutils/rubygem-bundler \
		rubygem-rugged>=0.28:devel/rubygem-rugged \
		rubygem-github-linguist>=7.11<8.0:textproc/rubygem-github-linguist \
		rubygem-gitlab-markup>=1.7.1<1.8.0:textproc/rubygem-gitlab-markup \
		rubygem-activesupport60>=6.0.3.3<6.0.4:devel/rubygem-activesupport60 \
		rubygem-rdoc>=6.1<7.0:devel/rubygem-rdoc \
		rubygem-gitlab-gollum-lib>=4.2.7.9<4.2.8:www/rubygem-gitlab-gollum-lib \
		rubygem-gitlab-gollum-rugged_adapter>=0.4.4.2<0.4.5.0:www/rubygem-gitlab-gollum-rugged_adapter \
		rubygem-grpc>=1.30.2<1.31:net/rubygem-grpc \
		rubygem-sentry-raven>=3.0<4:devel/rubygem-sentry-raven \
		rubygem-faraday>=1.0.1<2:www/rubygem-faraday \
		rubygem-rbtrace>=0.4.14:devel/rubygem-rbtrace \
		rubygem-gitlab-labkit>=0.12.1<0.13:devel/rubygem-gitlab-labkit \
		rubygem-licensee8>=8.9.0<8.10.0:devel/rubygem-licensee8 \
		rubygem-google-protobuf>=3.12.0<4:devel/rubygem-google-protobuf
BUILD_DEPENDS=	gem:devel/ruby-gems \
		bash>0:shells/bash \
		${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS} \
		gitlab-shell>=9.3.0:devel/gitlab-shell
LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		gmake go:modules,no_targets pkgconfig
USE_RUBY=	yes

MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find this here: https://gitlab.com/gitlab-org/gitaly/-/tags
GL_COMMIT=	17bea8a2e504e3ef94101fe8c9356c7e406c988e

# for go dependencies
USE_GITHUB=	nodefault
# generated with: make gomod-vendor
# 74dd
GH_TUPLE=	\
		DataDog:dd-trace-go:v1.7.0:datadog_dd_trace_go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		alexbrainman:sspi:4729b3d4d858:alexbrainman_sspi/vendor/github.com/alexbrainman/sspi \
		avast:retry-go:v2.4.2:avast_retry_go/vendor/github.com/avast/retry-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		client9:reopen:v1.0.0:client9_reopen/vendor/github.com/client9/reopen \
		cloudflare:tableflip:4baec9811f2b:cloudflare_tableflip/vendor/github.com/cloudflare/tableflip \
		HdrHistogram:hdrhistogram-go:3a0bb77429bd:codahale_hdrhistogram_go/vendor/github.com/codahale/hdrhistogram \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dpotapov:go-spnego:c2c609116ad0:dpotapov_go_spnego/vendor/github.com/dpotapov/go-spnego \
		getsentry:sentry-go:v0.5.1:getsentry_sentry_go/vendor/github.com/getsentry/sentry-go \
		git-lfs:git-lfs:9ea4eed5b112:git_lfs_git_lfs/vendor/github.com/git-lfs/git-lfs \
		git-lfs:gitobj:v2.0.0:git_lfs_gitobj_v2/vendor/github.com/git-lfs/gitobj/v2 \
		git-lfs:go-netrc:e0e9ca483a18:git_lfs_go_netrc/vendor/github.com/git-lfs/go-netrc \
		git-lfs:go-ntlm:c5056e7fa066:git_lfs_go_ntlm/vendor/github.com/git-lfs/go-ntlm \
		git-lfs:wildmatch:v1.0.4:git_lfs_wildmatch/vendor/github.com/git-lfs/wildmatch \
		go-gorp:gorp:v1.7.2:go_gorp_gorp/vendor/gopkg.in/gorp.v1 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:5c72a883971a:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:215e87163ea7:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:62affa334b73:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:6e8e738ad208:golang_sync/vendor/golang.org/x/sync \
		golang:sys:af09f7315aff:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		google:go-genproto:ca5a22157cba:google_go_genproto/vendor/google.golang.org/genproto \
		google:pprof:d4f498aebedc:google_pprof/vendor/github.com/google/pprof \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.15.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.50.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc-ecosystem:go-grpc-middleware:v1.0.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc:grpc-go:v1.24.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:gokrb5:v5.3.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v5 \
		jcmturner:rpc:v0.0.2:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v0 \
		kelseyhightower:envconfig:v1.3.0:kelseyhightower_envconfig/vendor/github.com/kelseyhightower/envconfig \
		konsorten:go-windows-terminal-sequences:v1.0.3:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
		libgit2:git2go:v30.0.5:libgit2_git2go_v30/vendor/github.com/libgit2/git2go/v30 \
		lightstep:lightstep-tracer-go:v0.15.6:lightstep_lightstep_tracer_go/vendor/github.com/lightstep/lightstep-tracer-go \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		olekukonko:tablewriter:v0.0.2:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		olekukonko:ts:78ecb04241c0:olekukonko_ts/vendor/github.com/olekukonko/ts \
		opentracing:opentracing-go:v1.0.2:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pelletier:go-toml:v1.8.1:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.0.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:14fe0d1b01d4:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.4.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		rubenv:sql-migrate:06338513c237:rubenv_sql_migrate/vendor/github.com/rubenv/sql-migrate \
		rubyist:tracerx:787959303086:rubyist_tracerx/vendor/github.com/rubyist/tracerx \
		sebest:xff:6c115e0ffa35:sebest_xff/vendor/github.com/sebest/xff \
		sirupsen:logrus:v1.6.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		ssgelm:cookiejarparser:v1.0.1:ssgelm_cookiejarparser/vendor/github.com/ssgelm/cookiejarparser \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tinylib:msgp:v1.1.0:tinylib_msgp/vendor/github.com/tinylib/msgp \
		uber:jaeger-client-go:v2.15.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v1.5.0:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib

GL_TUPLE=	gitlab-org:gitlab-shell:1a2bfecd2f0ebb8e31f9833e0522c4643797041b:gitlab_org_gitlab_shell/vendor/gitlab.com/gitlab-org/gitlab-shell \
		gitlab-org:labkit:45895e1290291a2519678a847a24edb22880b9e6:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/config.toml.example
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/ruby/gitlab-shell/config.yml.example
	${MV} ${WRKSRC}/config.toml.example ${WRKSRC}/config.toml.sample
	${MV} ${WRKSRC}/ruby/gitlab-shell/config.yml.example ${WRKSRC}/ruby/gitlab-shell/config.yml.sample

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${FIND} ${WRKSRC} -name '*.orig' -delete
	${FIND} ${WRKSRC} -name "Gemfile.lock" -delete
	(cd ${WRKSRC}/_build/bin/ && ${COPYTREE_SHARE} .  ${STAGEDIR}${DATADIR}/bin && \
	cd ${WRKSRC} && ${COPYTREE_SHARE} config.toml.sample  ${STAGEDIR}${DATADIR}) && \
	cd ${WRKSRC}/ruby && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/ruby

.include <bsd.port.mk>
