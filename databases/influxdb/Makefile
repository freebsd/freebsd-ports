# $FreeBSD$

PORTNAME=	influxdb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
CATEGORIES=	databases net-mgmt

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Open-source distributed time series database

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	depends on go which is not supported in this architecture

USES=		go:modules

USE_RC_SUBR=	influxd

USE_GITHUB=	yes
GH_ACCOUNT=	influxdata
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT_DEFAULT}

GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		apache:arrow:af6fa24be0db:apache_arrow_arrow/vendor/github.com/apache/arrow \
		beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		bmizerany:pat:6226ea591a40:bmizerany_pat/vendor/github.com/bmizerany/pat \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		c-bata:go-prompt:v0.2.2:c_bata_go_prompt/vendor/github.com/c-bata/go-prompt \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		collectd:go-collectd:v0.3.0:collectd_go_collectd/vendor/collectd.org \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dgryski:go-bitstream:3522498ce2c8:dgryski_go_bitstream/vendor/github.com/dgryski/go-bitstream \
		dominikh:go-tools:v0.0.1-2019.2.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		eclipse:paho.mqtt.golang:v1.2.0:eclipse_paho_mqtt_golang/vendor/github.com/eclipse/paho.mqtt.golang \
		glycerine:go-unsnap-stream:9f0cb55181dd:glycerine_go_unsnap_stream/vendor/github.com/glycerine/go-unsnap-stream \
		go-sql-driver:mysql:v1.4.1:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		gogo:protobuf:v1.1.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:87dc89f01550:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:da58074b4299:golang_exp/vendor/golang.org/x/exp \
		golang:geo:5b978397cfec:golang_geo/vendor/github.com/golang/geo \
		golang:groupcache:215e87163ea7:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:fdd1cda4f05f:golang_lint/vendor/golang.org/x/lint \
		golang:net:c0dbc17a3553:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:2e65f85255db:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:548cf772de50:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		golang:tools:89082a384178:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:flatbuffers:v1.11.0:google_flatbuffers/vendor/github.com/google/flatbuffers \
		google:go-cmp:v0.4.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:bd8f9a0ef82f:google_go_genproto/vendor/google.golang.org/genproto \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.15.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:bigtable/v1.2.0:googleapis_google_cloud_go_bigtable \
		googleapis:google-cloud-go:v0.51.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		grpc:grpc-go:v1.26.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		influxdata:flux:v0.65.0:influxdata_flux/vendor/github.com/influxdata/flux \
		influxdata:influxql:v1.1.0:influxdata_influxql/vendor/github.com/influxdata/influxql \
		influxdata:line-protocol:32c6aa80de5e:influxdata_line_protocol/vendor/github.com/influxdata/line-protocol \
		influxdata:roaring:fc520f41fab6:influxdata_roaring/vendor/github.com/influxdata/roaring \
		influxdata:tdigest:bf2b5ad3c0a9:influxdata_tdigest/vendor/github.com/influxdata/tdigest \
		influxdata:usage-client:6d3895376368:influxdata_usage_client/vendor/github.com/influxdata/usage-client \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		jsternberg:zap-logfmt:v1.0.0:jsternberg_zap_logfmt/vendor/github.com/jsternberg/zap-logfmt \
		jwilder:encoding:b4e1701a28ef:jwilder_encoding/vendor/github.com/jwilder/encoding \
		klauspost:compress:v1.4.0:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:ae7887de9fa5:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		klauspost:crc32:cb6bfca970f6:klauspost_crc32/vendor/github.com/klauspost/crc32 \
		klauspost:pgzip:0bf5dcad4ada:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		lib:pq:v1.0.0:lib_pq/vendor/github.com/lib/pq \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.4:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.3:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-tty:13ff1204f104:mattn_go_tty/vendor/github.com/mattn/go-tty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mschoch:smat:90eadee771ae:mschoch_smat/vendor/github.com/mschoch/smat \
		opentracing:opentracing-go:bd9c31933947:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		paulbellamy:ratecounter:v0.2.0:paulbellamy_ratecounter/vendor/github.com/paulbellamy/ratecounter \
		peterh:liner:8c1271fcf47f:peterh_liner/vendor/github.com/peterh/liner \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:term:bffc007b7fd5:pkg_term/vendor/github.com/pkg/term \
		prometheus:client_golang:v1.0.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:14fe0d1b01d4:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.6.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.2:prometheus_procfs/vendor/github.com/prometheus/procfs \
		retailnext:hllpp:101a6d2f8b52:retailnext_hllpp/vendor/github.com/retailnext/hllpp \
		satori:go.uuid:b2ce2384e17b:satori_go_uuid/vendor/github.com/satori/go.uuid \
		segmentio:kafka-go:v0.2.0:segmentio_kafka_go/vendor/github.com/segmentio/kafka-go \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		tinylib:msgp:v1.0.2:tinylib_msgp/vendor/github.com/tinylib/msgp \
		uber-go:atomic:v1.3.2:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.1.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.9.1:uber_go_zap/vendor/go.uber.org/zap \
		willf:bitset:v1.1.3:willf_bitset/vendor/github.com/willf/bitset \
		xlab:treeprint:d6fb6747feb6:xlab_treeprint/vendor/github.com/xlab/treeprint

GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSION}"
GO_TARGET=	./cmd/influxd \
		./cmd/influx \
		./cmd/influx_inspect \
		./cmd/influx_tsm \
		./cmd/influx_stress

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	xmlto:textproc/xmlto \
			asciidoc:textproc/asciidoc \
			docbook-xml>0:textproc/docbook-xml
MANPAGES_USES=	gmake

INFLUXD_DBDIR=	/var/db/${PORTNAME}/
INFLUXD_LOGDIR=	/var/log/${PORTNAME}/
INFLUXD_PIDDIR=	/var/run/${PORTNAME}/

INFLUXD_USER=	influxd
INFLUXD_GROUP=	influxd

USERS=		${INFLUXD_USER}
GROUPS=		${INFLUXD_GROUP}

SUB_LIST=	INFLUXD_USER=${INFLUXD_USER} \
		INFLUXD_GROUP=${INFLUXD_GROUP} \
		INFLUXD_DBDIR=${INFLUXD_DBDIR} \
		INFLUXD_PIDDIR=${INFLUXD_PIDDIR} \
		INFLUXD_LOGDIR=${INFLUXD_LOGDIR}

PLIST_SUB=	INFLUXD_USER=${INFLUXD_USER} \
		INFLUXD_GROUP=${INFLUXD_GROUP} \
		INFLUXD_DBDIR=${INFLUXD_DBDIR} \
		INFLUXD_PIDDIR=${INFLUXD_PIDDIR} \
		INFLUXD_LOGDIR=${INFLUXD_LOGDIR}

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD"
SUB_LIST+=	INFLUXD_LOGCMD="daemon"
.else
SUB_LIST+=	INFLUXD_LOGCMD="logger"
.endif

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/bigtable
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_bigtable}/bigtable ${WRKSRC}/vendor/cloud.google.com/go/bigtable

do-build-MANPAGES-on:
	@cd ${WRKSRC}/man && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}

post-install:
	${MKDIR} ${STAGEDIR}${INFLUXD_DBDIR} \
	${STAGEDIR}${INFLUXD_PIDDIR} \
	${STAGEDIR}${INFLUXD_LOGDIR}
	@${SED} -i .bak -e \
		"s|/var/lib/influxdb|/var/db/influxdb|g" \
		${WRKSRC}/etc/config.sample.toml
	${INSTALL_DATA} \
		${WRKSRC}/etc/config.sample.toml \
		${STAGEDIR}${PREFIX}/etc/influxd.conf.sample

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
