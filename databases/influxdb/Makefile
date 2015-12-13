# $FreeBSD$

PORTNAME=	influxdb
PORTVERSION=	0.9.6
DISTVERSIONPREFIX=	v
CATEGORIES=	databases net-mgmt

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Open-source distributed time series database

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.5.0:${PORTSDIR}/lang/go

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
		collectd:go_collectd \
		dgryski:go_bits,go_bitstream \
		fatih:pool \
		gogo:gogo_protobuf \
		golang:golang_protobuf,golang_snappy \
		hashicorp:raft,raft_boltdb,go_msgpack \
		influxdb:enterprise_client \
		jwilder:encoding \
		kimor79:gollectd \
		peterh:liner \
		rakyll:statik \
		paulbellamy:ratecounter
GH_PROJECT=	bolt:bolt crypto:crypto encoding:encoding \
		enterprise-client:enterprise_client go-bits:go_bits \
		go-bitstream:go_bitstream go-collectd:go_collectd \
		go-metrics:go_metrics go-msgpack:go_msgpack gollectd:gollectd \
		liner:liner log4go:log4go pat:pat pool:pool \
		protobuf:gogo_protobuf protobuf:golang_protobuf \
		raft-boltdb:raft_boltdb raft:raft ratecounter:ratecounter \
		snappy:golang_snappy, statik:statik toml:toml go-uuid:go_uuid
GH_TAGNAME=	b34b35e:bolt 056c9bc:toml 1351f93:crypto 4d47685:liner \
		5c3c713:log4go 274df12:statik e492fd3:gogo_protobuf \
		61d0dee:gollectd 68415e7:golang_protobuf 06b6099:go_metrics \
		b8a3500:pat cba550e:pool d1e82c1:raft_boltdb ed3ca8a:go_uuid \
		d136cd1:raft fa3f638:go_msgpack 723cc1e:golang_snappy \
		9fc824c:go_collectd 86c69b3:go_bits 27cd597:go_bitstream \
		07d88d4:encoding 25665cb:enterprise_client 5a11f58:ratecounter

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
	@${MKDIR} ${WRKSRC}/src/collectd.org
	@${MKDIR} ${WRKSRC}/src/github.com/dgryski
	@${MKDIR} ${WRKSRC}/src/github.com/fatih
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
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in LICENSE_OF_DEPENDENCIES.md Makefile build-docker.sh build.py \
	circle-test.sh circle.yml client cluster cmd errors.go etc importer \
	influxql influxvar.go meta models monitor nightly.sh package.sh \
	pkg scripts services shared snapshot statik stress tcp \
	test-32bit-docker.sh tests toml tsdb uuid
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.endfor
	@${MV} ${WRKSRC_bolt} ${WRKSRC}/src/github.com/boltdb/bolt
	@${MV} ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto
	@${MV} ${WRKSRC_encoding} ${WRKSRC}/src/github.com/jwilder/encoding
	@${MV} ${WRKSRC_enterprise_client} ${WRKSRC}/src/github.com/influxdb/enterprise-client
	@${MV} ${WRKSRC_go_bits} ${WRKSRC}/src/github.com/dgryski/go-bits
	@${MV} ${WRKSRC_go_bitstream} ${WRKSRC}/src/github.com/dgryski/go-bitstream
	@${MV} ${WRKSRC_go_collectd}/api ${WRKSRC}/src/collectd.org/api
	@${MV} ${WRKSRC_go_collectd}/network ${WRKSRC}/src/collectd.org/network
	@${MV} ${WRKSRC_go_collectd}/cdtime ${WRKSRC}/src/collectd.org/cdtime
	@${MV} ${WRKSRC_go_metrics} ${WRKSRC}/src/github.com/armon/go-metrics
	@${MV} ${WRKSRC_go_uuid} ${WRKSRC}/src/code.google.com/p/go-uuid
	@${MV} ${WRKSRC_go_msgpack} ${WRKSRC}/src/github.com/hashicorp/go-msgpack
	@${MV} ${WRKSRC_gogo_protobuf} ${WRKSRC}/src/github.com/gogo/protobuf
	@${MV} ${WRKSRC_golang_protobuf} ${WRKSRC}/src/github.com/golang/protobuf
	@${MV} ${WRKSRC_gollectd} ${WRKSRC}/src/github.com/kimor79/gollectd
	@${MV} ${WRKSRC_liner} ${WRKSRC}/src/github.com/peterh/liner
	@${MV} ${WRKSRC_log4go} ${WRKSRC}/src/code.google.com/p/log4go
	@${MV} ${WRKSRC_pat} ${WRKSRC}/src/github.com/bmizerany/pat
	@${MV} ${WRKSRC_pool} ${WRKSRC}/src/github.com/fatih/pool
	@${MV} ${WRKSRC_raft_boltdb} ${WRKSRC}/src/github.com/hashicorp/raft-boltdb
	@${MV} ${WRKSRC_raft} ${WRKSRC}/src/github.com/hashicorp/raft
	@${MV} ${WRKSRC_ratecounter} ${WRKSRC}/src/github.com/paulbellamy/ratecounter
	@${MV} ${WRKSRC_statik} ${WRKSRC}/src/github.com/rakyll/statik
	@${MV} ${WRKSRC_golang_snappy} ${WRKSRC}/src/github.com/golang/snappy
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
