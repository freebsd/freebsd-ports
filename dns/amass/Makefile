# $FreeBSD$

PORTNAME=	amass
DISTVERSION=	3.0.16
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
		andybalholm:cascadia:v1.0.0:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		caffix:cloudflare-roundtripper:4c29d231c9cb:caffix_cloudflare_roundtripper/vendor/github.com/caffix/cloudflare-roundtripper \
		cayleygraph:cayley:v0.7.5:cayleygraph_cayley/vendor/github.com/cayleygraph/cayley \
		cenkalti:backoff:v2.1.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		dghubble:go-twitter:53f972dc4b06:dghubble_go_twitter/vendor/github.com/dghubble/go-twitter \
		dghubble:sling:v1.2.0:dghubble_sling/vendor/github.com/dghubble/sling \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/github.com/go-ini/ini \
		go-sourcemap:sourcemap:v1.0.5:go_sourcemap_sourcemap/vendor/gopkg.in/sourcemap.v1 \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.4.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:57b3e21c3d56:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:eb5bcb51f2a3:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.2.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:516e3c20635f:golang_sys/vendor/golang.org/x/sys \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		irfansharif:cfilter:v0.1.1:irfansharif_cfilter/vendor/github.com/irfansharif/cfilter \
		jmoiron:sqlx:v1.2.0:jmoiron_sqlx/vendor/github.com/jmoiron/sqlx \
		johnnadratowski:golang-neo4j-bolt-driver:6b24c0085aae:johnnadratowski_golang_neo4j_bolt_driver/vendor/github.com/johnnadratowski/golang-neo4j-bolt-driver \
		lib:pq:v1.1.1:lib_pq/vendor/github.com/lib/pq \
		mattn:go-colorable:v0.1.2:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.8:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		miekg:dns:v1.1.14:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		qasaur:gremgo:fa23ada7c5da:qasaur_gremgo/vendor/github.com/qasaur/gremgo \
		robertkrimen:otto:15f95af6e78d:robertkrimen_otto/vendor/github.com/robertkrimen/otto \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		temoto:robotstxt:97ee4a9ee6ea:temoto_robotstxt_go/vendor/github.com/temoto/robotstxt-go \
		tylertreat:BoomFilters:611b3dbe80e8:tylertreat_boomfilters/vendor/github.com/tylertreat/BoomFilters

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

.include <bsd.port.mk>
