PORTNAME=	blocky
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18
CATEGORIES=	dns

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast and lightweight DNS proxy as ad-blocker

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	0xERR0R
USE_RC_SUBR=	blocky

GH_TUPLE=	\
		KyleBanks:depth:v1.2.1:kylebanks_depth/vendor/github.com/KyleBanks/depth \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alicebob:gopher-json:a9ecdc9d1d3a:alicebob_gopher_json/vendor/github.com/alicebob/gopher-json \
		alicebob:miniredis:v2.18.0:alicebob_miniredis_v2/vendor/github.com/alicebob/miniredis/v2 \
		asaskevich:EventBus:49d423059eef:asaskevich_eventbus/vendor/github.com/asaskevich/EventBus \
		avast:retry-go:v4.0.3:avast_retry_go_v4/vendor/github.com/avast/retry-go/v4 \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		creasty:defaults:v1.5.2:creasty_defaults/vendor/github.com/creasty/defaults \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		fsnotify:fsnotify:v1.5.1:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-chi:chi:v5.0.7:go_chi_chi_v5/vendor/github.com/go-chi/chi/v5 \
		go-chi:cors:v1.2.0:go_chi_cors/vendor/github.com/go-chi/cors \
		go-gorm:gorm:v1.22.5:go_gorm_gorm/vendor/gorm.io/gorm \
		go-gorm:mysql:v1.2.3:go_gorm_mysql/vendor/gorm.io/driver/mysql \
		go-gorm:postgres:v1.2.3:go_gorm_postgres/vendor/gorm.io/driver/postgres \
		go-gorm:sqlite:v1.2.6:go_gorm_sqlite/vendor/gorm.io/driver/sqlite \
		go-openapi:jsonpointer:v0.19.5:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.6:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:spec:v0.20.4:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:swag:v0.19.15:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-redis:redis:v8.11.4:go_redis_redis_v8/vendor/github.com/go-redis/redis/v8 \
		go-sql-driver:mysql:v1.6.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:4570a0811e8b:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.5.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:491a49abca63:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:da31bd327af9:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.7:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		hako:durafmt:5c1018a4e16b:hako_durafmt/vendor/github.com/hako/durafmt \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jackc:chunkreader:v2.0.1:jackc_chunkreader_v2/vendor/github.com/jackc/chunkreader/v2 \
		jackc:pgconn:v1.10.1:jackc_pgconn/vendor/github.com/jackc/pgconn \
		jackc:pgio:v1.0.0:jackc_pgio/vendor/github.com/jackc/pgio \
		jackc:pgpassfile:v1.0.0:jackc_pgpassfile/vendor/github.com/jackc/pgpassfile \
		jackc:pgproto3:v2.2.0:jackc_pgproto3_v2/vendor/github.com/jackc/pgproto3/v2 \
		jackc:pgservicefile:2b9c44734f2b:jackc_pgservicefile/vendor/github.com/jackc/pgservicefile \
		jackc:pgtype:v1.9.0:jackc_pgtype/vendor/github.com/jackc/pgtype \
		jackc:pgx:v4.14.0:jackc_pgx_v4/vendor/github.com/jackc/pgx/v4 \
		jinzhu:inflection:v1.0.0:jinzhu_inflection/vendor/github.com/jinzhu/inflection \
		jinzhu:now:v1.1.4:jinzhu_now/vendor/github.com/jinzhu/now \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		mailru:easyjson:v0.7.6:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-colorable:v0.1.12:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v1.14.9:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		miekg:dns:v1.1.46:miekg_dns/vendor/github.com/miekg/dns \
		mroth:weightedrand:v0.4.1:mroth_weightedrand/vendor/github.com/mroth/weightedrand \
		nxadm:tail:v1.4.8:nxadm_tail/vendor/github.com/nxadm/tail \
		onsi:ginkgo:v1.16.5:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.18.1:onsi_gomega/vendor/github.com/onsi/gomega \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.12.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v1.3.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:objx:v0.3.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		swaggo:swag:v1.7.8:swaggo_swag/vendor/github.com/swaggo/swag \
		x-cray:logrus-prefixed-formatter:v0.5.2:x_cray_logrus_prefixed_formatter/vendor/github.com/x-cray/logrus-prefixed-formatter \
		yuin:gopher-lua:ee81675732da:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

GO_TARGET=	main.go:${PREFIX}/sbin/${PORTNAME}

SUB_FILES=	pkg-message

post-install:
		${INSTALL_DATA} ${FILESDIR}/blocky-config.yml.sample ${STAGEDIR}${PREFIX}/etc/blocky-config.yml.sample

.include <bsd.port.mk>
