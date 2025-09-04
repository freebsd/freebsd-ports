PORTNAME=	ncbi-entrez-direct
DISTVERSION=	14.9.20210423
PORTREVISION=	31
CATEGORIES=	biology perl5
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/entrez/entrezdirect/versions/${PORTVERSION}/
DISTFILES=	edirect.tar.gz
DIST_SUBDIR=	edirect-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Access to the NCBI's suite of interconnected databases
WWW=		https://www.ncbi.nlm.nih.gov/books/NBK179288/

LICENSE=	PD

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		curl:ftp/curl

USES=		go:modules perl5 shebangfix
USE_GITHUB=	nodefault

CONFLICTS_INSTALL=	ebook-tools p5-XML-Compile # bin/einfo bin/xml2json

# Dependency versions:
#	make clean extract
# 	cd ${WRKSRC}/cmd
#	rm -r vendor
#	../../../files/build-cmd
# files/modules.txt: cd ${WRKSRC}/cmd && go mod vendor
GHSD=		vendor/github.com
GLSD=		vendor/golang.org
GH_TUPLE=	fatih:color:v1.10.0:a/${GHSD}/fatih/color \
		surgebase:porter2:56e4718818e8:b/${GHSD}/surgebase/porter2 \
		gedex:inflector:16278e9db813:c/${GHSD}/gedex/inflector \
		klauspost:cpuid:v1.3.1:d/${GHSD}/klauspost/cpuid \
		pbnjay:memory:b12e5d931931:e/${GHSD}/pbnjay/memory \
		mattn:go-colorable:v0.1.8:f/${GHSD}/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:g/${GHSD}/mattn/go-isatty \
		fiam:gounidecode:8deddbd03fec:h/${GHSD}/fiam/gounidecode \
		golang:text:v0.3.5:i/${GLSD}/x/text \
		golang:sys:v0.5.0:j/${GLSD}/x/sys

SHEBANG_FILES=	nquire edirect.pl word-at-a-time accn-at-a-time \
		amino-acid-composition between-two-genes exclude-uid-lists \
		filter-stop-words intersect-uid-lists phrase-search \
		skip-if-file-exists theme-aliases test-edirect hgvs2spdi

PSCRIPTS=	efetch efilter einfo elink epost esearch esummary nquire
SCRIPTS=	accn-at-a-time amino-acid-composition archive-pubmed \
		between-two-genes download-ncbi-data download-pubmed \
		download-sequence efetch efilter einfo elink epost \
		esample esearch esummary exclude-uid-lists expand-current \
		fetch-pubmed filter-stop-words gbf2xml index-extras \
		index-pubmed intersect-uid-lists join-into-groups-of \
		nquire phrase-search pm-collect pm-index pm-invert pm-merge \
		pm-prepare pm-promote pm-refresh pm-stash rchive \
		reorder-columns run-ncbi-converter skip-if-file-exists \
		ecommon.sh sort-uniq-count sort-uniq-count-rank stream-pubmed \
		theme-aliases transmute word-at-a-time xml2tbl xtract xy-plot \
		hlp-xtract.txt transmute xml2json xtract test-edirect \
		align-columns hgvs2spdi sort-table print-columns

post-extract:
	@${MV} ${WRKDIR}/edirect/* ${WRKSRC}
	@${RMDIR} ${WRKDIR}/edirect
	@${MV} ${WRKSRC}/vendor ${WRKSRC}/cmd

pre-configure:
	@cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's|$$PATH:$$pth|$$PATH:${PREFIX}/bin|g' \
		-e 's|"$$pth"|${PREFIX}/bin|g' \
		${PSCRIPTS}

do-build:
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/cmd/vendor
	@${CP} -R ${WRKSRC}/eutils ${WRKSRC}/cmd/vendor
	@cd ${WRKSRC}/cmd && ${SETENV} ${MAKE_ENV} ${FILESDIR}/build-cmd

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/edirect.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/*.FreeBSD ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
