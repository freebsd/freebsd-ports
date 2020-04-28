# $FreeBSD$

PORTNAME=	prometheus-postgresql-adapter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	databases

MAINTAINER=	felix@userspace.com.au
COMMENT=	Use PostgreSQL as a remote storage database for Prometheus

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	timescale
GH_TUPLE=	\
		beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		go-kit:kit:v0.9.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-logfmt:logfmt:v0.4.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:net:d28f0bde5980:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:81d4e9dc473e:golang_sys/vendor/golang.org/x/sys \
		golang:text:cb6730876b98:golang_text/vendor/golang.org/x/text \
		google:go-genproto:c506a9f90610:google_go_genproto/vendor/google.golang.org/genproto \
		grpc-ecosystem:grpc-gateway:v1.9.5:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.22.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jamiealquiza:envy:v1.1.0:jamiealquiza_envy/vendor/github.com/jamiealquiza/envy \
		kr:logfmt:b84e30acd515:kr_logfmt/vendor/github.com/kr/logfmt \
		lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.0.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.6.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prometheus:e5b22494857d:prometheus_prometheus/vendor/github.com/prometheus/prometheus \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag

USE_RC_SUBR=	prometheus-postgresql-adapter

GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-w" ${BUILD_TAGS}

PLIST_FILES=	bin/prometheus-postgresql-adapter

.include <bsd.port.mk>
