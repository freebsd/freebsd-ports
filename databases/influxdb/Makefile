# $FreeBSD$

PORTNAME=	influxdb
PORTVERSION=	0.10.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases net-mgmt

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Open-source distributed time series database

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.5.0:lang/go

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	influxd

USE_GITHUB=	yes
GH_ACCOUNT=	influxdb:DEFAULT \
		BurntSushi:BurntSushi_toml \
		armon:armon_go_metrics \
		bmizerany:bmizerany_pat \
		boltdb:boltdb_bolt \
		collectd:collectd_go_collectd \
		davecgh:davecgh_go_spew \
		dgryski:dgryski_go_bits \
		dgryski:dgryski_go_bitstream \
		fatih:fatih_pool \
		gogo:gogo_protobuf \
		golang:golang_crypto,golang_snappy \
		hashicorp:hashicorp_go_msgpack,hashicorp_raft,hashicorp_raft_boltdb \
		influxdb:influxdb_usage_client \
		jwilder:jwilder_encoding \
		kimor79:kimor79_gollectd \
		paulbellamy:paulbellamy_ratecounter \
		peterh:peterh_liner \
		rakyll:rakyll_statik

GH_PROJECT=	bolt:boltdb_bolt \
		crypto:golang_crypto \
		encoding:jwilder_encoding \
		go-bits:dgryski_go_bits \
		go-bitstream:dgryski_go_bitstream \
		go-collectd:collectd_go_collectd \
		go-metrics:armon_go_metrics \
		go-msgpack:hashicorp_go_msgpack \
		go-spew:davecgh_go_spew \
		gollectd:kimor79_gollectd \
		liner:peterh_liner \
		pat:bmizerany_pat \
		pool:fatih_pool \
		protobuf:gogo_protobuf \
		raft-boltdb:hashicorp_raft_boltdb \
		raft:hashicorp_raft \
		ratecounter:paulbellamy_ratecounter \
		snappy:golang_snappy \
		statik:rakyll_statik \
		toml:BurntSushi_toml \
		usage-client:influxdb_usage_client

GH_TAGNAME=	5c4df71:BurntSushi_toml \
		345426c:armon_go_metrics \
		b8a3500:bmizerany_pat \
		2f846c3:boltdb_bolt \
		9fc824c:collectd_go_collectd \
		5215b55:davecgh_go_spew \
		86c69b3:dgryski_go_bits \
		27cd597:dgryski_go_bitstream \
		cba550e:fatih_pool \
		82d16f7:gogo_protobuf \
		1f22c01:golang_crypto \
		894fd46:golang_snappy \
		fa3f638:hashicorp_go_msgpack \
		057b893:hashicorp_raft \
		d1e82c1:hashicorp_raft_boltdb \
		475977e:influxdb_usage_client \
		07d88d4:jwilder_encoding \
		61d0dee:kimor79_gollectd \
		5a11f58:paulbellamy_ratecounter \
		ad1edfd:peterh_liner \
		274df12:rakyll_statik

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
	@${MKDIR} ${WRKSRC}/src/github.com/BurntSushi
	@${MKDIR} ${WRKSRC}/src/github.com/armon
	@${MKDIR} ${WRKSRC}/src/github.com/bmizerany
	@${MKDIR} ${WRKSRC}/src/github.com/boltdb
	@${MKDIR} ${WRKSRC}/src/collectd.org
	@${MKDIR} ${WRKSRC}/src/github.com/davecgh
	@${MKDIR} ${WRKSRC}/src/github.com/dgryski
	@${MKDIR} ${WRKSRC}/src/github.com/gogo
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp
	@${MKDIR} ${WRKSRC}/src/github.com/jwilder
	@${MKDIR} ${WRKSRC}/src/github.com/influxdb
	@${MKDIR} ${WRKSRC}/src/github.com/kimor79
	@${MKDIR} ${WRKSRC}/src/github.com/paulbellamy
	@${MKDIR} ${WRKSRC}/src/github.com/peterh
	@${MKDIR} ${WRKSRC}/src/github.com/rakyll
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/gopkg.in/fatih
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in Dockerfile LICENSE LICENSE_OF_DEPENDENCIES.md Makefile \
	build-docker.sh build.py build.sh circle-test.sh circle.yml \
	client cluster cmd errors.go etc gobuild.sh importer influxql \
	influxvar.go models monitor nightly.sh node.go 	package.sh pkg \
	scripts services shared statik stress tcp test.sh tests toml tsdb uuid
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.endfor
	@${MV} ${WRKSRC_BurntSushi_toml} ${WRKSRC}/src/github.com/BurntSushi/toml
	@${MV} ${WRKSRC_boltdb_bolt} ${WRKSRC}/src/github.com/boltdb/bolt
	@${MV} ${WRKSRC_davecgh_go_spew} ${WRKSRC}/src/github.com/davecgh/go-spew
	@${MV} ${WRKSRC_golang_crypto} ${WRKSRC}/src/golang.org/x/crypto
	@${MV} ${WRKSRC_golang_snappy} ${WRKSRC}/src/github.com/golang/snappy
	@${MV} ${WRKSRC_jwilder_encoding} ${WRKSRC}/src/github.com/jwilder/encoding
	@${MV} ${WRKSRC_influxdb_usage_client} ${WRKSRC}/src/github.com/influxdb/usage-client
	@${MV} ${WRKSRC_dgryski_go_bits} ${WRKSRC}/src/github.com/dgryski/go-bits
	@${MV} ${WRKSRC_dgryski_go_bitstream} ${WRKSRC}/src/github.com/dgryski/go-bitstream
	@${MV} ${WRKSRC_collectd_go_collectd}/api ${WRKSRC}/src/collectd.org/api
	@${MV} ${WRKSRC_collectd_go_collectd}/cdtime ${WRKSRC}/src/collectd.org/cdtime
	@${MV} ${WRKSRC_collectd_go_collectd}/exec ${WRKSRC}/src/collectd.org/exec
	@${MV} ${WRKSRC_collectd_go_collectd}/export ${WRKSRC}/src/collectd.org/export
	@${MV} ${WRKSRC_collectd_go_collectd}/format ${WRKSRC}/src/collectd.org/format
	@${MV} ${WRKSRC_collectd_go_collectd}/network ${WRKSRC}/src/collectd.org/network
	@${MV} ${WRKSRC_armon_go_metrics} ${WRKSRC}/src/github.com/armon/go-metrics
	@${MV} ${WRKSRC_hashicorp_go_msgpack} ${WRKSRC}/src/github.com/hashicorp/go-msgpack
	@${MV} ${WRKSRC_hashicorp_raft} ${WRKSRC}/src/github.com/hashicorp/raft
	@${MV} ${WRKSRC_hashicorp_raft_boltdb} ${WRKSRC}/src/github.com/hashicorp/raft-boltdb
	@${MV} ${WRKSRC_gogo_protobuf} ${WRKSRC}/src/github.com/gogo/protobuf
	@${MV} ${WRKSRC_kimor79_gollectd} ${WRKSRC}/src/github.com/kimor79/gollectd
	@${MV} ${WRKSRC_peterh_liner} ${WRKSRC}/src/github.com/peterh/liner
	@${MV} ${WRKSRC_bmizerany_pat} ${WRKSRC}/src/github.com/bmizerany/pat
	@${MV} ${WRKSRC_fatih_pool} ${WRKSRC}/src/gopkg.in/fatih/pool.v2
	@${MV} ${WRKSRC_paulbellamy_ratecounter} ${WRKSRC}/src/github.com/paulbellamy/ratecounter
	@${MV} ${WRKSRC_rakyll_statik} ${WRKSRC}/src/github.com/rakyll/statik

do-build:
		@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/ &&  ${SETENV} GOPATH=${WRKSRC} go install ./...

do-install:
		${MKDIR} ${STAGEDIR}${INFLUXD_DBDIR} \
		${STAGEDIR}${INFLUXD_PIDDIR} \
		${STAGEDIR}${INFLUXD_LOGDIR}

post-install:
		${INSTALL_PROGRAM} ${WRKSRC}/bin/influxd ${STAGEDIR}${PREFIX}/bin/influxd
		${INSTALL_PROGRAM} ${WRKSRC}/bin/influx ${STAGEDIR}${PREFIX}/bin/influx
		${INSTALL_PROGRAM} ${WRKSRC}/bin/influx_inspect ${STAGEDIR}${PREFIX}/bin/influx_inspect
		${INSTALL_PROGRAM} ${WRKSRC}/bin/influx_tsm ${STAGEDIR}${PREFIX}/bin/influx_tsm
		@${SED} -i .bak -e \
			"s|/tmp/influxdb/development|/var/db/influxdb|g" \
			${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/etc/config.sample.toml
		${INSTALL_DATA} \
			${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/etc/config.sample.toml  \
			${STAGEDIR}${PREFIX}/etc/influxd.conf.sample
		@${MKDIR} ${STAGEDIR}/var/db/influxdb
		@${MKDIR} ${STAGEDIR}/var/log/influxdb

.include <bsd.port.mk>
