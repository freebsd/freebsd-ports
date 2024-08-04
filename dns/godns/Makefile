PORTNAME=	godns
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.7
CATEGORIES=	dns

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Dynamic DNS client (DDNS) with optional external reporting features
WWW=		https://github.com/TimothyYe/godns

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	TimothyYe

GO_TARGET=	./cmd/${PORTNAME}

GH_TUPLE=	\
		alexcesaro:quotedprintable:2caba252f4dc:alexcesaro_quotedprintable/vendor/gopkg.in/alexcesaro/quotedprintable.v3 \
		andybalholm:brotli:v1.0.5:andybalholm_brotli/vendor/github.com/andybalholm/brotli \
		bitly:go-simplejson:v0.5.0:bitly_go_simplejson/vendor/github.com/bitly/go-simplejson \
		bmizerany:assert:b7ed37b82869:bmizerany_assert/vendor/github.com/bmizerany/assert \
		bwmarrin:discordgo:v0.27.1:bwmarrin_discordgo/vendor/github.com/bwmarrin/discordgo \
		fatih:color:v1.15.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.7.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-gomail:gomail:81ebce5c23df:go_gomail_gomail/vendor/gopkg.in/gomail.v2 \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-resty:resty:v2.7.0:go_resty_resty_v2/vendor/github.com/go-resty/resty/v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		gofiber:fiber:v2.52.1:gofiber_fiber_v2/vendor/github.com/gofiber/fiber/v2 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:v0.21.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.10.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.23.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.7.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.18.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.8.0:golang_tools/vendor/golang.org/x/tools \
		google:uuid:v1.5.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		klauspost:compress:v1.17.0:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		linode:linodego:v1.16.1:linode_linodego/vendor/github.com/linode/linodego \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.15:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miekg:dns:v1.1.53:miekg_dns/vendor/github.com/miekg/dns \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		ovh:go-ovh:v1.4.1:ovh_go_ovh/vendor/github.com/ovh/go-ovh \
		protocolbuffers:protobuf-go:v1.33.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sirupsen:logrus:v1.9.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasthttp:v1.51.0:valyala_fasthttp/vendor/github.com/valyala/fasthttp \
		valyala:tcplisten:v1.0.0:valyala_tcplisten/vendor/github.com/valyala/tcplisten

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${PATCH_WRKSRC}/cmd/godns/godns.go
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
		${PATCH_WRKSRC}/cmd/godns/godns.go
	${MKDIR} ${PATCH_WRKSRC}/internal/server/out
	${TOUCH} ${PATCH_WRKSRC}/internal/server/out/index.html

post-install:
	${INSTALL_DATA} ${FILESDIR}/godns-config.json.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
