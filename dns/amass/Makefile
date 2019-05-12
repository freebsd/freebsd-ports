# $FreeBSD$

PORTNAME=	amass
DISTVERSION=	2.9.11
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-depth DNS enumeration

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	nodefault # main code is in GH_TUPLE, otherwise build fails with circular dependency errors
GH_ACCOUNT=	OWASP
GH_PROJECT=	Amass
GH_TUPLE=	OWASP:Amass:${DISTVERSIONFULL}:main/src/github.com/OWASP/Amass \
		andybalholm:cascadia:v1.0.0:cascadia/src/github.com/andybalholm/cascadia \
		asaskevich:EventBus:d46933a:EventBus/src/github.com/asaskevich/EventBus \
		boltdb:bolt:fd01fc7:bolt/src/github.com/boltdb/bolt \
		cayleygraph:cayley:v0.7.5:cayley/src/github.com/cayleygraph/cayley \
		caffix:cloudflare-roundtripper:4c29d23:roundtripper/src/github.com/caffix/cloudflare-roundtripper \
		cenkalti:backoff:v2.1.1:backoff/src/github.com/cenkalti/backoff \
		dghubble:go-twitter:7fd79e2:twitter/src/github.com/dghubble/go-twitter \
		dghubble:sling:v1.2.0:sling/src/github.com/dghubble/sling \
		google:go-querystring:v1.0.0:querystring/src/github.com/google/go-querystring \
		fatih:color:v1.7.0:color/src/github.com/fatih/color \
		go-ini:ini:f55231c:ini/src/github.com/go-ini/ini \
		gogo:protobuf:v1.2.1:protobuf/src/github.com/gogo/protobuf \
		google:uuid:v1.1.1:uuid/src/github.com/google/uuid \
		irfansharif:cfilter:d07d951:cfilter/src/github.com/irfansharif/cfilter \
		jmoiron:sqlx:1d3423c:sqlx/src/github.com/jmoiron/sqlx \
		johnnadratowski:golang-neo4j-bolt-driver:v0.1:neo4j/src/github.com/johnnadratowski/golang-neo4j-bolt-driver \
		lib:pq:v1.1.0:pq/src/github.com/lib/pq \
		mattn:go-colorable:v0.0.9:colorable/src/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.4:isatty/src/github.com/mattn/go-isatty \
		miekg:dns:v1.0.8:dns/src/github.com/miekg/dns \
		PuerkitoBio:fetchbot:1f502d6:fetchbot/src/github.com/PuerkitoBio/fetchbot \
		PuerkitoBio:goquery:v1.4.1:goquery/src/github.com/PuerkitoBio/goquery \
		qasaur:gremgo:fa23ada:gremgo/src/github.com/qasaur/gremgo \
		robertkrimen:otto:15f95af:otto/src/github.com/robertkrimen/otto \
		sensepost:maltegolocal:6d52c19:maltegolocal/src/github.com/sensepost/maltegolocal \
		temoto:robotstxt:97ee4a9:robotstxt/src/github.com/temoto/robotstxt-go \
		tylertreat:BoomFilters:611b3db:BoomFilters/src/github.com/tylertreat/BoomFilters \
		golang:crypto:0e37d00:crypto/src/golang.org/x/crypto \
		golang:net:161cd47:net/src/golang.org/x/net \
		golang:oauth2:d2e6202:oauth2/src/golang.org/x/oauth2 \
		golang:sync:1d60e46:sync/src/golang.org/x/sync \
		golang:sys:d0be072:sys/src/golang.org/x/sys \
		golang:text:4ae1256:text/src/golang.org/x/text \
		golang:tools:18207bb:tools/src/golang.org/x/tools \
		go-sourcemap:sourcemap:b019cc3:sourcemap/src/github.com/go-sourcemap/sourcemap

PROGS=		${PORTNAME} ${PORTNAME}.db ${PORTNAME}.netdomains ${PORTNAME}.viz

PLIST_FILES=	${PROGS:C/^/bin\//}

post-patch:
.for f in src/github.com/robertkrimen/otto/file/file.go src/github.com/robertkrimen/otto/parser/parser.go
	@cd ${WRKSRC} && ${REINPLACE_CMD} 's|gopkg.in/sourcemap.v1|github.com/go-sourcemap/sourcemap|' ${f}
.endfor

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go install ./...

do-install:
.for p in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${p} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
