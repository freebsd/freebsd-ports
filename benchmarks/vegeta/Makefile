PORTNAME=	vegeta
DISTVERSIONPREFIX=	v
DISTVERSION=	12.11.0
PORTREVISION=	14
CATEGORIES=	benchmarks www

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	HTTP load testing tool and library
WWW=		https://github.com/tsenart/vegeta

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	tsenart
GH_TUPLE=	alecthomas:jsonschema:9eeeec9d044b:alecthomas_jsonschema/vendor/github.com/alecthomas/jsonschema \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bmizerany:perks:03f9df79da1e:bmizerany_perks/vendor/github.com/bmizerany/perks \
		c2h5oh:datasize:859f65c6625b:c2h5oh_datasize/vendor/github.com/c2h5oh/datasize \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		dgryski:go-gk:a69029f61654:dgryski_go_gk/vendor/github.com/dgryski/go-gk \
		dgryski:go-lttb:f8fc36cdbff1:dgryski_go_lttb/vendor/github.com/dgryski/go-lttb \
		flyingmutant:rapid:v1.0.0:flyingmutant_rapid/vendor/pgregory.net/rapid \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:exp:613f0c0eb8a1:golang_exp/vendor/golang.org/x/exp \
		golang:mod:v0.12.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.12.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:v0.3.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.10.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.11.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.11.0:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.5.9:google_go_cmp/vendor/github.com/google/go-cmp \
		grafana:regexp:6b5c0a4cb7fd:grafana_regexp/vendor/github.com/grafana/regexp \
		iancoleman:orderedmap:v0.3.0:iancoleman_orderedmap/vendor/github.com/iancoleman/orderedmap \
		influxdata:tdigest:v0.0.1:influxdata_tdigest/vendor/github.com/influxdata/tdigest \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		mailru:easyjson:v0.7.7:mailru_easyjson/vendor/github.com/mailru/easyjson \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.55:miekg_dns/vendor/github.com/miekg/dns \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.16.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.4.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.44.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.10.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prometheus:v0.45.0:prometheus_prometheus/vendor/github.com/prometheus/prometheus \
		protocolbuffers:protobuf-go:v1.30.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rs:dnscache:e0241e321417:rs_dnscache/vendor/github.com/rs/dnscache \
		streadway:quantile:4246515d968d:streadway_quantile/vendor/github.com/streadway/quantile \
		tsenart:go-tsz:0bd30b3df1c3:tsenart_go_tsz/vendor/github.com/tsenart/go-tsz

GO_BUILDFLAGS=	-tags=netgo \
		-ldflags '-s -w -extldflags "-static" -X main.Version=${DISTVERSION}'

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
