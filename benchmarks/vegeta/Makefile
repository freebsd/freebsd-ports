PORTNAME=	vegeta
DISTVERSIONPREFIX=	v
DISTVERSION=	12.8.4
PORTREVISION=	4
CATEGORIES=	benchmarks www

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	HTTP load testing tool and library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	tsenart
GH_TUPLE=	alecthomas:jsonschema:71f4389:alecthomas_jsonschema/vendor/github.com/alecthomas/jsonschema \
		bmizerany:perks:d9a9656a3a4b:bmizerany_perks/vendor/github.com/bmizerany/perks \
		c2h5oh:datasize:4eba002a5eae:c2h5oh_datasize/vendor/github.com/c2h5oh/datasize \
		dgryski:go-gk:201884a44051:dgryski_go_gk/vendor/github.com/dgryski/go-gk \
		dgryski:go-lttb:318fcdf10a77:dgryski_go_lttb/vendor/github.com/dgryski/go-lttb \
		flyingmutant:rapid:v0.3.3:flyingmutant_rapid/vendor/pgregory.net/rapid \
		golang:crypto:9e8e0b3:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:7b1cca2:golang_net/vendor/golang.org/x/net \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:sys:b09fb70:golang_sys/vendor/golang.org/x/sys \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		influxdata:tdigest:a7d76c6f093a:influxdata_tdigest/vendor/github.com/influxdata/tdigest \
		mailru:easyjson:v0.7.0:mailru_easyjson/vendor/github.com/mailru/easyjson \
		miekg:dns:v1.1.33:miekg_dns/vendor/github.com/miekg/dns \
		streadway:quantile:b0c588724d25:streadway_quantile/vendor/github.com/streadway/quantile \
		tsenart:go-tsz:cdeb9e1e981e:tsenart_go_tsz/vendor/github.com/tsenart/go-tsz

GO_BUILDFLAGS=	-tags=netgo \
		-ldflags '-s -w -extldflags "-static" -X main.Version=${DISTVERSION}'

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
