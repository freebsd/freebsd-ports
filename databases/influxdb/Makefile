# $FreeBSD$

PORTNAME=	influxdb
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases net-mgmt

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Open-source distributed time series database

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.4.0:${PORTSDIR}/lang/go

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	influxd

USE_GITHUB=	yes
GH_ACCOUNT=	influxdb:DEFAULT \
		alecthomas:log4go \
		armon:go_metrics \
		BurntSushi:toml \
		bmizerany:pat \
		boltdb:bolt \
		cheffo:crypto,go_uuid \
		fatih:pool \
		gogo:gogo_protobuf \
		golang:golang_protobuf \
		hashicorp:raft,raft_boltdb,go_msgpack \
		kimor79:gollectd \
		peterh:liner \
		rakyll:statik
GH_PROJECT=	bolt:bolt crypto:crypto go-metrics:go_metrics \
		go-msgpack:go_msgpack gollectd:gollectd liner:liner \
		log4go:log4go pat:pat pool:pool protobuf:gogo_protobuf \
		protobuf:golang_protobuf raft-boltdb:raft_boltdb raft:raft \
		statik:statik toml:toml go-uuid:go_uuid
GH_TAGNAME=	04a3e85:bolt 056c9bc:toml 1351f93:crypto 1bb0d1c:liner \
		1bcc57d:log4go 274df12:statik 58bbd41:gogo_protobuf \
		61d0dee:gollectd aece6fb:golang_protobuf b2d95e5:go_metrics \
		b8a3500:pat cba550e:pool d1e82c1:raft_boltdb ed3ca8a:go_uuid \
		f0f02dd:raft fa3f638:go_msgpack

SUB_FILES=	influxd
SUB_LIST+=	INFLUXD_USER=${INFLUXD_USER} \
		INFLUXD_GROUP=${INFLUXD_GROUP} \
		INFLUXD_DBDIR=${INFLUXD_DBDIR} \
		INFLUXD_PIDDIR=${INFLUXD_PIDDIR} \
		INFLUXD_LOGDIR=${INFLUXD_LOGDIR}

PLIST_SUB=	INFLUXD_USER=${INFLUXD_USER} \
		INFLUXD_GROUP=${INFLUXD_GROUP} \
		INFLUXD_DBDIR=${INFLUXD_DBDIR} \
		INFLUXD_PIDDIR=${INFLUXD_PIDDIR} \
		INFLUXD_LOGDIR=${INFLUXD_LOGDIR}

INFLUXD_USER?=	influxd
INFLUXD_GROUP?=	influxd

INFLUXD_DBDIR=	/var/db/${PORTNAME}/
INFLUXD_LOGDIR=	/var/log/${PORTNAME}/
INFLUXD_PIDDIR=	/var/run/${PORTNAME}/

USERS=		${INFLUXD_USER}
GROUPS=		${INFLUXD_GROUP}

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/code.google.com/p
	@${MKDIR} ${WRKSRC}/src/github.com/BurntSushi
	@${MKDIR} ${WRKSRC}/src/github.com/armon
	@${MKDIR} ${WRKSRC}/src/github.com/bmizerany
	@${MKDIR} ${WRKSRC}/src/github.com/boltdb
	@${MKDIR} ${WRKSRC}/src/github.com/fatih
	@${MKDIR} ${WRKSRC}/src/github.com/gogo
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp
	@${MKDIR} ${WRKSRC}/src/github.com/influxdb
	@${MKDIR} ${WRKSRC}/src/github.com/kimor79
	@${MKDIR} ${WRKSRC}/src/github.com/peterh
	@${MKDIR} ${WRKSRC}/src/github.com/rakyll
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in CHANGELOG.md CONTRIBUTING.md LICENSE QUERIES.md README.md \
	balancer.go balancer_test.go circle-test.sh circle.yml client \
	cluster cmd continuous_queries.md diagnostics.go errors.go etc \
	influxql meta package.sh scripts services shared snapshot statik \
	stats.go stats_test.go tcp tests toml tsdb uuid
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.endfor
	@${MV} ${WRKSRC_bolt} ${WRKSRC}/src/github.com/boltdb/bolt
	@${MV} ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto
	@${MV} ${WRKSRC_go_metrics} ${WRKSRC}/src/github.com/armon/go-metrics
	@${MV} ${WRKSRC_go_msgpack} ${WRKSRC}/src/github.com/hashicorp/go-msgpack
	@${MV} ${WRKSRC_go_uuid} ${WRKSRC}/src/code.google.com/p/go-uuid
	@${MV} ${WRKSRC_gogo_protobuf} ${WRKSRC}/src/github.com/gogo/protobuf
	@${MV} ${WRKSRC_golang_protobuf} ${WRKSRC}/src/github.com/golang/protobuf
	@${MV} ${WRKSRC_gollectd} ${WRKSRC}/src/github.com/kimor79/gollectd
	@${MV} ${WRKSRC_liner} ${WRKSRC}/src/github.com/peterh/liner
	@${MV} ${WRKSRC_log4go} ${WRKSRC}/src/code.google.com/p/log4go
	@${MV} ${WRKSRC_pat} ${WRKSRC}/src/github.com/bmizerany/pat
	@${MV} ${WRKSRC_pool} ${WRKSRC}/src/github.com/fatih/pool
	@${MV} ${WRKSRC_raft_boltdb} ${WRKSRC}/src/github.com/hashicorp/raft-boltdb
	@${MV} ${WRKSRC_raft} ${WRKSRC}/src/github.com/hashicorp/raft
	@${MV} ${WRKSRC_statik} ${WRKSRC}/src/github.com/rakyll/statik
	@${MV} ${WRKSRC_toml} ${WRKSRC}/src/github.com/BurntSushi/toml

do-build:
		@cd ${WRKSRC}/src/github.com/influxdb/ &&  ${SETENV} GOPATH=${WRKSRC} go install ./...

do-install:
		${MKDIR} ${STAGEDIR}${INFLUXD_DBDIR} \
		${STAGEDIR}${INFLUXD_PIDDIR} \
		${STAGEDIR}${INFLUXD_LOGDIR}

post-install:
		${INSTALL_PROGRAM} ${WRKSRC}/bin/influxd ${STAGEDIR}${PREFIX}/bin/influxd
		${INSTALL_PROGRAM} ${WRKSRC}/bin/influx ${STAGEDIR}${PREFIX}/bin/influx
		@${SED} -i .bak -e \
			"s|/tmp/influxdb/development|/var/db/influxdb|g" \
			${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/etc/config.sample.toml
		${INSTALL_DATA} \
			${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/etc/config.sample.toml  \
			${STAGEDIR}${PREFIX}/etc/influxd.conf.sample
		@${MKDIR} ${STAGEDIR}/var/db/influxdb
		@${MKDIR} ${STAGEDIR}/var/log/influxdb

.include <bsd.port.mk>
