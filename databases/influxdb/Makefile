# $FreeBSD$

PORTNAME=	influxdb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.6
CATEGORIES=	databases net-mgmt

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Open-source distributed time series database

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	depends on go which is not supported in this architecture

BUILD_DEPENDS=	go>=1.10.3:lang/go

USE_RC_SUBR=	influxd

USE_GITHUB=	yes
GH_ACCOUNT=	influxdata
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT_DEFAULT}

GH_TUPLE=	BurntSushi:toml:a368813:BurntSushi_toml/src/github.com/BurntSushi/toml \
		Masterminds:semver:v1.4.2:Masterminds_semver/src/github.com/Masterminds/semver \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/src/github.com/alecthomas/kingpin \
		alecthomas:template:a0175ee:alecthomas_template/src/github.com/alecthomas/template \
		alecthomas:units:2efee85:alecthomas_units/src/github.com/alecthomas/units \
		apache:arrow:f5df773:apache_arrow/src/github.com/apache/arrow \
		apex:log:941dea7:apex_log/src/github.com/apex/log \
		aws:aws-sdk-go:v1.15.50:aws_aws_sdk_go/src/github.com/aws/aws-sdk-go \
		beorn7:perks:3a771d9:beorn7_perks/src/github.com/beorn7/perks \
		blakesmith:ar:8bd4349:blakesmith_ar/src/github.com/blakesmith/ar \
		bmizerany:pat:6226ea5:bmizerany_pat/src/github.com/bmizerany/pat \
		boltdb:bolt:v1.3.1:boltdb_bolt/src/github.com/boltdb/bolt \
		c-bata:go-prompt:v0.2.1:c_bata_go_prompt/src/github.com/c-bata/go-prompt \
		caarlos0:ctrlc:v1.0.0:caarlos0_ctrlc/src/github.com/caarlos0/ctrlc \
		campoy:unique:88950e5:campoy_unique/src/github.com/campoy/unique \
		cespare:xxhash:v1.0.0:cespare_xxhash/src/github.com/cespare/xxhash \
		collectd:go-collectd:v0.3.0:collectd_go_collectd/src/collectd.org \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/src/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/src/github.com/dgrijalva/jwt-go \
		dgryski:go-bitstream:3522498:dgryski_go_bitstream/src/github.com/dgryski/go-bitstream \
		dominikh:go-tools:2017.2.2:dominikh_go_tools/src/honnef.co/go/tools \
		fatih:color:v1.5.0:fatih_color/src/github.com/fatih/color \
		glycerine:go-unsnap-stream:9f0cb55:glycerine_go_unsnap_stream/src/github.com/glycerine/go-unsnap-stream \
		go-ini:ini:v1.38.3:go_ini_ini/src/github.com/go-ini/ini \
		go-sql-driver:mysql:v1.4.1:go_sql_driver_mysql/src/github.com/go-sql-driver/mysql \
		go-yaml:yaml:5420a8b:go_yaml_yaml/src/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.1.1:gogo_protobuf/src/github.com/gogo/protobuf \
		golang:appengine:v1.2.0:golang_appengine/src/google.golang.org/appengine \
		golang:crypto:a214413:golang_crypto/src/golang.org/x/crypto \
		golang:net:a680a1e:golang_net/src/golang.org/x/net \
		golang:oauth2:c57b0fa:golang_oauth2/src/golang.org/x/oauth2 \
		golang:protobuf:v1.1.0:golang_protobuf/src/github.com/golang/protobuf \
		golang:snappy:d9eb7a3:golang_snappy/src/github.com/golang/snappy \
		golang:sync:1d60e46:golang_sync/src/golang.org/x/sync \
		golang:sys:ac767d6:golang_sys/src/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/src/golang.org/x/text \
		golang:time:fbb02b2:golang_time/src/golang.org/x/time \
		golang:tools:45ff765:golang_tools/src/golang.org/x/tools \
		google:go-cmp:v0.2.0:google_go_cmp/src/github.com/google/go-cmp \
		google:go-genproto:fedd286:google_go_genproto/src/google.golang.org/genproto \
		google:go-github:dd29b54:google_go_github/src/github.com/google/go-github \
		google:go-querystring:v1.0.0:google_go_querystring/src/github.com/google/go-querystring \
		goreleaser:goreleaser:v0.88.0:goreleaser_goreleaser/src/github.com/goreleaser/goreleaser \
		goreleaser:nfpm:v0.9.5:goreleaser_nfpm/src/github.com/goreleaser/nfpm \
		grpc:grpc-go:v1.13.0:grpc_grpc_go/src/google.golang.org/grpc \
		imdario:mergo:v0.3.6:imdario_mergo/src/github.com/imdario/mergo \
		influxdata:flux:v0.24.0:influxdata_flux/src/github.com/influxdata/flux \
		influxdata:influxql:v1.0.0:influxdata_influxql/src/github.com/influxdata/influxql \
		influxdata:line-protocol:a3afd89:influxdata_line_protocol/src/github.com/influxdata/line-protocol \
		influxdata:roaring:fc520f4:influxdata_roaring/src/github.com/influxdata/roaring \
		influxdata:tdigest:bf2b5ad:influxdata_tdigest/src/github.com/influxdata/tdigest \
		influxdata:usage-client:6d38953:influxdata_usage_client/src/github.com/influxdata/usage-client \
		jmespath:go-jmespath:0b12d6b:jmespath_go_jmespath/src/github.com/jmespath/go-jmespath \
		jsternberg:zap-logfmt:v1.0.0:jsternberg_zap_logfmt/src/github.com/jsternberg/zap-logfmt \
		jwilder:encoding:b4e1701:jwilder_encoding/src/github.com/jwilder/encoding \
		kisielk:gotool:v1.0.0:kisielk_gotool/src/github.com/kisielk/gotool \
		klauspost:compress:v1.4.0:klauspost_compress/src/github.com/klauspost/compress \
		klauspost:cpuid:v1.1:klauspost_cpuid/src/github.com/klauspost/cpuid \
		klauspost:crc32:v1.1:klauspost_crc32/src/github.com/klauspost/crc32 \
		klauspost:pgzip:v1.1:klauspost_pgzip/src/github.com/klauspost/pgzip \
		lib:pq:v1.0.0:lib_pq/src/github.com/lib/pq \
		mattn:go-colorable:v0.0.9:mattn_go_colorable/src/github.com/mattn/go-colorable \
		mattn:go-isatty:6ca4dbf:mattn_go_isatty/src/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.2:mattn_go_runewidth/src/github.com/mattn/go-runewidth \
		mattn:go-tty:13ff120:mattn_go_tty/src/github.com/mattn/go-tty \
		mattn:go-zglob:2ea3427:mattn_go_zglob/src/github.com/mattn/go-zglob \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/src/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:go-homedir:ae18d6b:mitchellh_go_homedir/src/github.com/mitchellh/go-homedir \
		mschoch:smat:90eadee:mschoch_smat/src/github.com/mschoch/smat \
		opentracing:opentracing-go:bd9c319:opentracing_opentracing_go/src/github.com/opentracing/opentracing-go \
		paulbellamy:ratecounter:v0.2.0:paulbellamy_ratecounter/src/github.com/paulbellamy/ratecounter \
		peterh:liner:8c1271f:peterh_liner/src/github.com/peterh/liner \
		philhofer:fwd:v1.0.0:philhofer_fwd/src/github.com/philhofer/fwd \
		pkg:errors:v0.8.0:pkg_errors/src/github.com/pkg/errors \
		pkg:term:bffc007:pkg_term/src/github.com/pkg/term \
		prometheus:client_golang:661e31b:prometheus_client_golang/src/github.com/prometheus/client_golang \
		prometheus:client_model:5c3871d:prometheus_client_model/src/github.com/prometheus/client_model \
		prometheus:common:7600349:prometheus_common/src/github.com/prometheus/common \
		prometheus:procfs:ae68e2d:prometheus_procfs/src/github.com/prometheus/procfs \
		retailnext:hllpp:101a6d2:retailnext_hllpp/src/github.com/retailnext/hllpp \
		satori:go.uuid:v1.2.0:satori_go_uuid/src/github.com/satori/go.uuid \
		segmentio:kafka-go:v0.2.2:segmentio_kafka_go/src/github.com/segmentio/kafka-go \
		spf13:cast:v1.3.0:spf13_cast/src/github.com/spf13/cast \
		tinylib:msgp:1.0.2:tinylib_msgp/src/github.com/tinylib/msgp \
		uber-go:atomic:v1.3.2:uber_go_atomic/src/go.uber.org/atomic \
		uber-go:multierr:v1.1.0:uber_go_multierr/src/go.uber.org/multierr \
		uber-go:zap:v1.9.0:uber_go_zap/src/go.uber.org/zap \
		willf:bitset:v1.1.3:willf_bitset/src/github.com/willf/bitset \
		xlab:treeprint:d6fb674:xlab_treeprint/src/github.com/xlab/treeprint

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=	MANPAGES
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

do-build:
		@cd ${WRKSRC}/${GH_SUBDIR} && \
			${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go install -ldflags "-X main.version=${DISTVERSION}" ./cmd/...

do-build-MANPAGES-on:
		@cd ${WRKSRC}/${GH_SUBDIR}/man && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}

do-install:
		${MKDIR} ${STAGEDIR}${INFLUXD_DBDIR} \
		${STAGEDIR}${INFLUXD_PIDDIR} \
		${STAGEDIR}${INFLUXD_LOGDIR}
		${INSTALL_PROGRAM} ${WRKSRC}/bin/influxd ${STAGEDIR}${PREFIX}/bin/influxd
		${INSTALL_PROGRAM} ${WRKSRC}/bin/influx ${STAGEDIR}${PREFIX}/bin/influx
		${INSTALL_PROGRAM} ${WRKSRC}/bin/influx_inspect ${STAGEDIR}${PREFIX}/bin/influx_inspect
		${INSTALL_PROGRAM} ${WRKSRC}/bin/influx_tsm ${STAGEDIR}${PREFIX}/bin/influx_tsm
		${INSTALL_PROGRAM} ${WRKSRC}/bin/influx_stress ${STAGEDIR}${PREFIX}/bin/influx_stress
		${INSTALL_PROGRAM} ${WRKSRC}/bin/store ${STAGEDIR}${PREFIX}/bin/influx_store
		@${SED} -i .bak -e \
			"s|/var/lib/influxdb|/var/db/influxdb|g" \
			${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT}/etc/config.sample.toml
		${INSTALL_DATA} \
			${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT}/etc/config.sample.toml  \
			${STAGEDIR}${PREFIX}/etc/influxd.conf.sample

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/src/github.com/influxdata/influxdb/man/*.1  ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
