# $FreeBSD$

PORTNAME=	amass
DISTVERSION=	3.0.18
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-depth DNS enumeration

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	OWASP
GH_PROJECT=	Amass
GH_TUPLE=	PuerkitoBio:fetchbot:v1.1.2:puerkitobio_fetchbot/vendor/github.com/PuerkitoBio/fetchbot \
		PuerkitoBio:goquery:v1.5.0:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		VividCortex:gohistogram:v1.0.0:vividcortex_gohistogram/vendor/github.com/VividCortex/gohistogram \
		andybalholm:cascadia:v1.0.0:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		caffix:cloudflare-roundtripper:4c29d231c9cb:caffix_cloudflare_roundtripper/vendor/github.com/caffix/cloudflare-roundtripper \
		cayleygraph:cayley:v0.7.5:cayleygraph_cayley/vendor/github.com/cayleygraph/cayley \
		cenkalti:backoff:v2.1.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		chromedp:cdproto:dd39f0bf0a54:chromedp_cdproto/vendor/github.com/chromedp/cdproto \
		chromedp:chromedp:d55cf9043e05:chromedp_chromedp/vendor/github.com/chromedp/chromedp \
		dghubble:go-twitter:53f972dc4b06:dghubble_go_twitter/vendor/github.com/dghubble/go-twitter \
		dghubble:sling:v1.2.0:dghubble_sling/vendor/github.com/dghubble/sling \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fpfeng:httpcache:6b8f16a92be3:fpfeng_httpcache/vendor/github.com/fpfeng/httpcache \
		geziyor:geziyor:71683ec6de71:geziyor_geziyor/vendor/github.com/geziyor/geziyor \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/github.com/go-ini/ini \
		go-kit:kit:v0.8.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-sourcemap:sourcemap:v1.0.5:go_sourcemap_sourcemap/vendor/gopkg.in/sourcemap.v1 \
		gobwas:httphead:2c6c146eadee:gobwas_httphead/vendor/github.com/gobwas/httphead \
		gobwas:pool:v0.2.0:gobwas_pool/vendor/github.com/gobwas/pool \
		gobwas:ws:v1.0.1:gobwas_ws/vendor/github.com/gobwas/ws \
		gogo:protobuf:v1.1.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.4.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c2843e01d9a2:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:f3200d17e092:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:1e42afee0f76:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		irfansharif:cfilter:v0.1.1:irfansharif_cfilter/vendor/github.com/irfansharif/cfilter \
		jmoiron:sqlx:v1.2.0:jmoiron_sqlx/vendor/github.com/jmoiron/sqlx \
		johnnadratowski:golang-neo4j-bolt-driver:6b24c0085aae:johnnadratowski_golang_neo4j_bolt_driver/vendor/github.com/johnnadratowski/golang-neo4j-bolt-driver \
		knq:sysutil:f05b59f0f307:knq_sysutil/vendor/github.com/knq/sysutil \
		lib:pq:v1.1.1:lib_pq/vendor/github.com/lib/pq \
		mailru:easyjson:1ea4449da983:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-colorable:v0.1.2:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.8:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.15:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.0.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.4.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.2:prometheus_procfs/vendor/github.com/prometheus/procfs \
		qasaur:gremgo:fa23ada7c5da:qasaur_gremgo/vendor/github.com/qasaur/gremgo \
		robertkrimen:otto:15f95af6e78d:robertkrimen_otto/vendor/github.com/robertkrimen/otto \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		tylertreat:BoomFilters:611b3dbe80e8:tylertreat_boomfilters/vendor/github.com/tylertreat/BoomFilters

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

.include <bsd.port.mk>
