PORTNAME=	ali
PORTVERSION=	0.7.5
DISTVERSIONPREFIX=	v
PORTREVISION=	28
CATEGORIES=	benchmarks

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Load testing tool aimed to perform real-time analysis
WWW=		https://github.com/nakabonne/ali

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	nakabonne
GH_TUPLE=	davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.2.0:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:net:a5a99cb37ef4:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:2321bbc49cbf:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		influxdata:tdigest:a7d76c6f093a:influxdata_tdigest/vendor/github.com/influxdata/tdigest \
		lucasb-eyer:go-colorful:v1.0.3:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mailru:easyjson:v0.7.0:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-runewidth:v0.0.12:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miekg:dns:v1.1.43:miekg_dns/vendor/github.com/miekg/dns \
		mum4k:termdash:v0.16.0:mum4k_termdash/vendor/github.com/mum4k/termdash \
		nakabonne:tstorage:v0.3.5:nakabonne_tstorage/vendor/github.com/nakabonne/tstorage \
		nsf:termbox-go:9b52a5faed9e:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.1.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tsenart:vegeta:v12.8.4:tsenart_vegeta_v12/vendor/github.com/tsenart/vegeta/v12 \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:goleak:v1.1.12:uber_go_goleak/vendor/go.uber.org/goleak

CONFLICTS_INSTALL=	ja-mh mmh nmh

PLIST_FILES=	bin/ali

.include <bsd.port.mk>
