# $FreeBSD$

PORTNAME=	vegeta
DISTVERSIONPREFIX=	cli/v
DISTVERSION=	11.0.0
CATEGORIES=	benchmarks www

MAINTAINER=	egypcio@googlemail.com
COMMENT=	HTTP load testing tool and library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PLIST_FILES=	bin/${PORTNAME}

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	tsenart
GH_TUPLE=	alecthomas:jsonschema:f2c9385:jsonschema/github.com/alecthomas/jsonschema \
		bmizerany:perks:d9a9656:perks/github.com/bmizerany/perks \
		dgryski:go-gk:201884a:gogk/github.com/dgryski/go-gk \
		dgryski:go-lttb:318fcdf:golttb/github.com/dgryski/go-lttb \
		google:go-cmp:3af367b:gocmp/github.com/google/go-cmp \
		influxdata:tdigest:a7d76c6:tdigest/github.com/influxdata/tdigest \
		shurcooL:httpfs:809bece:httpfs/github.com/shurcooL/httpfs \
		shurcooL:vfsgen:62bca83:vfsgen/github.com/shurcooL/vfsgen \
		streadway:quantile:b0c5887:quantile/github.com/streadway/quantile \
		tsenart:go-tsz:cdeb9e1:gotsz/github.com/tsenart/go-tsz \
		golang:net:c394268:net/golang.org/x/net \
		golang:text:f21a4df:text/golang.org/x/text

do-build:
	@${MKDIR} ${WRKSRC}/github.com/${GH_ACCOUNT}
	@${RLN} ${WRKSRC} ${WRKSRC}/github.com/${GH_ACCOUNT}/${PORTNAME}
	@${RLN} ${WRKSRC} ${WRKSRC}/src
	@cd ${WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GO_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} \
	  ${GO_CMD} build -v -a -tags=netgo -ldflags \
	  '-s -w -extldflags "-static" -X main.Version=${DISTVERSION} -X main.Date=20180818' \
	  -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}/${LOCALBASE}/bin

.include <bsd.port.mk>
