# $FreeBSD$

PORTNAME=	vegeta
DISTVERSIONPREFIX=	v
DISTVERSION=	12.7.0
CATEGORIES=	benchmarks www

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	HTTP load testing tool and library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	tsenart
GH_TUPLE=	alecthomas:jsonschema:f2c9385:jsonschema/vendor/github.com/alecthomas/jsonschema \
		c2h5oh:datasize:4eba002:datasize/vendor/github.com/c2h5oh/datasize \
		bmizerany:perks:d9a9656:perks/vendor/github.com/bmizerany/perks \
		dgryski:go-gk:201884a:gogk/vendor/github.com/dgryski/go-gk \
		dgryski:go-lttb:318fcdf:golttb/vendor/github.com/dgryski/go-lttb \
		google:go-cmp:v0.2.0:gocmp/vendor/github.com/google/go-cmp \
		influxdata:tdigest:a7d76c6:tdigest/vendor/github.com/influxdata/tdigest \
		mailru:easyjson:60711f1:easyjson/vendor/github.com/mailru/easyjson \
		shurcooL:httpfs:809bece:httpfs/vendor/github.com/shurcooL/httpfs \
		shurcooL:vfsgen:62bca83:vfsgen/vendor/github.com/shurcooL/vfsgen \
		streadway:quantile:b0c5887:quantile/vendor/github.com/streadway/quantile \
		tsenart:go-tsz:cdeb9e1:gotsz/vendor/github.com/tsenart/go-tsz \
		golang:net:c394268:net/vendor/golang.org/x/net \
		golang:text:v0.3.0:text/vendor/golang.org/x/text

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-tags=netgo \
		-ldflags '-s -w -extldflags "-static" -X main.Version=${DISTVERSION}'

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
