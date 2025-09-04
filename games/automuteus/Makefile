PORTNAME=	automuteus
DISTVERSION=	8.3.7
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	seafork@disroot.org
COMMENT=	Discord Bot to automute Among Us players at round transitions
WWW=		https://automute.us/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes

GH_TUPLE=	\
		BurntSushi:toml:v1.1.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		KyleBanks:depth:v1.2.1:kylebanks_depth/vendor/github.com/KyleBanks/depth \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bsm:redislock:v0.7.1:bsm_redislock/vendor/github.com/bsm/redislock \
		bwmarrin:discordgo:v0.27.1:bwmarrin_discordgo/vendor/github.com/bwmarrin/discordgo \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		georgysavva:scany:v0.2.7:georgysavva_scany/vendor/github.com/georgysavva/scany \
		gin-contrib:sse:v0.1.0:gin_contrib_sse/vendor/github.com/gin-contrib/sse \
		gin-gonic:gin:v1.8.2:gin_gonic_gin/vendor/github.com/gin-gonic/gin \
		go-openapi:jsonpointer:v0.19.5:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.6:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:spec:v0.20.4:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:swag:v0.19.15:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-playground:locales:v0.14.0:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.18.0:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v10.11.1:go_playground_validator_v10/vendor/github.com/go-playground/validator/v10 \
		redis:go-redis:v8.8.0:go_redis_redis_v8/vendor/github.com/go-redis/redis/v8 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		goccy:go-json:v0.9.11:goccy_go_json/vendor/github.com/goccy/go-json \
		golang:crypto:630584e8d5aa:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:a684f29349b6:golang_exp/vendor/golang.org/x/exp \
		golang:net:v0.4.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.3.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.5.0:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.2.0:golang_tools/vendor/golang.org/x/tools \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		jackc:chunkreader:v2.0.1:jackc_chunkreader_v2/vendor/github.com/jackc/chunkreader/v2 \
		jackc:pgconn:v1.13.0:jackc_pgconn/vendor/github.com/jackc/pgconn \
		jackc:pgio:v1.0.0:jackc_pgio/vendor/github.com/jackc/pgio \
		jackc:pgpassfile:v1.0.0:jackc_pgpassfile/vendor/github.com/jackc/pgpassfile \
		jackc:pgproto3:v2.3.1:jackc_pgproto3_v2/vendor/github.com/jackc/pgproto3/v2 \
		jackc:pgservicefile:2b9c44734f2b:jackc_pgservicefile/vendor/github.com/jackc/pgservicefile \
		jackc:pgtype:v1.12.0:jackc_pgtype/vendor/github.com/jackc/pgtype \
		jackc:pgx:v4.17.0:jackc_pgx_v4/vendor/github.com/jackc/pgx/v4 \
		jackc:puddle:v1.2.1:jackc_puddle/vendor/github.com/jackc/puddle \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		leodido:go-urn:v1.2.1:leodido_go_urn/vendor/github.com/leodido/go-urn \
		mailru:easyjson:v0.7.6:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-isatty:v0.0.16:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		nicksnyder:go-i18n:v2.2.1:nicksnyder_go_i18n_v2/vendor/github.com/nicksnyder/go-i18n \
		open-telemetry:opentelemetry-go:v0.19.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		pashagolub:pgxmock:v1.8.0:pashagolub_pgxmock/vendor/github.com/pashagolub/pgxmock \
		pelletier:go-toml:v2.0.6:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.10.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.18.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.28.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		stretchr:objx:v0.5.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.8.1:stretchr_testify/vendor/github.com/stretchr/testify \
		swaggo:files:551d4a08d97a:swaggo_files/vendor/github.com/swaggo/files \
		swaggo:gin-swagger:v1.5.3:swaggo_gin_swagger/vendor/github.com/swaggo/gin-swagger \
		swaggo:swag:v1.8.10:swaggo_swag/vendor/github.com/swaggo/swag \
		Top-gg-Community:go-sdk:e844586b1159:top_gg_go_dbl/vendor/github.com/top-gg/go-dbl \
		ugorji:go:v1.2.7:ugorji_go_codec/vendor/github.com/ugorji/go

USE_RC_SUBR=	${PORTNAME}

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	.:${PORTNAME}

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME} \
		"@sample etc/${PORTNAME}/${PORTNAME}.conf.sample" \
		"@dir /var/log/${PORTNAME}" \
		/var/log/${PORTNAME}/logs.txt

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}/var/log/${PORTNAME}
	@${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample
	@${TOUCH} ${STAGEDIR}/var/log/${PORTNAME}/logs.txt

.include <bsd.port.mk>
