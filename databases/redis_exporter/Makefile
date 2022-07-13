# Created by: Jev Björsell <ports@ecadlabs.com>

PORTNAME=	redis_exporter
PORTVERSION=	1.33.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	databases

MAINTAINER=	arcade@b1t.name
COMMENT=	Prometheus exporter for redis stats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	oliver006
GH_TUPLE=	beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash/vendor/github.com/cespare/xxhash/v2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:ebe580a85c40:golang_sys/vendor/golang.org/x/sys \
		gomodule:redigo:v1.8.6:gomodule_redigo/vendor/github.com/gomodule/redigo \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mna:redisc:v1.3.2:gomodule_redisc/vendor/github.com/mna/redisc \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.26.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus
USE_RC_SUBR=	redis_exporter

GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

PLIST_FILES=	bin/redis_exporter

LD_FLAG_X_PREFIX=	-X main
LD_FLAG_STRING=		-s ${LD_FLAG_X_PREFIX}.BuildVersion=${PORTVERSION}

.include <bsd.port.mk>
