# $FreeBSD$

PORTNAME=	amass
DISTVERSION=	2.8.6
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
		fatih:color:v1.7.0:color/src/github.com/fatih/color \
		go-ini:ini:f55231c:ini/src/github.com/go-ini/ini \
		irfansharif:cfilter:d07d951:cfilter/src/github.com/irfansharif/cfilter \
		johnnadratowski:golang-neo4j-bolt-driver:v0.1:neo4j/src/github.com/johnnadratowski/golang-neo4j-bolt-driver \
		mattn:go-colorable:v0.0.9:colorable/src/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.4:isatty/src/github.com/mattn/go-isatty \
		miekg:dns:v1.0.8:dns/src/github.com/miekg/dns \
		PuerkitoBio:fetchbot:1f502d6:fetchbot/src/github.com/PuerkitoBio/fetchbot \
		PuerkitoBio:goquery:v1.4.1:goquery/src/github.com/PuerkitoBio/goquery \
		sensepost:maltegolocal:6d52c19:maltegolocal/src/github.com/sensepost/maltegolocal \
		temoto:robotstxt:97ee4a9:robotstxt/src/github.com/temoto/robotstxt-go \
		golang:crypto:0e37d00:crypto/src/golang.org/x/crypto \
		golang:net:161cd47:net/src/golang.org/x/net \
		golang:sync:1d60e46:sync/src/golang.org/x/sync \
		golang:sys:d0be072:sys/src/golang.org/x/sys \
		golang:text:4ae1256:text/src/golang.org/x/text \
		golang:tools:18207bb:tools/src/golang.org/x/tools

PROGS=		${PORTNAME} ${PORTNAME}.db ${PORTNAME}.netdomains ${PORTNAME}.viz

PLIST_FILES=	${PROGS:C/^/bin\//}

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go install ./...

do-install:
.for p in ${PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${p} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
