# $FreeBSD$

PORTNAME=	gitlab-runner
PORTVERSION=	13.5.0
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
GL_COMMIT=	ece8634382223b250b259534ed398d2c125b9911
GITBRANCH=	13-5-stable
# https://gitlab-runner-downloads.s3.amazonaws.com/latest/binaries/gitlab-runner-freebsd-amd64
BUILT=		2020-10-20T12:05:24+0000

GH_TUPLE=	\
		Azure:azure-pipeline-go:v0.2.2:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.10.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:5bd9621f41a0:azure_go_autorest_date/vendor/github.com/Azure/go-autorest \
		Azure:go-autorest:autorest/v0.9.2:azure_go_autorest_autorest \
		Azure:go-autorest:e727cfcfc902:azure_go_autorest_adal \
		Azure:go-autorest:logger/v0.1.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.5.0:azure_go_autorest_tracing \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Microsoft:go-winio:v0.4.12:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Nvveen:Gotty:cd527374f1e5:nvveen_gotty/vendor/github.com/Nvveen/Gotty \
		ayufan:golang-kardianos-service:0c8eb6d8fff2:ayufan_golang_kardianos_service/vendor/github.com/ayufan/golang-kardianos-service \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bmatcuk:doublestar:v1.3.0:bmatcuk_doublestar/vendor/github.com/bmatcuk/doublestar \
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
		dominikh:go-tools:v0.0.1-2019.2.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		fullsailor:pkcs7:d7302db945fa:fullsailor_pkcs7/vendor/github.com/fullsailor/pkcs7 \
		getsentry:raven-go:dffeb57df75d:getsentry_raven_go/vendor/github.com/getsentry/raven-go \
		go-inf:inf:v0.9.0:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.52.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.1.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.1:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:2aa609cf4a9d:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:a1ab85dbe136:golang_exp/vendor/golang.org/x/exp \
		golang:lint:fdd1cda4f05f:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.3.1:golang_mock/vendor/github.com/golang/mock \
		golang:net:5a598a2470a0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:d5e6a3e2c0ae:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		golang:tools:345141a36859:golang_tools/vendor/golang.org/x/tools \
		google:go-genproto:c23dd37a84c9:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.0.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.1.0:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.14.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:storage/v1.0.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.49.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gophercloud:gophercloud:e25975f29734:gophercloud_gophercloud/vendor/github.com/gophercloud/gophercloud \
		gorhill:cronexpr:f0984319b442:gorhill_cronexpr/vendor/github.com/gorhill/cronexpr \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:mux:599cba5e7b61:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.22.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.5.4:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.1:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-version:v1.2.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:vault:api/v1.0.4:hashicorp_vault_api/vendor/github.com/hashicorp/vault \
		hashicorp:vault:sdk/v0.1.13:hashicorp_vault_sdk \
		imdario:mergo:v0.3.7:imdario_mergo/vendor/github.com/imdario/mergo \
		jpillora:backoff:06c7a16c845d:jpillora_backoff/vendor/github.com/jpillora/backoff \
		json-iterator:go:v1.1.7:json_iterator_go/vendor/github.com/json-iterator/go \
		jstemmer:go-junit-report:af01ea7f8024:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		kardianos:osext:c2c54e542fb7:kardianos_osext/vendor/github.com/kardianos/osext \
		klauspost:compress:v1.10.5:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:pgzip:v1.2.3:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kr:pty:v1.1.1:kr_pty/vendor/github.com/kr/pty \
		kubernetes-sigs:yaml:v1.1.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:159aefb8556b:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:c5d2f014d689:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:01520b8320fc:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v1.0.0:kubernetes_klog/vendor/k8s.io/klog \
		kubernetes:utils:69764acb6e8e:kubernetes_utils/vendor/k8s.io/utils \
		markelog:trie:098fa99650c0:markelog_trie/vendor/github.com/markelog/trie \
		mattn:go-ieproxy:6dee0af9227d:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		minio:minio-go:v6.0.49:minio_minio_go_v6/vendor/github.com/minio/minio-go/v6 \
		minio:sha256-simd:v0.1.1:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:gox:v1.0.1:mitchellh_gox/vendor/github.com/mitchellh/gox \
		mitchellh:iochan:v1.0.0:mitchellh_iochan/vendor/github.com/mitchellh/iochan \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:c1e454b2a1bf:opencontainers_runc/vendor/github.com/opencontainers/runc \
		pierrec:lz4:v2.0.5:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.1.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.6.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.5:prometheus_procfs/vendor/github.com/prometheus/procfs \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:pflag:4c012f6dcd95:spf13_pflag/vendor/github.com/spf13/pflag \
		square:go-jose:v2.3.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:objx:v0.3.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tevino:abool:3c25f2fe7cd0:tevino_abool/vendor/github.com/tevino/abool \
		urfave:cli:v1.20.0:urfave_cli/vendor/github.com/urfave/cli

GL_TUPLE=	ayufan:golang-cli-helpers:a7cf72d604cdf0af6031dd5d54a4e513abeff0d4:ayufan_golang_cli_helpers/vendor/gitlab.com/ayufan/golang-cli-helpers \
		gitlab-org:gitlab-terminal:5af59b871b1bcc3f4b733f6db0ff3b6e8b247b92:gitlab_org_gitlab_terminal/vendor/gitlab.com/gitlab-org/gitlab-terminal

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

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/vault/sdk
	@${RLN} ${WRKSRC_hashicorp_vault_sdk}/sdk ${WRKSRC}/vendor/github.com/hashicorp/vault/sdk

post-patch:
	@${MKDIR} ${WRKSRC}/out/docker/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/prebuilt-x86_64.tar.xz ${WRKSRC}/out/docker/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/prebuilt-arm.tar.xz ${WRKSRC}/out/docker/

gomod-deps: patch
	(cd ${WRKSRC} && go mod vendor)
	(cd ${WRKSRC} && modules2tuple vendor/modules.txt)

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
