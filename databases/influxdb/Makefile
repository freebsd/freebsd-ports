# $FreeBSD$

PORTNAME=	influxdb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
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
GH_TUPLE=	BurntSushi:toml:a368813:toml/src/github.com/BurntSushi/toml \
		RoaringBitmap:roaring:v0.4.3:roaring/src/github.com/RoaringBitmap/roaring \
		beorn7:perks:4c0e845:perks/src/github.com/beorn7/perks \
		bmizerany:pat:6226ea5:pat/src/github.com/bmizerany/pat \
		boltdb:bolt:v1.3.1:bolt/src/github.com/boltdb/bolt \
		cespare:xxhash:v1.0.0:xxhash/src/github.com/cespare/xxhash \
		davecgh:go-spew:v1.1.0:go_spew/src/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:jwt_go/src/github.com/dgrijalva/jwt-go \
		dgryski:go-bitstream:9f22ccc:go_bitstream/src/github.com/dgryski/go-bitstream \
		glycerine:go-unsnap-stream:62a9a9e:go_unsnap_stream/src/github.com/glycerine/go-unsnap-stream \
		gogo:protobuf:v1.0.0:gogo_protobuf/src/github.com/gogo/protobuf \
		golang:protobuf:9255415:golang_protobuf/src/github.com/golang/protobuf \
		golang:snappy:d9eb7a3:snappy/src/github.com/golang/snappy \
		google:go-cmp:v0.2.0:go_cmp/src/google/go-cmp \
		influxdata:influxql:a7267bf:influxql/src/github.com/influxdata/influxql \
		influxdata:usage-client:6d38953:usage_client/src/github.com/influxdata/usage-client \
		influxdata:yamux:1f58ded:yamux/src/github.com/influxdata/yamux \
		influxdata:yarpc:f0da2db:yarpc/src/github.com/influxdata/yarpc \
		jsternberg:zap-logfmt:v1.0.0:zap_logfmt/src/github.com/jsternberg/zap-logfmt \
		jwilder:encoding:b4e1701:encoding/src/github.com/jwilder/encoding \
		klauspost:compress:v1.2.1:compress/src/github.com/klauspost/compress \
		klauspost:cpuid:v1.1:cpuid/src/github.com/klauspost/cpuid \
		klauspost:crc32:v1.1:crc32/src/github.com/klauspost/crc32 \
		klauspost:pgzip:v1.1:pgzip/src/github.com/klauspost/pgzip \
		mattn:go-isatty:6ca4dbf:go_isatty/src/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.0:golang_protobuf_extensions/src/github.com/matttproud/golang_protobuf_extensions \
		opentracing:opentracing-go:328fceb:opentracing_go/src/github.com/opentracing/opentracing-go \
		paulbellamy:ratecounter:v0.2.0:ratecounter/src/github.com/paulbellamy/ratecounter \
		peterh:liner:6106ee4:liner/src/github.com/peterh/liner \
		philhofer:fwd:v1.0.0:fwd/src/github.com/philhofer/fwd \
		prometheus:client_golang:661e31b:client_golang/src/github.com/prometheus/client_golang \
		prometheus:client_model:99fa1f4:client_model/src/github.com/prometheus/client_model \
		prometheus:common:e4aa40a:common/src/github.com/prometheus/common \
		prometheus:procfs:54d17b5:procfs/src/github.com/prometheus/procfs \
		retailnext:hllpp:101a6d2:hllpp/src/github.com/retailnext/hllpp \
		tinylib:msgp:1.0.2:msgp/src/github.com/tinylib/msgp \
		xlab:treeprint:f3a15cf:treeprint/src/github.com/xlab/treeprint \
		collectd:go-collectd:v0.3.0:go_collectd/src/collectd.org \
		uber-go:atomic:v1.3.1:atomic/src//go.uber.org/atomic \
		uber-go:multierr:v1.1.0:multierr/src/go.uber.org/multierr \
		uber-go:zap:v1.7.1:zap/src/go.uber.org/zap \
		xlab:treeprint:f3a15cf:treeprint/src/github.com/xlab/treeprint \
		golang:crypto:c3a3ad6:crypto/src/golang.org/x/crypto \
		golang:net:92b859f:net/src/golang.org/x/net \
		golang:sync:1d60e46:sync/src/golang.org/x/sync \
		golang:sys:d8e400b:sys/src/golang.org/x/sys \
		golang:text:v0.3.0:text/src/golang.org/x/text \
		golang:time:26559e0:time/src/golang.org/x/time

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
