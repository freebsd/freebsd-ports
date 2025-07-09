PORTNAME=		acme-dns
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0
PORTREVISION=	24
PORTEPOCH=		1
CATEGORIES=		dns

MAINTAINER=		mops@punkt.de
COMMENT=		Limited DNS server with RESTful HTTP API to handle ACME DNS challenges
WWW=		https://github.com/joohoi/acme-dns

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

USES=			go:modules

USE_GITHUB=		yes
GH_ACCOUNT=		joohoi

GH_TUPLE=		\
			BurntSushi:toml:v0.4.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
			DATA-DOG:go-sqlmock:v1.5.0:data_dog_go_sqlmock/vendor/github.com/DATA-DOG/go-sqlmock \
			ajg:form:v1.5.1:ajg_form/vendor/github.com/ajg/form \
			andybalholm:brotli:v1.0.2:andybalholm_brotli/vendor/github.com/andybalholm/brotli \
			caddyserver:certmagic:v0.15.2:caddyserver_certmagic/vendor/github.com/caddyserver/certmagic \
			davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
			erikstmartin:go-testdb:8d10e4a1bae5:erikstmartin_go_testdb/vendor/github.com/erikstmartin/go-testdb \
			fasthttp-contrib:websocket:1f3b11f56072:fasthttp_contrib_websocket/vendor/github.com/fasthttp-contrib/websocket \
			fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
			gavv:httpexpect:v2.0.0:gavv_httpexpect/vendor/github.com/gavv/httpexpect \
			go-acme:lego:v3.9.0:go_acme_lego_v3/vendor/github.com/go-acme/lego/v3 \
			go-yaml:yaml:496545a6307b:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
			golang:crypto:e495a2d5b3d3:golang_crypto/vendor/golang.org/x/crypto \
			golang:mod:v0.5.1:golang_mod/vendor/golang.org/x/mod \
			golang:net:v0.8.0:golang_net/vendor/golang.org/x/net \
			golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
			golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
			golang:tools:v0.6.0:golang_tools/vendor/golang.org/x/tools \
			golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
			google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
			google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
			gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
			imkira:go-interpol:v1.1.0:imkira_go_interpol/vendor/github.com/imkira/go-interpol \
			julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
			klauspost:compress:v1.13.4:klauspost_compress/vendor/github.com/klauspost/compress \
			klauspost:cpuid:v2.0.9:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
			lib:pq:v1.10.4:lib_pq/vendor/github.com/lib/pq \
			libdns:libdns:v0.2.1:libdns_libdns/vendor/github.com/libdns/libdns \
			mattn:go-colorable:v0.1.12:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
			mattn:go-sqlite3:v1.14.10:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
			mholt:acmez:v1.0.1:mholt_acmez/vendor/github.com/mholt/acmez \
			miekg:dns:v1.1.45:miekg_dns/vendor/github.com/miekg/dns \
			moul:http2curl:v1.0.0:moul_http2curl/vendor/github.com/moul/http2curl \
			pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
			rs:cors:v1.8.2:rs_cors/vendor/github.com/rs/cors \
			sergi:go-diff:v1.2.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
			sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
			stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
			uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
			uber-go:multierr:v1.7.0:uber_go_multierr/vendor/go.uber.org/multierr \
			uber-go:zap:v1.20.0:uber_go_zap/vendor/go.uber.org/zap \
			valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
			valyala:fasthttp:v1.31.0:valyala_fasthttp/vendor/github.com/valyala/fasthttp \
			xeipuuv:gojsonpointer:4e3ac2762d5f:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
			xeipuuv:gojsonreference:bd5ef7bd5415:xeipuuv_gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
			xeipuuv:gojsonschema:v1.2.0:xeipuuv_gojsonschema/vendor/github.com/xeipuuv/gojsonschema \
			yalp:jsonpath:5cc68e5049a0:yalp_jsonpath/vendor/github.com/yalp/jsonpath \
			yudai:gojsondiff:v1.0.0:yudai_gojsondiff/vendor/github.com/yudai/gojsondiff \
			yudai:golcs:ecda9a501e82:yudai_golcs/vendor/github.com/yudai/golcs \
			yudai:pp:v2.0.1:yudai_pp/vendor/github.com/yudai/pp

USE_RC_SUBR=		acme_dns

post-patch:
	@${REINPLACE_CMD} -e 's|etc\/acme-dns|usr\/local\/etc\/acme-dns|' ${WRKSRC}/main.go
	@${REINPLACE_CMD} -e 's|etc\/tls|usr\/local\/etc\/tls|' ${WRKSRC}/config.cfg
	@${REINPLACE_CMD} -e 's|var\/lib|var\/db|' ${WRKSRC}/config.cfg

post-install:
	${MKDIR} ${STAGEDIR}/var/db/acme-dns
	${MKDIR} ${STAGEDIR}/var/run/acme-dns
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/acme-dns
	${CP} ${WRKSRC}/config.cfg ${STAGEDIR}${PREFIX}/etc/acme-dns/config.cfg.sample
	${MV} ${STAGEDIR}${PREFIX}/bin/acme-dns ${STAGEDIR}${PREFIX}/libexec/acme-dns

.include <bsd.port.mk>
