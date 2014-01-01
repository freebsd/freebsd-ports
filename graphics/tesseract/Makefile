# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tesseract
PORTVERSION=	3.02.02
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	tesseract-ocr-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Commercial quality open source OCR engine

LICENSE=	APACHE20

LIB_DEPENDS=	lept:${PORTSDIR}/graphics/leptonica

DIST_SUBDIR=	${PORTNAME}
PROJECTHOST=	tesseract-ocr
WRKSRC= 	${WRKDIR}/tesseract-ocr

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LIBLEPT_HEADERSDIR="${LOCALBASE}/include/leptonica" \
		LIBS="${PTHREAD_LIBS}"
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.ifndef NOPORTDATA
DATADIR=        ${PREFIX}/share/tessdata
MAN1=		ambiguous_words.1 cntraining.1 combine_tessdata.1 dawg2wordlist.1 \
		mftraining.1 shapeclustering.1 tesseract.1 unicharset_extractor.1 \
		wordlist2dawg.1
MAN5=		unicharambigs.5 unicharset.5
PORTDATA=	*
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	AUTHORS ChangeLog README ReleaseNotes html
.endif

.if ${PORT_OPTIONS:MDOCS} || make(makesum)
DISTFILES+=	tesseract-ocr-${PORTVERSION}-doc-html${EXTRACT_SUFX}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	eurotext.tif phototest.tif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3 -DNDEBUG||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
	's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
	${WRKSRC}/Makefile.in
.ifdef NOPORTDATA
	@${FIND} ${WRKSRC} -type f -name 'Makefile.in' -print0 | ${XARGS} -0 \
	${REINPLACE_CMD} -e '\|^install-am:|,+1s|install-data-am||'
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS:Nhtml} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.mk>
