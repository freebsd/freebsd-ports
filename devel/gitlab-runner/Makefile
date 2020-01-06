# $FreeBSD$

PORTNAME=	gitlab-runner
PORTVERSION=	12.6.0
CATEGORIES=	devel
MASTER_SITES=	https://gitlab-runner-downloads.s3.amazonaws.com/master/docker/:dockerx64 \
		https://gitlab-runner-downloads.s3.amazonaws.com/master/docker/:dockerarm
DISTFILES=	prebuilt-x86_64.tar.xz:dockerx64 \
		prebuilt-arm.tar.xz:dockerarm
DIST_SUBDIR=	gitlab-runner
EXTRACT_ONLY=	${ALLFILES:Nprebuilt*:}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Official GitLab Runner written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go-bindata:devel/go-bindata
RUN_DEPENDS=	bash:shells/bash \
		ca_root_nss>=0:security/ca_root_nss \
		git:devel/git

USES=		go:modules

USE_GITLAB=	yes
USE_GITHUB=	nodefault

# Find tags here:
# https://gitlab.com/gitlab-org/gitlab-runner/tags
GL_ACCOUNT=	gitlab-org
GL_COMMIT=	ac8e767ac77b0be4ad5dc9e6a5566a714512bba3
GITBRANCH=	12-6-stable
# https://gitlab-runner-downloads.s3.amazonaws.com/latest/binaries/gitlab-runner-freebsd-amd64
BUILT=		2019-12-22T11:55:36+0000

GH_TUPLE=	beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		go-inf:inf:v0.9.0:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-yaml:yaml:v2.2.4:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.1:golang_appengine/vendor/google.golang.org/appengine \
		google:go-genproto:c23dd37a84c9:google_go_genproto/vendor/google.golang.org/genproto \
		googleapis:google-api-go-client:v0.14.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.49.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.21.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		kubernetes:api:159aefb8556b:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:c5d2f014d689:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:01520b8320fc:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:utils:69764acb6e8e:kubernetes_utils/vendor/k8s.io/utils \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		ayufan:golang-kardianos-service:0c8eb6d8fff2:ayufan_golang_kardianos_service/vendor/github.com/ayufan/golang-kardianos-service \
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:v13.3.1:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Microsoft:go-winio:v0.4.12:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Nvveen:Gotty:cd527374f1e5:nvveen_gotty/vendor/github.com/Nvveen/Gotty \
		census-instrumentation:opencensus-go:v0.22.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		containerd:continuity:004b46473808:containerd_continuity/vendor/github.com/containerd/continuity \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		docker:cli:336b2a5cac7f:docker_cli/vendor/github.com/docker/cli \
		docker:distribution:v2.7.0:docker_distribution/vendor/github.com/docker/distribution \
		docker:docker-credential-helpers:v0.4.1:docker_docker_credential_helpers/vendor/github.com/docker/docker-credential-helpers \
		docker:engine:9552f2b2fdde:docker_engine/vendor/github.com/docker/docker \
		docker:go-connections:v0.3.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-metrics:b84716841b82:docker_go_metrics/vendor/github.com/docker/go-metrics \
		docker:go-units:eb879ae3e2b8:docker_go_units/vendor/github.com/docker/go-units \
		docker:machine:7b7a141da844:docker_machine/vendor/github.com/docker/machine \
		docker:spdystream:449fdfce4d96:docker_spdystream/vendor/github.com/docker/spdystream \
		fullsailor:pkcs7:d7302db945fa:fullsailor_pkcs7/vendor/github.com/fullsailor/pkcs7 \
		getsentry:raven-go:dffeb57df75d:getsentry_raven_go/vendor/github.com/getsentry/raven-go \
		go-ini:ini:v1.28.2:go_ini_ini/vendor/github.com/go-ini/ini \
		gogo:protobuf:v1.1.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:f99c8df09eb5:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:a1ab85dbe136:golang_exp/vendor/golang.org/x/exp \
		golang:lint:fdd1cda4f05f:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.3.1:golang_mock/vendor/github.com/golang/mock \
		golang:net:3b0461eec859:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:cbf593c0f2f3:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		golang:tools:b0650ceb63d9:golang_tools/vendor/golang.org/x/tools \
		google:gofuzz:v1.0.0:google_gofuzz/vendor/github.com/google/gofuzz \
		googleapis:gax-go:v2.0.5:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.1.0:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		gophercloud:gophercloud:e25975f29734:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gorhill:cronexpr:f0984319b442:gorhill_cronexpr/vendor/github.com/gorhill/cronexpr \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:mux:599cba5e7b61:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		hashicorp:go-version:03c5bf6be031:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		imdario:mergo:v0.3.7:imdario_mergo/vendor/github.com/imdario/mergo \
		jpillora:backoff:06c7a16c845d:jpillora_backoff/vendor/github.com/jpillora/backoff \
		json-iterator:go:v1.1.7:json_iterator_go/vendor/github.com/json-iterator/go \
		jstemmer:go-junit-report:af01ea7f8024:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		kardianos:osext:c2c54e542fb7:kardianos_osext/vendor/github.com/kardianos/osext \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kr:pty:v1.1.1:kr_pty/vendor/github.com/kr/pty \
		markelog:trie:098fa99650c0:markelog_trie/vendor/github.com/markelog/trie \
		mattn:go-zglob:v0.0.1:mattn_go_zglob/vendor/github.com/mattn/go-zglob \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		minio:minio-go:4e0f567303d4:minio_minio_go/vendor/github.com/minio/minio-go \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:c1e454b2a1bf:opencontainers_runc/vendor/github.com/opencontainers/runc \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.1.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.6.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.5:prometheus_procfs/vendor/github.com/prometheus/procfs \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:pflag:4c012f6dcd95:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:objx:v0.1.1:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.3.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tevino:abool:3c25f2fe7cd0:tevino_abool/vendor/github.com/tevino/abool \
		urfave:cli:v1.20.0:urfave_cli/vendor/github.com/urfave/cli \
		dominikh:go-tools:afd67930eec2a9ed3e9b19f684d17a062285f16a:gotools/vendor/honnef.co/go/tools \
		googleapis:google-cloud-go:264def2dd949cdb8a803bb9f50fa29a67b798a6a:googlecloudstorage/vendor/cloud.google.com/go/storage

GL_TUPLE=	ayufan:golang-cli-helpers:a7cf72d604cdf0af6031dd5d54a4e513abeff0d4:ayufan_golang_cli_helpers/vendor/gitlab.com/ayufan/golang-cli-helpers \
		gitlab-org:gitlab-terminal:5af59b871b1bcc3f4b733f6db0ff3b6e8b247b92:gitlab_org_gitlab_terminal/vendor/gitlab.com/gitlab-org/gitlab-terminal \
		steveazz:go-homedir:01701865551470435b20b226b0eafb945185b700:steveazz_go_homedir/vendor/github.com/minio/go-homedir

GO_BUILDFLAGS=	-ldflags=" \
		-X gitlab.com/gitlab-org/gitlab-runner/common.VERSION=${PORTVERSION} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.REVISION=${GL_COMMIT:C/^(........).*/\1/} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.BUILT=${BUILT} \
		-X gitlab.com/gitlab-org/gitlab-runner/common.BRANCH=${GITBRANCH} \
		-s -w"

PLIST_FILES=	bin/gitlab-runner

USE_RC_SUBR=	gitlab_runner

USERS=		gitlab-runner
GROUPS=		gitlab-runner

post-patch:
	@${MKDIR} ${WRKSRC}/out/docker/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/prebuilt-x86_64.tar.xz ${WRKSRC}/out/docker/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/prebuilt-arm.tar.xz ${WRKSRC}/out/docker/

pre-build:
	@cd ${WRKSRC} && go-bindata \
		-pkg docker \
		-nocompress \
		-nomemcopy \
		-nometadata \
		-prefix out/docker/ \
		-o executors/docker/bindata.go \
		out/docker/prebuilt-x86_64.tar.xz \
		out/docker/prebuilt-arm.tar.xz

.include <bsd.port.mk>
