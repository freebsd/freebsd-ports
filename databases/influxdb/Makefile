# $FreeBSD$

PORTNAME=	influxdb
PORTVERSION=	1.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	databases net-mgmt

MAINTAINER=	cheffo@freebsd-bg.org
COMMENT=	Open-source distributed time series database

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 armv6 i386

BUILD_DEPENDS=	go>=1.8.1:lang/go

USE_RC_SUBR=	influxd

USE_GITHUB=	yes
GH_ACCOUNT=	influxdata:DEFAULT
GH_TUPLE=	BurntSushi:toml:9906417:toml/src/github.com/BurntSushi/toml \
		bmizerany:pat:c068ca2:pat/src/github.com/bmizerany/pat \
		boltdb:bolt:4b1ebc1:bolt/src/github.com/boltdb/bolt \
		cespare:xxhash:4a94f89:xxhash/src/github.com/cespare/xxhash \
		davecgh:go-spew:346938d:go_spew/src/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:24c63f5:jwt_go/src/github.com/dgrijalva/jwt-go \
		dgryski:go-bits:2ad8d70:go_bits/src/github.com/dgryski/go-bits \
		dgryski:go-bitstream:7d46cd2:go_bitstream/src/github.com/dgryski/go-bitstream \
		gogo:protobuf:3043356:protobuf/src/github.com/gogo/protobuf \
		golang:snappy:d9eb7a3:snappy/src/github.com/golang/snappy \
		influxdata:usage-client:6d38953:usage_client/src/github.com/influxdata/usage-client \
		jwilder:encoding:278947:encoding/src/github.com/jwilder/encoding \
		paulbellamy:ratecounter:5a11f58:ratecounter/src/github.com/paulbellamy/ratecounter \
		peterh:liner:8860952:liner/src/github.com/peterh/liner \
		retailnext:hllpp:38a7bb7:hllpp/src/github.com/retailnext/hllpp \
		spaolacci:murmur3:0d12bf8:murmur3/src/github.com/spaolacci/murmur3 \
		collectd:go-collectd:e84e8af:go_collectd/src/collectd.org \
		uber-go:atomic:74ca5ec:atomic/src/github.com/uber-go/atomic \
		uber-go:zap:fbae028:zap/src/github.com/uber-go/zap \
		golang:crypto:9477e0b:crypto/src/golang.org/x/crypto

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

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
	@cd ${WRKSRC} && \
		${MV} appveyor.yml build.py build.sh CHANGELOG.md \
		circle-test.sh circle.yml client cmd CODING_GUIDELINES.md \
		CONTRIBUTING.md coordinator \
		Dockerfile_build_ubuntu32 Dockerfile_build_ubuntu64 \
		Dockerfile_build_ubuntu64_git Dockerfile_test_ubuntu32 \
		errors.go etc gobuild.sh Godeps importer influxdb.go influxql \
		internal LICENSE_OF_DEPENDENCIES.md Makefile man models \
		monitor nightly.sh node.go pkg QUERIES.md README.md \
		scripts services stress tcp test.sh tests TODO.md toml tsdb uuid \
 		${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}

do-build:
		@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT} && \
			${SETENV} GOPATH=${WRKSRC} go install -ldflags "-X main.version=${DISTVERSION}" ./...

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
		@${SED} -i .bak -e \
			"s|/var/lib/influxdb|/var/db/influxdb|g" \
			${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT}/etc/config.sample.toml
		${INSTALL_DATA} \
			${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT}/etc/config.sample.toml  \
			${STAGEDIR}${PREFIX}/etc/influxd.conf.sample

do-install-MANPAGES-on:
.for i in influx.1 influx_inspect.1 influx_stress.1 influx_tsm.1 \
	influxd-backup.1 influxd-config.1 influxd-restore.1 \
	influxd-run.1 influxd-version.1 influxd.1
		${INSTALL_MAN} ${WRKSRC}/src/github.com/influxdata/influxdb/man/$i ${STAGEDIR}${MAN8PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
