# $FreeBSD$

PORTNAME=	influxdb
PORTVERSION=	1.1.0
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
GH_TUPLE=	BurntSushi:toml:9906417:toml \
		bmizerany:pat:c068ca2:pat \
		boltdb:bolt:5cc10bb:bolt \
		davecgh:go-spew:5215b55:go_spew \
		dgrijalva:jwt-go:63734ea:jwt_go \
		dgryski:go-bits:2ad8d70:go_bits \
		dgryski:go-bitstream:7d46cd2:go_bitstream \
		gogo:protobuf:0394392:protobuf \
		golang:snappy:d9eb7a3:snappy \
		influxdata:usage-client:6d38953:usage_client \
		jwilder:encoding:4dada27:encoding \
		kimor79:gollectd:61d0dee:gollectd \
		paulbellamy:ratecounter:5a11f58:ratecounter \
		peterh:liner:8975875:liner \
		rakyll:statik:274df12:statik \
		retailnext:hllpp:38a7bb7:hllpp \
		collectd:go-collectd:9fc824c:go_collectd \
 		golang:crypto:c197bcf:crypto

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
	@${MKDIR} ${WRKSRC}/src/github.com/bmizerany
	@${MKDIR} ${WRKSRC}/src/github.com/boltdb
	@${MKDIR} ${WRKSRC}/src/github.com/davecgh
	@${MKDIR} ${WRKSRC}/src/github.com/dgrijalva
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
	@${MKDIR} ${WRKSRC}/src/github.com/retailnext
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/gopkg.in/fatih
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
	@cd ${WRKSRC} && \
		${MV} LICENSE build.sh gobuild.sh node.go tests \
		circle-test.sh importer package.sh toml \
		Dockerfile Makefile circle.yml influxdb.go pkg tsdb \
		Dockerfile_build_ubuntu32 client influxql scripts uuid \
		Dockerfile_build_ubuntu64 cmd man services \
		.mention-bot Dockerfile_build_ubuntu64_git appveyor.yml coordinator models stress \
		Dockerfile_test_ubuntu32 build-docker.sh errors.go monitor tcp \
		Godeps build.py etc nightly.sh test.sh \
 		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
	@${MV} ${WRKSRC_toml} ${WRKSRC}/src/github.com/BurntSushi/toml
	@${MV} ${WRKSRC_pat} ${WRKSRC}/src/github.com/bmizerany/pat
	@${MV} ${WRKSRC_bolt} ${WRKSRC}/src/github.com/boltdb/bolt
	@${MV} ${WRKSRC_go_spew} ${WRKSRC}/src/github.com/davecgh/go-spew
	@${MV} ${WRKSRC_jwt_go} ${WRKSRC}/src/github.com/dgrijalva/jwt-go
	@${MV} ${WRKSRC_go_bits} ${WRKSRC}/src/github.com/dgryski/go-bits
	@${MV} ${WRKSRC_go_bitstream} ${WRKSRC}/src/github.com/dgryski/go-bitstream
	@${MV} ${WRKSRC_protobuf} ${WRKSRC}/src/github.com/gogo/protobuf
	@${MV} ${WRKSRC_snappy} ${WRKSRC}/src/github.com/golang/snappy
	@${MV} ${WRKSRC_usage_client} ${WRKSRC}/src/github.com/influxdata/usage-client
	@${MV} ${WRKSRC_encoding} ${WRKSRC}/src/github.com/jwilder/encoding
	@${MV} ${WRKSRC_gollectd} ${WRKSRC}/src/github.com/kimor79/gollectd
	@${MV} ${WRKSRC_ratecounter} ${WRKSRC}/src/github.com/paulbellamy/ratecounter
	@${MV} ${WRKSRC_liner} ${WRKSRC}/src/github.com/peterh/liner
	@${MV} ${WRKSRC_statik} ${WRKSRC}/src/github.com/rakyll/statik
	@${MV} ${WRKSRC_hllpp} ${WRKSRC}/src/github.com/retailnext/hllpp
	@${MV} ${WRKSRC_go_collectd} ${WRKSRC}/src/collectd.org
	@${MV} ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto

do-build:
		@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT} && \
			${SETENV} GOPATH=${WRKSRC} go install -ldflags "-X main.version=${DISTVERSION}" ./...

do-install:
		${MKDIR} ${STAGEDIR}${INFLUXD_DBDIR} \
		${STAGEDIR}${INFLUXD_PIDDIR} \
		${STAGEDIR}${INFLUXD_LOGDIR}
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
