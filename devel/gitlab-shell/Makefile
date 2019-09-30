# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-shell
PORTVERSION=	10.0.0
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitLab Shell handles git commands for GitLab

LICENSE=	MIT

BUILD_DEPENDS=	gem:devel/ruby-gems

USES=		gmake go:modules,no_targets
MAKE_ENV=	GOFLAGS="${GO_BUILDFLAGS}"
ALL_TARGET=	build

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find the commit hash here: https://gitlab.com/gitlab-org/gitlab-shell/tags
GL_COMMIT=	996b2e1d44cc671cc60fd4ddacd2c5750b72a025

USERS=		git
GROUPS=		git

INSTALL_TARGET=	install-strip

# for go dependencies
USE_GITHUB=	nodefault
# generated with gomod-deps below
GH_TUPLE=	\
		DataDog:dd-trace-go:v1.9.0:datadog_dd_trace_go/go/vendor/gopkg.in/DataDog/dd-trace-go.v1 \
		codahale:hdrhistogram:3a0bb77429bd:codahale_hdrhistogram/go/vendor/github.com/codahale/hdrhistogram \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/go/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:v2.2.1:go_yaml_yaml/go/vendor/gopkg.in/yaml.v2 \
		golang:crypto:182114d58262:golang_crypto/go/vendor/golang.org/x/crypto \
		golang:net:10aee1819953:golang_net/go/vendor/golang.org/x/net \
		golang:protobuf:v1.2.0:golang_protobuf/go/vendor/github.com/golang/protobuf \
		golang:sys:70b957f3b65e:golang_sys/go/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/go/vendor/golang.org/x/text \
		google:go-genproto:bd91e49a0898:google_go_genproto/go/vendor/google.golang.org/genproto \
		grpc-ecosystem:go-grpc-middleware:v1.0.0:grpc_ecosystem_go_grpc_middleware/go/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc:grpc-go:v1.16.0:grpc_grpc_go/go/vendor/google.golang.org/grpc \
		lightstep:lightstep-tracer-go:v0.15.6:lightstep_lightstep_tracer_go/go/vendor/github.com/lightstep/lightstep-tracer-go \
		mattn:go-shellwords:2444a32a19f4:mattn_go_shellwords/go/vendor/github.com/mattn/go-shellwords \
		opentracing:opentracing-go:v1.0.2:opentracing_opentracing_go/go/vendor/github.com/opentracing/opentracing-go \
		otiai10:copy:v1.0.1:otiai10_copy/go/vendor/github.com/otiai10/copy \
		philhofer:fwd:v1.0.0:philhofer_fwd/go/vendor/github.com/philhofer/fwd \
		pkg:errors:v0.8.0:pkg_errors/go/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/go/vendor/github.com/pmezard/go-difflib \
		sirupsen:logrus:v1.0.5:sirupsen_logrus/go/vendor/github.com/sirupsen/logrus \
		stretchr:testify:v1.2.2:stretchr_testify/go/vendor/github.com/stretchr/testify \
		tinylib:msgp:v1.0.2:tinylib_msgp/go/vendor/github.com/tinylib/msgp \
		uber:jaeger-client-go:v2.15.0:uber_jaeger_client_go/go/vendor/github.com/uber/jaeger-client-go \
		uber:jaeger-lib:v1.5.0:uber_jaeger_lib/go/vendor/github.com/uber/jaeger-lib
GL_TUPLE=	\
		gitlab-org:gitaly-proto:53d58cd1f691f0370aca152927db89a6b6fbab59:gitlab_org_gitaly_proto/go/vendor/gitlab.com/gitlab-org/gitaly-proto \
		gitlab-org:gitaly:52d67af596f75e82305f16ff0f27a9e0e77d57e1:gitlab_org_gitaly/go/vendor/gitlab.com/gitlab-org/gitaly \
		gitlab-org:labkit:0c3fc7cdd57c57da5ab474aa72b6640d2bdc9ebb:gitlab_org_labkit/go/vendor/gitlab.com/gitlab-org/labkit

post-patch:
	${MV} ${WRKSRC}/config.yml.example ${WRKSRC}/config.yml.sample
	${CP} ${WRKSRC}/config.yml.sample ${WRKSRC}/config.yml

# Build the go deps, use `pkg install modules2tuple`
gomod-deps: patch
	(cd ${WRKSRC}/go && go mod vendor)
	(cd ${WRKSRC}/go && modules2tuple vendor/modules.txt)

#export GOCACHE=${WRKSRC}/go && ${WRKSRC}/bin/compile
pre-build:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} bin/compile)
	@(cd ${WRKSRC}; ${MAKE_CMD} build)
	@(cd ${WRKSRC}; ${MAKE_CMD} compile)

pre-install:
	${RM} -rf ${WRKSRC}/config.yml
	#${RM} -rf ${WRKSRC}/go_build

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for x in .codeclimate.yml .gitignore .gitlab-ci.yml .rubocop.yml .ruby-version CHANGELOG CONTRIBUTING.md Gemfile Gemfile.lock LICENSE README.md VERSION config.yml.sample
	${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DATADIR}/
.endfor
.for x in bin spec lib hooks support .gitlab
	@${MKDIR} ${STAGEDIR}${DATADIR}/${x}
	(cd ${WRKSRC}/${x} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${x})
.endfor

	@${MKDIR} ${STAGEDIR}/var/log/gitlab-shell

.include <bsd.port.mk>
