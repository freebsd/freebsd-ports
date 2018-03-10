# $FreeBSD$

PORTNAME=	influxdb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	databases net-mgmt

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Open-source distributed time series database

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

BUILD_DEPENDS=	go>=1.8.1:lang/go

USE_RC_SUBR=	influxd

USE_GITHUB=	yes
GH_ACCOUNT=	influxdata:DEFAULT
GH_TUPLE=	BurntSushi:toml:a368813:toml/src/github.com/BurntSushi/toml \
		RoaringBitmap:roaring:cefad6e:roaring/src/github.com/RoaringBitmap/roaring \
		beorn7:perks:4c0e845:perks/src/github.com/beorn7/perks \
		bmizerany:pat:c068ca2:pat/src/github.com/bmizerany/pat \
		boltdb:bolt:4b1ebc1:bolt/src/github.com/boltdb/bolt \
		cespare:xxhash:1b6d2e4:xxhash/src/github.com/cespare/xxhash \
		davecgh:go-spew:346938d:go_spew/src/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:24c63f5:jwt_go/src/github.com/dgrijalva/jwt-go \
		dgryski:go-bits:2ad8d70:go_bits/src/github.com/dgryski/go-bits \
		dgryski:go-bitstream:7d46cd2:go_bitstream/src/github.com/dgryski/go-bitstream \
		glycerine:go-unsnap-stream:62a9a9e:go_unsnap_stream/src/github.com/glycerine/go-unsnap-stream \
		gogo:protobuf:1c2b16b:protobuf/src/github.com/gogo/protobuf \
		golang:protobuf:1e59b77:golang_protobuf/src/github.com/golang/protobuf \
		golang:snappy:d9eb7a3:snappy/src/github.com/golang/snappy \
		google:go-cmp:18107e6:go_cmp/src/google/go-cmp \
		influxdata:influxql:c0a433a:influxql/src/github.com/influxdata/influxql \
		influxdata:usage-client:6d38953:usage_client/src/github.com/influxdata/usage-client \
		influxdata:yamux:1f58ded:yamux/src/github.com/influxdata/yamux \
		influxdata:yarpc:036268c:yarpc/src/github.com/influxdata/yarpc \
		jsternberg:zap-logfmt:5ea5386:zap_logfmt/src/github.com/jsternberg/zap-logfmt \
		jwilder:encoding:278947:encoding/src/github.com/jwilder/encoding \
		mattn:go-isatty:6ca4dbf:go_isatty/src/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:c12348c:golang_protobuf_extensions/src/github.com/matttproud/golang_protobuf_extensions \
		opentracing:opentracing-go:1361b9c:opentracing_go/src/github.com/opentracing/opentracing-go \
		paulbellamy:ratecounter:5a11f58:ratecounter/src/github.com/paulbellamy/ratecounter \
		peterh:liner:8860952:liner/src/github.com/peterh/liner \
		philhofer:fwd:1612a29:fwd/src/github.com/philhofer/fwd \
		prometheus:client_golang:661e31b:client_golang/src/github.com/prometheus/client_golang \
		prometheus:client_model:99fa1f4:client_model/src/github.com/prometheus/client_model \
		prometheus:common:2e54d0b:common/src/github.com/prometheus/common \
		prometheus:procfs:a6e9df8:procfs/src/github.com/prometheus/procfs \
		retailnext:hllpp:38a7bb7:hllpp/src/github.com/retailnext/hllpp \
		tinylib:msgp:ad0ff2e:msgp/src/github.com/tinylib/msgp \
		xlab:treeprint:06dfc6f:treeprint/src/github.com/xlab/treeprint \
		collectd:go-collectd:e84e8af:go_collectd/src/collectd.org \
		uber-go:atomic:74ca5ec:atomic/src//go.uber.org/atomic \
		uber-go:multierr:fb7d312:multierr/src/go.uber.org/multierr \
		uber-go:zap:35aad58:zap/src/go.uber.org/zap \
		xlab:treeprint:06dfc6f:treeprint/src/github.com/xlab/treeprint \
		golang:crypto:9477e0b:crypto/src/golang.org/x/crypto \
		golang:net:9dfe398:net/src/golang.org/x/net \
		golang:sync:fd80eb9:sync/src/golang.org/x/sync \
		golang:sys:062cd7e:sys/src/golang.org/x/sys \
		golang:text:a71fd10:text/src/golang.org/x/text \
		golang:time:6dc1736:time/src/golang.org/x/time

SUB_FILES=	influxd
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

INFLUXD_USER=	influxd
INFLUXD_GROUP=	influxd

USERS=		${INFLUXD_USER}
GROUPS=		${INFLUXD_GROUP}

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

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD" && ((${OSVERSION} >= 1100513 && ${OSVERSION} < 1200000) || \
	${OSVERSION} >= 1200015)
SUB_LIST+=	INFLUXD_LOGCMD="daemon"
.else
SUB_LIST+=	INFLUXD_LOGCMD="logger"
.endif

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
	@cd ${WRKSRC} && \
		${MV} appveyor.yml build.py build.sh circle-test.sh circle.yml \
		client cmd coordinator docker errors.go etc gobuild.sh importer \
		influxdb.go internal logger man models monitor nightly.sh node.go pkg \
		prometheus query releng scripts services stress tcp test.sh \
		tests toml tsdb uuid \
		${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}

do-build:
		@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT} && \
			${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go install -ldflags "-X main.version=${DISTVERSION}" ./...

do-build-MANPAGES-on:
		@cd ${WRKSRC}/src/github.com/influxdata/influxdb/man && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}

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
.for i in influx.1 influx_inspect.1 influx_stress.1 influx_tsm.1 \
	influxd-backup.1 influxd-config.1 influxd-restore.1 \
	influxd-run.1 influxd-version.1 influxd.1 influx.1 influx_inspect.1 \
	influx_stress.1 influx_tsm.1
		${INSTALL_MAN} ${WRKSRC}/src/github.com/influxdata/influxdb/man/$i ${STAGEDIR}${MAN8PREFIX}/man/man1
.endfor

.include <bsd.port.post.mk>
