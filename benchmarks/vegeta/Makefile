# $FreeBSD$

PORTNAME=	vegeta
DISTVERSIONPREFIX=	cli/v
DISTVERSION=	12.2.1
CATEGORIES=	benchmarks www

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	HTTP load testing tool and library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	tsenart
GH_TUPLE=	alecthomas:jsonschema:f2c9385:jsonschema/github.com/alecthomas/jsonschema \
		c2h5oh:datasize:4eba002:datasize/github.com/c2h5oh/datasize \
		bmizerany:perks:d9a9656:perks/github.com/bmizerany/perks \
		dgryski:go-gk:201884a:gogk/github.com/dgryski/go-gk \
		dgryski:go-lttb:318fcdf:golttb/github.com/dgryski/go-lttb \
		google:go-cmp:v0.2.0:gocmp/github.com/google/go-cmp \
		influxdata:tdigest:a7d76c6:tdigest/github.com/influxdata/tdigest \
		mailru:easyjson:60711f1:easyjson/github.com/mailru/easyjson \
		shurcooL:httpfs:809bece:httpfs/github.com/shurcooL/httpfs \
		shurcooL:vfsgen:62bca83:vfsgen/github.com/shurcooL/vfsgen \
		streadway:quantile:b0c5887:quantile/github.com/streadway/quantile \
		tsenart:go-tsz:cdeb9e1:gotsz/github.com/tsenart/go-tsz \
		golang:net:c394268:net/golang.org/x/net \
		golang:text:v0.3.0:text/golang.org/x/text

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@${MKDIR} ${WRKSRC}/github.com/${GH_ACCOUNT}
	@${RLN} ${WRKSRC} ${WRKSRC}/github.com/${GH_ACCOUNT}/${PORTNAME}
	@${RLN} ${WRKSRC} ${WRKSRC}/src
	@cd ${WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GO_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} \
	  ${GO_CMD} build -v -a -tags=netgo -ldflags \
	  '-s -w -extldflags "-static" -X main.Version=${DISTVERSION}' -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}/${LOCALBASE}/bin

.include <bsd.port.mk>
