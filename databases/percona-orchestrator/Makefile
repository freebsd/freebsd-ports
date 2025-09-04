PORTNAME=	orchestrator
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.6-16
PORTREVISION=	5
CATEGORIES=	databases
PKGNAMEPREFIX=	percona-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Replication topology manager for MySQL
WWW=		https://github.com/percona/orchestrator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash>0:shells/bash \
		gsed>0:textproc/gsed \
		jq>0:textproc/jq

USES=		go mysql:server shebangfix

USERS=		percona
GROUPS=		percona

USE_GITHUB=	yes
GH_ACCOUNT=	percona
USE_RC_SUBR=	${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	pkg-message
SHEBANG_FILES=	resources/bin/orchestrator-client

GO_PKGNAME=	github.com/openark/${PORTNAME}
GO_TARGET=	./go/cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags '-X main.AppVersion=${DISTVERSION} -X main.BuildDescribe=${DISTVERSION}'

GH_TUPLE=	\
		Showmax:go-fqdn:v1.0.0:showmax_go_fqdn/vendor/github.com/Showmax/go-fqdn \
		armon:consul-api:eb2c6b5be1b6:armon_consul_api/vendor/github.com/armon/consul-api \
		armon:go-metrics:f0300d1749da:armon_go_metrics/vendor/github.com/armon/go-metrics \
		codegangsta:inject:33e0aa1cb7c0:codegangsta_inject/vendor/github.com/codegangsta/inject \
		cyberdelia:go-metrics-graphite:39f87cc3b432:cyberdelia_go_metrics_graphite/vendor/github.com/cyberdelia/go-metrics-graphite \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		go-gcfg:gcfg:v1.2.3:go_gcfg_gcfg/vendor/gopkg.in/gcfg.v1 \
		go-martini:martini:22fa46961aab:go_martini_martini/vendor/github.com/go-martini/martini \
		go-sql-driver:mysql:v1.7.1:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		golang:crypto:630584e8d5aa:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:bea034e7d591:golang_net/vendor/golang.org/x/net \
		golang:sys:3c1f35247d10:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.8:golang_text/vendor/golang.org/x/text \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		hashicorp:consul:v1.7.0:hashicorp_consul_api/vendor/github.com/hashicorp/consul \
		hashicorp:go-cleanhttp:d3fcbee8e181:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-hclog:59fbd7b93270:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.3.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-msgpack:v0.5.3:hashicorp_go_msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-rootcerts:c8a9a31cbd76:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:serf:v0.9.5:hashicorp_serf/vendor/github.com/hashicorp/serf \
		howeyc:gopass:7cb4b85ec19c:howeyc_gopass/vendor/github.com/howeyc/gopass \
		martini-contrib:auth:fa62c19b7ae8:martini_contrib_auth/vendor/github.com/martini-contrib/auth \
		martini-contrib:gzip:6c035326b43f:martini_contrib_gzip/vendor/github.com/martini-contrib/gzip \
		martini-contrib:render:ec18f8345a11:martini_contrib_render/vendor/github.com/martini-contrib/render \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:cb30d6282491:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v1.14.7:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		miekg:dns:v1.1.31:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-testing-interface:v1.14.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:mapstructure:v1.3.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		montanaflynn:stats:f8cd06f93c6c:montanaflynn_stats/vendor/github.com/montanaflynn/stats \
		openark:golib:827f3ea62180:openark_golib \
		openark:raft:fba9f909f7fe:openark_raft/vendor/github.com/hashicorp/raft \
		outbrain:golib:2531e5dbcc71:outbrain_golib/vendor/github.com/outbrain/golib \
		oxtoacart:bpool:03653db5a59c:oxtoacart_bpool/vendor/github.com/oxtoacart/bpool \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		rcrowley:go-metrics:cf1acfcdf475:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		samuel:go-zookeeper:7117e9ea2414:samuel_go_zookeeper/vendor/github.com/samuel/go-zookeeper \
		sjmudd:stopwatch:637ef30077b7:sjmudd_stopwatch/vendor/github.com/sjmudd/stopwatch \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify

post-extract:
	@${RLN} ${WRKSRC_openark_golib} ${WRKSRC}/go/golib

post-patch:
	@${REINPLACE_CMD} -e 's|"resources|"${DATADIR}|g' ${WRKSRC}/go/app/http.go

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/resources/bin/orchestrator-client ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}/resources/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/conf/orchestrator-simple.conf.json \
		${STAGEDIR}${ETCDIR}/orchestrator.conf.sample

.include <bsd.port.mk>
