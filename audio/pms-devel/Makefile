# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pms-devel
PORTVERSION=	0.0.20171103
CATEGORIES=	audio

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Rewrite of pms, an ncurses-based client for the Music Player Daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	ambientsound
GH_PROJECT=	pms
GH_TAGNAME=	8c9440a

GH_TUPLE=\
	ambientsound:gompd:b065d40:gompd/src/github.com/ambientsound/gompd \
	blevesearch:bleve:6eea5b7:bleve/src/github.com/blevesearch/bleve \
	blevesearch:go-porterstemmer:23a2c8e:porterstemmer/src/github.com/blevesearch/go-porterstemmer \
	blevesearch:segment:762005e:segment/src/github.com/blevesearch/segment \
	boltdb:bolt:fa5367d:boltdb/src/github.com/boltdb/bolt \
	gdamore:encoding:b23993c:encoding/src/github.com/gdamore/encoding \
	gdamore:tcell:87c64c4:tcell/src/github.com/gdamore/tcell \
	golang:protobuf:1e59b77:protobuf/src/github.com/golang/protobuf \
	jessevdk:go-flags:f88afde:flags/src/github.com/jessevdk/go-flags \
	lucasb-eyer:go-colorful:2312723:colorful/src/github.com/lucasb-eyer/go-colorful \
	mattn:go-runewidth:97311d9:runewidth/src/github.com/mattn/go-runewidth \
	steveyen:gtreap:0abe01e:gtreap/src/github.com/steveyen/gtreap \
	stretchr:testify:2aa2c17:testify/src/github.com/stretchr/testify \
	golang:net:9dfe398:net/src/golang.org/x/net \
	golang:text:88f656f:text/src/golang.org/x/text

PLIST_FILES=	bin/${GO_PKGNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	${LN} -sf ${WRKSRC} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}

do-build:
	@cd ${WRKSRC}; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -ldflags "-X main.buildVersion=${DISTVERSION}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pms-${GH_TAGNAME} ${STAGEDIR}${PREFIX}/bin/${GO_PKGNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${COPYTREE_SHARE} ${WRKSRC}/doc ${STAGEDIR}${DOCSDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${GO_PKGNAME}

.include <bsd.port.mk>
