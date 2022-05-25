PORTNAME=	acme-dns
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8
CATEGORIES=	dns

MAINTAINER=	mops@punkt.de
COMMENT=	Limited DNS server with RESTful HTTP API to handle ACME DNS challenges

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_TARGET=	:${PREFIX}/libexec/acme-dns

USE_GITHUB=	yes
GH_ACCOUNT=	joohoi
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		DATA-DOG:go-sqlmock:v1.3.3:data_dog_go_sqlmock/vendor/github.com/DATA-DOG/go-sqlmock \
		ajg:form:v1.5.1:ajg_form/vendor/github.com/ajg/form \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		cenkalti:backoff:v3.0.0:cenkalti_backoff_v3/vendor/github.com/cenkalti/backoff/v3 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		erikstmartin:go-testdb:8d10e4a1bae5:erikstmartin_go_testdb/vendor/github.com/erikstmartin/go-testdb \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		gavv:httpexpect:v2.0.0:gavv_httpexpect/vendor/github.com/gavv/httpexpect \
		go-acme:lego:v2.7.2:go_acme_lego/vendor/github.com/go-acme/lego \
		go-acme:lego:v3.1.0:go_acme_lego_v3/vendor/github.com/go-acme/lego/v3 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:87dc89f01550:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:da9a3fd4c582:golang_net/vendor/golang.org/x/net \
		golang:sys:b09406accb47:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		imkira:go-interpol:v1.1.0:imkira_go_interpol/vendor/github.com/imkira/go-interpol \
		julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		klauspost:compress:v1.8.2:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.2.1:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
		mattn:go-sqlite3:v1.11.0:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mholt:certmagic:6f9f0e6dd0e8:mholt_certmagic/vendor/github.com/mholt/certmagic \
		miekg:dns:v1.1.22:miekg_dns/vendor/github.com/miekg/dns \
		moul:http2curl:v1.0.0:moul_http2curl/vendor/github.com/moul/http2curl \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		sergi:go-diff:v1.0.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		square:go-jose:v2.3.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasthttp:v1.5.0:valyala_fasthttp/vendor/github.com/valyala/fasthttp \
		xeipuuv:gojsonpointer:4e3ac2762d5f:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		xeipuuv:gojsonreference:bd5ef7bd5415:xeipuuv_gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
		xeipuuv:gojsonschema:v1.2.0:xeipuuv_gojsonschema/vendor/github.com/xeipuuv/gojsonschema \
		yalp:jsonpath:5cc68e5049a0:yalp_jsonpath/vendor/github.com/yalp/jsonpath \
		yudai:gojsondiff:v1.0.0:yudai_gojsondiff/vendor/github.com/yudai/gojsondiff \
		yudai:golcs:ecda9a501e82:yudai_golcs/vendor/github.com/yudai/golcs

USE_RC_SUBR=	acme-dns

post-patch:
	@${REINPLACE_CMD} -e 's|etc\/acme-dns|usr\/local\/etc\/acme-dns|' ${WRKSRC}/main.go
	@${REINPLACE_CMD} -e 's|etc\/tls|usr\/local\/etc\/tls|' ${WRKSRC}/config.cfg
	@${REINPLACE_CMD} -e 's|var\/lib|var\/db|' ${WRKSRC}/config.cfg

post-install:
	${MKDIR} ${STAGEDIR}/var/db/acme-dns
	${MKDIR} ${STAGEDIR}/var/run/acme-dns
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/acme-dns
	${CP} ${WRKSRC}/config.cfg ${STAGEDIR}${PREFIX}/etc/acme-dns/config.cfg.sample

.include <bsd.port.mk>
