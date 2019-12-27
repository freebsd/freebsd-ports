# $FreeBSD$

PORTNAME=	usql
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.7-6
DISTVERSIONSUFFIX=	-ga2978c0
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal command-line interface for SQL databases

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	xo
GH_TUPLE=	\
		ClickHouse:clickhouse-go:v1.3.12:clickhouse_clickhouse_go/vendor/github.com/ClickHouse/clickhouse-go \
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		MichaelS11:go-cql-driver:cf3b3196aa43:michaels11_go_cql_driver/vendor/github.com/MichaelS11/go-cql-driver \
		SAP:go-hdb:v0.14.1:sap_go_hdb/vendor/github.com/SAP/go-hdb \
		SermoDigital:jose:803625baeddc:sermodigital_jose/vendor/github.com/SermoDigital/jose \
		VoltDB:voltdb-client-go:v1.0.1:voltdb_voltdb_client_go/vendor/github.com/VoltDB/voltdb-client-go \
		alecthomas:chroma:v0.7.0:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/github.com/alecthomas/kingpin \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:f65c72e2690d:alecthomas_units/vendor/github.com/alecthomas/units \
		alexbrainman:odbc:cf37ce290779:alexbrainman_odbc/vendor/github.com/alexbrainman/odbc \
		amsokol:ignite-go-client:v0.12.2:amsokol_ignite_go_client/vendor/github.com/amsokol/ignite-go-client \
		apache:calcite-avatica-go:v4.0.0:apache_calcite_avatica_go/vendor/github.com/apache/calcite-avatica-go/v4 \
		cloudflare:golz4:ef862a3cdc58:cloudflare_golz4/vendor/github.com/cloudflare/golz4 \
		couchbase:go-couchbase:b2754d72cc98:couchbase_go_couchbase/vendor/github.com/couchbase/go-couchbase \
		couchbase:go_n1ql:6cf4e348b127:couchbase_go_n1ql/vendor/github.com/couchbase/go_n1ql \
		couchbase:gomemcached:7b5da2ec40b2:couchbase_gomemcached/vendor/github.com/couchbase/gomemcached \
		couchbase:goutils:b49639060d85:couchbase_goutils/vendor/github.com/couchbase/goutils \
		cznic:mathutil:297441e03548:cznic_mathutil/vendor/github.com/cznic/mathutil \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		denisenkom:go-mssqldb:1d7a30a10f73:denisenkom_go_mssqldb/vendor/github.com/denisenkom/go-mssqldb \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		edsrzf:mmap-go:v1.0.0:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-sql-driver:mysql:v1.4.1:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		gocql:gocql:1982a06ad6b9:gocql_gocql/vendor/github.com/gocql/gocql \
		godror:godror:v0.9.1:godror_godror/vendor/github.com/godror/godror \
		gohxs:readline:a780388e6e7c:gohxs_readline/vendor/github.com/gohxs/readline \
		golang-sql:civil:cb61b32ac6fe:golang_sql_civil/vendor/github.com/golang-sql/civil \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:e9b2fee46413:golang_crypto/vendor/golang.org/x/crypto \
		golang:glog:23def4e6c14b:golang_glog/vendor/github.com/golang/glog \
		golang:net:c0dbc17a3553:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:4a24b4065292:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		hailocab:go-hostpool:e80d13ce29ed:hailocab_go_hostpool/vendor/github.com/hailocab/go-hostpool \
		hashicorp:go-uuid:v1.0.1:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		jackc:pgx:v3.6.0:jackc_pgx/vendor/github.com/jackc/pgx \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:goidentity:v3.0.0:jcmturner_goidentity/vendor/gopkg.in/jcmturner/goidentity.v3 \
		jcmturner:gokrb5:v6.1.1:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v6 \
		jcmturner:gokrb5:v7.3.0:jcmturner_gokrb5_1/vendor/gopkg.in/jcmturner/gokrb5.v7 \
		jcmturner:rpc:v1.1.0:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v1 \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		lib:pq:v1.3.0:lib_pq/vendor/github.com/lib/pq \
		mattn:go-adodb:v0.0.1:mattn_go_adodb/vendor/github.com/mattn/go-adodb \
		mattn:go-isatty:v0.0.11:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v2.0.2:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		nakagami:firebirdsql:8048f7ca3088:nakagami_firebirdsql/vendor/github.com/nakagami/firebirdsql \
		pkg:browser:0a3d74bf9ce4:pkg_browser/vendor/github.com/pkg/browser \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		prestodb:presto-go-client:4980913e2459:prestodb_presto_go_client/vendor/github.com/prestodb/presto-go-client \
		remyoudompheng:bigfft:6a916e37a237:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft \
		shopspring:decimal:360f2bc03045:shopspring_decimal/vendor/github.com/shopspring/decimal \
		snowflakedb:gosnowflake:v1.3.3:snowflakedb_gosnowflake/vendor/github.com/snowflakedb/gosnowflake \
		spaolacci:murmur3:v1.1.0:spaolacci_murmur3/vendor/github.com/spaolacci/murmur3 \
		thda:tds:v0.1.7:thda_tds/vendor/github.com/thda/tds \
		vertica:vertica-sql-go:v0.1.6:vertica_vertica_sql_go/vendor/github.com/vertica/vertica-sql-go \
		xinsnake:go-http-digest-auth-client:v0.4.0:xinsnake_go_http_digest_auth_client/vendor/github.com/xinsnake/go-http-digest-auth-client \
		xo:dburl:3cca8608d645:xo_dburl/vendor/github.com/xo/dburl \
		xo:tblfmt:4c686ae34009:xo_tblfmt/vendor/github.com/xo/tblfmt \
		xo:terminfo:1a4775eeeb62:xo_terminfo/vendor/github.com/xo/terminfo \
		xo:xoutil:46189f4026a5:xo_xoutil/vendor/github.com/xo/xoutil \
		zaf:temp:94e385923345:zaf_temp/vendor/github.com/zaf/temp \
		ziutek:mymysql:v1.5.4:ziutek_mymysql/vendor/github.com/ziutek/mymysql
USE_GITLAB=	nodefault
GL_TUPLE=	\
		nyarla:go-crypt:d9a5dc2b789bc330075d4b805d9b7c971f2865a1:nyarla_go_crypt/vendor/gitlab.com/nyarla/go-crypt

PLIST_FILES=	bin/usql

.include <bsd.port.mk>
