# $FreeBSD$

PORTNAME=	litestream
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
CATEGORIES=	databases

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Standalone streaming replication tool for SQLite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	benbjohnson

GH_TUPLE=	\
		aws:aws-sdk-go:v1.27.0:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:f9fddec55a1e:golang_sys/vendor/golang.org/x/sys \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		mattn:go-sqlite3:v1.14.5:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		pierrec:lz4:v4.1.3:pierrec_lz4_v4/vendor/github.com/pierrec/lz4/v4 \
		prometheus:client_golang:v1.9.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.15.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.2.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./cmd/${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${CP} ${WRKSRC}/etc/${PORTNAME}.yml ${STAGEDIR}${ETCDIR}/${PORTNAME}.yml.sample

.include <bsd.port.mk>
