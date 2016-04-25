# $FreeBSD$

PORTNAME=	influxdb
PORTVERSION=	0.12.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases net-mgmt

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Open-source distributed time series database

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.5.0:lang/go

ONLY_FOR_ARCHS=	i386 amd64

USE_RC_SUBR=	influxd

USE_GITHUB=	yes
GH_ACCOUNT=	influxdata:DEFAULT
GH_TUPLE=	BurntSushi:toml:bbd5bb6:toml \
		armon:go-metrics:f303b03:go_metrics \
		bmizerany:pat:c068ca2:pat \
		boltdb:bolt:144418e:bolt \
		dgryski:go-bits:86c69b3:go_bits \
		dgryski:go-bitstream:27cd597:go_bitstream \
		gogo:protobuf:74b6e9d:protobuf \
		golang:snappy:ef80b33:snappy \
		hashicorp:go-msgpack:fa3f638:go_msgpack \
		hashicorp:raft:1c84b7c:raft \
		hashicorp:raft-boltdb:d1e82c1:raft_boltdb \
		influxdata:usage-client:475977e:usage_client \
		jwilder:encoding:07d88d4:encoding \
		kimor79:gollectd:b5dddb1:gollectd \
		paulbellamy:ratecounter:5a11f58:ratecounter \
		peterh:liner:49ca659:liner \
		rakyll:statik:2940084:statik \
		collectd:go-collectd:9fc824c:go_collectd \
 		golang:crypto:3fbbcd2:crypto \
		fatih:pool:cba550e:pool

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
	@${MKDIR} ${WRKSRC}/src/github.com/dgryski
	@${MKDIR} ${WRKSRC}/src/github.com/gogo
	@${MKDIR} ${WRKSRC}/src/github.com/golang
	@${MKDIR} ${WRKSRC}/src/github.com/hashicorp
	@${MKDIR} ${WRKSRC}/src/github.com/influxdata
	@${MKDIR} ${WRKSRC}/src/github.com/jwilder
	@${MKDIR} ${WRKSRC}/src/github.com/kimor79
	@${MKDIR} ${WRKSRC}/src/github.com/paulbellamy
	@${MKDIR} ${WRKSRC}/src/github.com/peterh
	@${MKDIR} ${WRKSRC}/src/github.com/rakyll
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/gopkg.in/fatih
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
	@cd ${WRKSRC} && \
		${MV} CHANGELOG.md CODING_GUIDELINES.md CONTRIBUTING.md DOCKER.md \
		Dockerfile Dockerfile_build_ubuntu32 Dockerfile_build_ubuntu64 \
		Dockerfile_build_ubuntu64_git Dockerfile_test_ubuntu32 Godeps LICENSE \
		LICENSE_OF_DEPENDENCIES.md Makefile QUERIES.md README.md build-docker.sh \
		build.py build.sh circle-test.sh circle.yml client cluster \
		cmd errors.go etc gobuild.sh importer influxdb.go influxql \
		influxvar.go models monitor nightly.sh node.go package.sh pkg scripts \
		services stress tcp test.sh tests toml tsdb uuid \
 		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
	@${MV} ${WRKSRC_toml} ${WRKSRC}/src/github.com/BurntSushi/toml
	@${MV} ${WRKSRC_go_metrics} ${WRKSRC}/src/github.com/armon/go-metrics
	@${MV} ${WRKSRC_pat} ${WRKSRC}/src/github.com/bmizerany/pat
	@${MV} ${WRKSRC_bolt} ${WRKSRC}/src/github.com/boltdb/bolt
	@${MV} ${WRKSRC_go_bits} ${WRKSRC}/src/github.com/dgryski/go-bits
	@${MV} ${WRKSRC_go_bitstream} ${WRKSRC}/src/github.com/dgryski/go-bitstream
	@${MV} ${WRKSRC_protobuf} ${WRKSRC}/src/github.com/gogo/protobuf
	@${MV} ${WRKSRC_snappy} ${WRKSRC}/src/github.com/golang/snappy
	@${MV} ${WRKSRC_go_msgpack} ${WRKSRC}/src/github.com/hashicorp/go-msgpack
	@${MV} ${WRKSRC_raft} ${WRKSRC}/src/github.com/hashicorp/raft
	@${MV} ${WRKSRC_raft_boltdb} ${WRKSRC}/src/github.com/hashicorp/raft-boltdb
	@${MV} ${WRKSRC_usage_client} ${WRKSRC}/src/github.com/influxdata/usage-client
	@${MV} ${WRKSRC_encoding} ${WRKSRC}/src/github.com/jwilder/encoding
	@${MV} ${WRKSRC_gollectd} ${WRKSRC}/src/github.com/kimor79/gollectd
	@${MV} ${WRKSRC_ratecounter} ${WRKSRC}/src/github.com/paulbellamy/ratecounter
	@${MV} ${WRKSRC_liner} ${WRKSRC}/src/github.com/peterh/liner
	@${MV} ${WRKSRC_statik} ${WRKSRC}/src/github.com/rakyll/statik
	@${MV} ${WRKSRC_go_collectd} ${WRKSRC}/src/collectd.org
	@${MV} ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto
	@${MV} ${WRKSRC_pool} ${WRKSRC}/src/gopkg.in/fatih/pool.v2

do-build:
		@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT} && ${SETENV} GOPATH=${WRKSRC} go install ./...

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
