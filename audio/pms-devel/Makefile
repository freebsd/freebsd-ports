# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pms-devel
PORTVERSION=	0.0.20181123
CATEGORIES=	audio

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Rewrite of pms, an ncurses-based client for the Music Player Daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	ambientsound
GH_PROJECT=	pms
GH_TAGNAME=	000c5c0

GH_TUPLE=\
	ambientsound:gompd:b065d40:gompd/src/github.com/ambientsound/gompd \
	blevesearch:bleve:1a319cd:bleve/src/github.com/blevesearch/bleve \
	blevesearch:go-porterstemmer:23a2c8e:porterstemmer/src/github.com/blevesearch/go-porterstemmer \
	blevesearch:segment:762005e:segment/src/github.com/blevesearch/segment \
	boltdb:bolt:2f1ce7a:boltdb/src/github.com/boltdb/bolt \
	couchbase:vellum:35d9e73:vellum/src/github.com/couchbase/vellum \
	edsrzf:mmap-go:0bce6a6:mmap/src/github.com/edsrzf/mmap-go \
	gdamore:encoding:b23993c:encoding/src/github.com/gdamore/encoding \
	gdamore:tcell:de7e78e:tcell/src/github.com/gdamore/tcell \
	glycerine:go-unsnap-stream:9f0cb55:unsnapstream/src/github.com/glycerine/go-unsnap-stream \
	golang:protobuf:aa810b6:protobuf/src/github.com/golang/protobuf \
	golang:snappy:2e65f85:snappy/src/github.com/golang/snappy \
	jessevdk:go-flags:c6ca198:flags/src/github.com/jessevdk/go-flags \
	lucasb-eyer:go-colorful:c784231:colorful/src/github.com/lucasb-eyer/go-colorful \
	mattn:go-runewidth:ce7b0b5:runewidth/src/github.com/mattn/go-runewidth \
	philhofer:fwd:bb6d471:fwd/src/github.com/philhofer/fwd \
	RoaringBitmap:roaring:3d677d3:roaring/src/github.com/RoaringBitmap/roaring \
	Smerity:govarint:7265e41:govarint/src/github.com/Smerity/govarint \
	steveyen:gtreap:0abe01e:gtreap/src/github.com/steveyen/gtreap \
	stretchr:testify:f35b8ab:testify/src/github.com/stretchr/testify \
	tinylib:msgp:b2b6a67:msgp/src/github.com/tinylib/msgp \
	golang:net:161cd47:net/src/golang.org/x/net \
	golang:text:f21a4df:text/src/golang.org/x/text

PLIST_FILES=	bin/${GO_PKGNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	${LN} -sf ${WRKSRC} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
	${RM} ${WRKSRC}/go.mod

do-build:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -ldflags "-X main.buildVersion=${DISTVERSION}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pms-${GH_TAGNAME} ${STAGEDIR}${PREFIX}/bin/${GO_PKGNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${GO_PKGNAME}

.include <bsd.port.mk>
