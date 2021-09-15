PORTNAME=	ali
PORTVERSION=	0.7.3
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Load testing tool aimed to perform real-time analysis

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	nakabonne
GH_TUPLE=	davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v1.3.0:gdamore_tcell/vendor/github.com/gdamore/tcell \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:lint:16217165b5de:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.4.4:golang_mock/vendor/github.com/golang/mock \
		golang:net:e18ecbb05110:golang_net/vendor/golang.org/x/net \
		golang:sys:134d130e1a04:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:tools:7d206e10da11:golang_tools/vendor/golang.org/x/tools \
		influxdata:tdigest:a7d76c6f093a:influxdata_tdigest/vendor/github.com/influxdata/tdigest \
		lucasb-eyer:go-colorful:v1.0.2:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mailru:easyjson:v0.7.0:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miekg:dns:v1.1.43:miekg_dns/vendor/github.com/miekg/dns \
		mum4k:termdash:v0.12.2:mum4k_termdash/vendor/github.com/mum4k/termdash \
		nakabonne:tstorage:v0.2.2:nakabonne_tstorage/vendor/github.com/nakabonne/tstorage \
		nsf:termbox-go:4d2b513ad8be:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tsenart:vegeta:v12.8.3:tsenart_vegeta_v12/vendor/github.com/tsenart/vegeta/v12 \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:goleak:v1.1.10:uber_go_goleak/vendor/go.uber.org/goleak

PLIST_FILES=	bin/ali

.include <bsd.port.mk>
