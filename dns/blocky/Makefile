PORTNAME=	blocky
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14
CATEGORIES=	dns

MAINTAINER=	gregf@beastie.tech
COMMENT=	Fast and lightweight DNS proxy as ad-blocker

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	0xERR0R
USE_RC_SUBR=	blocky

GH_TUPLE=	\
		asaskevich:EventBus:49d423059eef:asaskevich_eventbus/vendor/github.com/asaskevich/EventBus \
		asaskevich:govalidator:f61b66f89f4a:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-chi:chi:v4.1.2:go_chi_chi/vendor/github.com/go-chi/chi \
		go-chi:cors:v1.2.0:go_chi_cors/vendor/github.com/go-chi/cors \
		go-openapi:errors:v0.19.2:go_openapi_errors/vendor/github.com/go-openapi/errors \
		go-openapi:strfmt:v0.19.4:go_openapi_strfmt/vendor/github.com/go-openapi/strfmt \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:e18ecbb05110:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:68d13333faf2:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jedib0t:go-pretty:v4.3.0:jedib0t_go_pretty/vendor/github.com/jedib0t/go-pretty \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.8:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.8:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		miekg:dns:v1.1.41:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mongodb:mongo-go-driver:v1.0.3:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		mroth:weightedrand:v0.4.1:mroth_weightedrand/vendor/github.com/mroth/weightedrand \
		nxadm:tail:v1.4.8:nxadm_tail/vendor/github.com/nxadm/tail \
		onsi:ginkgo:v1.16.1:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.11.0:onsi_gomega/vendor/github.com/onsi/gomega \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.10.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.18.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		x-cray:logrus-prefixed-formatter:v0.5.2:x_cray_logrus_prefixed_formatter/vendor/github.com/x-cray/logrus-prefixed-formatter


GO_TARGET=	main.go:${PREFIX}/sbin/${PORTNAME}

SUB_FILES=	pkg-message

post-install:
		${INSTALL_DATA} ${FILESDIR}/blocky-config.yml.sample ${STAGEDIR}${PREFIX}/etc/blocky-config.yml.sample

.include <bsd.port.mk>
