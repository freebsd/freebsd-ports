# $FreeBSD$

PORTNAME=	amass
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.10
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-depth DNS enumeration

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	OWASP
GH_PROJECT=	Amass
GH_TUPLE=	\
		PuerkitoBio:goquery:v1.5.0:puerkitobio_goquery/vendor/github.com/PuerkitoBio/goquery \
		TheTannerRyan:ring:v1.1.0:thetannerryan_ring/vendor/github.com/TheTannerRyan/ring \
		VividCortex:gohistogram:v1.0.0:vividcortex_gohistogram/vendor/github.com/VividCortex/gohistogram \
		andybalholm:cascadia:v1.0.0:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		caffix:cloudflare-roundtripper:4c29d231c9cb:caffix_cloudflare_roundtripper/vendor/github.com/caffix/cloudflare-roundtripper \
		cayleygraph:cayley:v0.7.5:cayleygraph_cayley/vendor/github.com/cayleygraph/cayley \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		chromedp:cdproto:1b4886c6fad6:chromedp_cdproto/vendor/github.com/chromedp/cdproto \
		chromedp:chromedp:42693d2528b1:chromedp_chromedp/vendor/github.com/chromedp/chromedp \
		dghubble:go-twitter:39e5462e111f:dghubble_go_twitter/vendor/github.com/dghubble/go-twitter \
		dghubble:sling:v1.3.0:dghubble_sling/vendor/github.com/dghubble/sling \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		geziyor:geziyor:9b8a3837bd4a:geziyor_geziyor/vendor/github.com/geziyor/geziyor \
		go-ini:ini:v1.48.0:go_ini_ini/vendor/github.com/go-ini/ini \
		go-kit:kit:v0.9.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-sourcemap:sourcemap:v1.0.5:go_sourcemap_sourcemap/vendor/gopkg.in/sourcemap.v1 \
		gobuffalo:envy:v1.7.1:gobuffalo_envy/vendor/github.com/gobuffalo/envy \
		gobuffalo:packd:v0.3.0:gobuffalo_packd/vendor/github.com/gobuffalo/packd \
		gobuffalo:packr:v1.30.1:gobuffalo_packr/vendor/github.com/gobuffalo/packr \
		gobwas:httphead:2c6c146eadee:gobwas_httphead/vendor/github.com/gobwas/httphead \
		gobwas:pool:v0.2.0:gobwas_pool/vendor/github.com/gobwas/pool \
		gobwas:ws:v1.0.2:gobwas_ws/vendor/github.com/gobwas/ws \
		gogo:protobuf:v1.3.0:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.4:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:a832865fa7ad:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:c00fd9afed17:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:c990c680b611:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		jmoiron:sqlx:v1.2.0:jmoiron_sqlx/vendor/github.com/jmoiron/sqlx \
		joho:godotenv:v1.3.0:joho_godotenv/vendor/github.com/joho/godotenv \
		knq:sysutil:f05b59f0f307:knq_sysutil/vendor/github.com/knq/sysutil \
		lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
		mailru:easyjson:v0.7.0:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-colorable:v0.1.2:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.9:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.19:miekg_dns/vendor/github.com/miekg/dns \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.1.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:14fe0d1b01d4:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.7.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.5:prometheus_procfs/vendor/github.com/prometheus/procfs \
		qasaur:gremgo:fa23ada7c5da:qasaur_gremgo/vendor/github.com/qasaur/gremgo \
		robertkrimen:otto:15f95af6e78d:robertkrimen_otto/vendor/github.com/robertkrimen/otto \
		rogpeppe:go-internal:v1.4.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		temoto:robotstxt:v1.1.1:temoto_robotstxt/vendor/github.com/temoto/robotstxt \
		tylertreat:BoomFilters:611b3dbe80e8:tylertreat_boomfilters/vendor/github.com/tylertreat/BoomFilters

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

.include <bsd.port.mk>
