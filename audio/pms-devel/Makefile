# Created by: Thomas Zander <riggs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pms-devel
PORTVERSION=	0.0.20181123
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Rewrite of pms, an ncurses-based client for the Music Player Daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	ambientsound
GH_PROJECT=	pms
GH_TAGNAME=	000c5c0

GH_TUPLE=	\
		RoaringBitmap:roaring:v0.4.16:roaringbitmap_roaring/vendor/github.com/RoaringBitmap/roaring \
		Smerity:govarint:7265e41f48f1:smerity_govarint/vendor/github.com/Smerity/govarint \
		ambientsound:gompd:b065d40b8238:ambientsound_gompd/vendor/github.com/ambientsound/gompd \
		blevesearch:bleve:v0.7.0:blevesearch_bleve/vendor/github.com/blevesearch/bleve \
		blevesearch:go-porterstemmer:v1.0.1:blevesearch_go_porterstemmer/vendor/github.com/blevesearch/go-porterstemmer \
		blevesearch:segment:762005e7a34f:blevesearch_segment/vendor/github.com/blevesearch/segment \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		couchbase:vellum:35d9e7346a69:couchbase_vellum/vendor/github.com/couchbase/vellum \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		edsrzf:mmap-go:0bce6a688712:edsrzf_mmap_go/vendor/github.com/edsrzf/mmap-go \
		gdamore:encoding:b23993cbb635:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v1.1.0:gdamore_tcell/vendor/github.com/gdamore/tcell \
		glycerine:go-unsnap-stream:9f0cb55181dd:glycerine_go_unsnap_stream/vendor/github.com/glycerine/go-unsnap-stream \
		golang:net:161cd47e91fd:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.2.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:2e65f85255db:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:bbd175535a8b:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		lucasb-eyer:go-colorful:c7842319cf3a:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:v0.0.3:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mschoch:smat:90eadee771ae:mschoch_smat/vendor/github.com/mschoch/smat \
		philhofer:fwd:v1.0.0:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		steveyen:gtreap:0abe01ef9be2:steveyen_gtreap/vendor/github.com/steveyen/gtreap \
		stretchr:testify:v1.2.2:stretchr_testify/vendor/github.com/stretchr/testify \
		tinylib:msgp:v1.0.2:tinylib_msgp/vendor/github.com/tinylib/msgp \
		willf:bitset:v1.1.9:willf_bitset/vendor/github.com/willf/bitset

GO_BUILDFLAGS=	-ldflags "-X main.buildVersion=${DISTVERSION}"
GO_TARGET=	:pms-devel

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
