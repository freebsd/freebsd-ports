PORTNAME=	blocky
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17
CATEGORIES=	dns

MAINTAINER=	gregf@beastie.tech
COMMENT=	Fast and lightweight DNS proxy as ad-blocker

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	0xERR0R
USE_RC_SUBR=	blocky

GH_TUPLE=       \
		0xERR0R:go-cache:v1.6.0:0xerr0r_go_cache/vendor/github.com/0xERR0R/go-cache \
		KyleBanks:depth:v1.2.1:kylebanks_depth/vendor/github.com/KyleBanks/depth \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		asaskevich:EventBus:49d423059eef:asaskevich_eventbus/vendor/github.com/asaskevich/EventBus \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		creasty:defaults:v1.5.2:creasty_defaults/vendor/github.com/creasty/defaults \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-chi:chi:v4.1.2:go_chi_chi/vendor/github.com/go-chi/chi \
		go-chi:cors:v1.2.0:go_chi_cors/vendor/github.com/go-chi/cors \
		go-gorm:gorm:v1.22.2:go_gorm_gorm/vendor/gorm.io/gorm \
		go-gorm:mysql:v1.1.3:go_gorm_mysql/vendor/gorm.io/driver/mysql \
		go-gorm:sqlite:v1.2.3:go_gorm_sqlite/vendor/gorm.io/driver/sqlite \
		go-openapi:jsonpointer:v0.19.5:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.5:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:spec:v0.20.3:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:swag:v0.19.14:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-sql-driver:mysql:v1.6.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:c07d793c2f9a:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:89ef3d95e781:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:0f9fa26af87c:golang_sys/vendor/golang.org/x/sys \
		golang:term:7de9c90e9dd1:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.2:golang_tools/vendor/golang.org/x/tools \
		hako:durafmt:5c1018a4e16b:hako_durafmt/vendor/github.com/hako/durafmt \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jinzhu:inflection:v1.0.0:jinzhu_inflection/vendor/github.com/jinzhu/inflection \
		jinzhu:now:v1.1.2:jinzhu_now/vendor/github.com/jinzhu/now \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		mailru:easyjson:v0.7.6:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v1.14.9:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		miekg:dns:v1.1.43:miekg_dns/vendor/github.com/miekg/dns \
		mroth:weightedrand:v0.4.1:mroth_weightedrand/vendor/github.com/mroth/weightedrand \
		nxadm:tail:v1.4.8:nxadm_tail/vendor/github.com/nxadm/tail \
		onsi:ginkgo:v1.16.5:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.17.0:onsi_gomega/vendor/github.com/onsi/gomega \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.26.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v1.2.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		swaggo:swag:v1.7.4:swaggo_swag/vendor/github.com/swaggo/swag \
		x-cray:logrus-prefixed-formatter:v0.5.2:x_cray_logrus_prefixed_formatter/vendor/github.com/x-cray/logrus-prefixed-formatter

GO_TARGET=	main.go:${PREFIX}/sbin/${PORTNAME}

SUB_FILES=	pkg-message

post-install:
		${INSTALL_DATA} ${FILESDIR}/blocky-config.yml.sample ${STAGEDIR}${PREFIX}/etc/blocky-config.yml.sample

.include <bsd.port.mk>
