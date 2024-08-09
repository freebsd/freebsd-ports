PORTNAME=	pms-devel
PORTVERSION=	0.0.20231224
PORTREVISION=	7
CATEGORIES=	audio

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Rewrite of pms, an ncurses-based client for the Music Player Daemon
WWW=		https://github.com/ambientsound/pms

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.21,modules

USE_GITHUB=	yes
GH_ACCOUNT=	kimtore
GH_PROJECT=	pms
GH_TAGNAME=	628d497

GH_TUPLE=	\
		RoaringBitmap:roaring:v0.9.4:roaringbitmap_roaring/vendor/github.com/RoaringBitmap/roaring \
		bits-and-blooms:bitset:v1.2.0:bits_and_blooms_bitset/vendor/github.com/bits-and-blooms/bitset \
		blevesearch:bleve:v2.3.4:blevesearch_bleve_v2/vendor/github.com/blevesearch/bleve/v2 \
		blevesearch:bleve_index_api:v1.0.3:blevesearch_bleve_index_api/vendor/github.com/blevesearch/bleve_index_api \
		blevesearch:geo:v0.1.13:blevesearch_geo/vendor/github.com/blevesearch/geo \
		blevesearch:go-porterstemmer:v1.0.3:blevesearch_go_porterstemmer/vendor/github.com/blevesearch/go-porterstemmer \
		blevesearch:gtreap:v0.1.1:blevesearch_gtreap/vendor/github.com/blevesearch/gtreap \
		blevesearch:mmap-go:v1.0.4:blevesearch_mmap_go/vendor/github.com/blevesearch/mmap-go \
		blevesearch:scorch_segment_api:v2.1.2:blevesearch_scorch_segment_api_v2/vendor/github.com/blevesearch/scorch_segment_api/v2 \
		blevesearch:segment:v0.9.0:blevesearch_segment/vendor/github.com/blevesearch/segment \
		blevesearch:snowballstem:v0.9.0:blevesearch_snowballstem/vendor/github.com/blevesearch/snowballstem \
		blevesearch:upsidedown_store_api:v1.0.1:blevesearch_upsidedown_store_api/vendor/github.com/blevesearch/upsidedown_store_api \
		blevesearch:vellum:v1.0.8:blevesearch_vellum/vendor/github.com/blevesearch/vellum \
		blevesearch:zapx:v11.3.5:blevesearch_zapx_v11/vendor/github.com/blevesearch/zapx/v11 \
		blevesearch:zapx:v12.3.5:blevesearch_zapx_v12/vendor/github.com/blevesearch/zapx/v12 \
		blevesearch:zapx:v13.3.5:blevesearch_zapx_v13/vendor/github.com/blevesearch/zapx/v13 \
		blevesearch:zapx:v14.3.5:blevesearch_zapx_v14/vendor/github.com/blevesearch/zapx/v14 \
		blevesearch:zapx:v15.3.5:blevesearch_zapx_v15/vendor/github.com/blevesearch/zapx/v15 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		etcd-io:bbolt:v1.3.5:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fhs:gompd:v2.3.0:fhs_gompd_v2/vendor/github.com/fhs/gompd/v2 \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.7.0:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:geo:740aa86cb551:golang_geo/vendor/github.com/golang/geo \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:v0.15.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.15.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		jessevdk:go-flags:v1.5.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		json-iterator:go:f7279a603ede:json_iterator_go/vendor/github.com/json-iterator/go \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-runewidth:v0.0.15:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mschoch:smat:v0.2.0:mschoch_smat/vendor/github.com/mschoch/smat \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.4.3:rivo_uniseg/vendor/github.com/rivo/uniseg \
		stretchr:testify:v1.7.1:stretchr_testify/vendor/github.com/stretchr/testify

GO_BUILDFLAGS=	-ldflags "-X main.buildVersion=${DISTVERSION}"
GO_TARGET=	:pms-devel

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
