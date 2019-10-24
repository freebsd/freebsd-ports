# $FreeBSD$

PORTNAME=	gitaly
DISTVERSION=	1.67.0
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# define dependencies that are required for build and run under MY_DEPENDS
MY_DEPENDS=	git>=2.21:devel/git \
		rubygem-bundler>=1.17.3:sysutils/rubygem-bundler \
		rubygem-rugged>=0.28<1.0:devel/rubygem-rugged \
		rubygem-github-linguist>=6.1<7.0:textproc/rubygem-github-linguist \
		rubygem-gitlab-markup>=1.7.0<1.8.0:textproc/rubygem-gitlab-markup \
		rubygem-activesupport52>=5.2.3<5.3.0:devel/rubygem-activesupport52 \
		rubygem-rdoc>=6.0:devel/rubygem-rdoc \
		rubygem-gitlab-gollum-lib>=4.2.7.7<4.2.8.0:www/rubygem-gitlab-gollum-lib \
		rubygem-gitlab-gollum-rugged_adapter>=0.4.4.2<0.4.5.0:www/rubygem-gitlab-gollum-rugged_adapter \
		rubygem-grpc>=1.19.0<1.20.0:net/rubygem-grpc \
		rubygem-sentry-raven>=2.9.0<2.10.0:devel/rubygem-sentry-raven \
		rubygem-faraday>=0.12<1.0:www/rubygem-faraday \
		rubygem-rbtrace>0:devel/rubygem-rbtrace \
		rubygem-gitlab-labkit>=0.5.0<0.6.0:devel/rubygem-gitlab-labkit \
		rubygem-licensee8>=8.9.0<8.10.0:devel/rubygem-licensee8 \
		rubygem-google-protobuf371>=3.7.1<3.8.0:devel/rubygem-google-protobuf371
BUILD_DEPENDS=	gem:devel/ruby-gems \
		${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS} \
		gitlab-shell>=9.3.0:devel/gitlab-shell

USES=		gmake go:modules,no_targets
USE_RUBY=	yes

MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find this here: https://gitlab.com/gitlab-org/gitaly/tags
GL_COMMIT=	ca21a624582be7bcf4d43075be2a7e5981e191fa

# for go dependencies
USE_GITHUB=	nodefault
# generated with: make gomod-vendor
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		DataDog:dd-trace-go:v1.7.0:datadog_dd_trace_go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		certifi:gocertifi:ee1a9a0726d2:certifi_gocertifi/vendor/github.com/certifi/gocertifi \
		cloudflare:tableflip:8392f1641731:cloudflare_tableflip/vendor/github.com/cloudflare/tableflip \
		codahale:hdrhistogram:3a0bb77429bd:codahale_hdrhistogram/vendor/github.com/codahale/hdrhistogram \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		getsentry:raven-go:v0.1.2:getsentry_raven_go/vendor/github.com/getsentry/raven-go \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:20be4c3c3ed5:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:d28f0bde5980:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:37e7f081c4d4:golang_sync/vendor/golang.org/x/sync \
		golang:sys:953cdadca894:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		google:go-genproto:bd91e49a0898:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		grpc-ecosystem:go-grpc-middleware:v1.0.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc:grpc-go:v1.16.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		kelseyhightower:envconfig:v1.3.0:kelseyhightower_envconfig/vendor/github.com/kelseyhightower/envconfig \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		libgit2:git2go:ecaeb7a21d47:libgit2_git2go/vendor/github.com/libgit2/git2go \
		lightstep:lightstep-tracer-go:v0.15.6:lightstep_lightstep_tracer_go/vendor/github.com/lightstep/lightstep-tracer-go \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		opentracing:opentracing-go:v1.0.2:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.0.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.4.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.2:prometheus_procfs/vendor/github.com/prometheus/procfs \
		sirupsen:logrus:v1.2.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.3.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tinylib:msgp:v1.1.0:tinylib_msgp/vendor/github.com/tinylib/msgp \
		uber:jaeger-client-go:v2.15.0:uber_jaeger_client_go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v1.5.0:uber_jaeger_lib/vendor/github.com/uber/jaeger-lib
GL_TUPLE=	\
		gitlab-org:labkit:0c3fc7cdd57c57da5ab474aa72b6640d2bdc9ebb:gitlab_org_labkit/vendor/gitlab.com/gitlab-org/labkit

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

