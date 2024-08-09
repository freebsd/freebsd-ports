PORTNAME=	litestream
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.13
PORTREVISION=	6
CATEGORIES=	databases

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Standalone streaming replication tool for SQLite
WWW=		https://litestream.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	Build error: constant 9223372036854775807 overflows int

USES=		go:1.21,modules

USE_GITHUB=	yes
GH_ACCOUNT=	benbjohnson

GH_TUPLE=	\
		Azure:azure-pipeline-go:v0.2.3:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.15.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		FiloSottile:age:v1.1.1:filosottile_age/vendor/filippo.io/age \
		aws:aws-sdk-go:v1.44.318:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		census-instrumentation:opencensus-go:v0.24.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:v0.12.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:v0.14.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.11.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:v0.3.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.11.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.12.0:golang_text/vendor/golang.org/x/text \
		golang:xerrors:04be3eba64a2:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.9:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:1744710a1577:google_go_genproto/vendor/google.golang.org/genproto \
		google:s2a-go:v0.1.4:google_s2a_go/vendor/github.com/google/s2a-go \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:enterprise-certificate-proxy:v0.2.5:googleapis_enterprise_certificate_proxy/vendor/github.com/googleapis/enterprise-certificate-proxy \
		googleapis:gax-go:v2.12.0:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.135.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:compute/v1.23.0:googleapis_google_cloud_go_compute \
		googleapis:google-cloud-go:iam/v1.1.1:googleapis_google_cloud_go_iam \
		googleapis:google-cloud-go:storage/v1.31.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.110.7:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.57.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		kr:fs:v0.1.0:kr_fs/vendor/github.com/kr/fs \
		mattn:go-ieproxy:v0.0.11:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-shellwords:v1.0.12:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		mattn:go-sqlite3:v1.14.17:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		pierrec:lz4:v4.1.18:pierrec_lz4_v4/vendor/github.com/pierrec/lz4/v4 \
		pkg:sftp:v1.13.5:pkg_sftp/vendor/github.com/pkg/sftp \
		prometheus:client_golang:v1.16.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.4.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.44.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.11.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.31.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/compute
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_compute}/compute ${WRKSRC}/vendor/cloud.google.com/go/compute
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/iam
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_iam}/iam ${WRKSRC}/vendor/cloud.google.com/go/iam
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage

.include <bsd.port.mk>

