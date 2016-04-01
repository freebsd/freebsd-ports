# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tesseract
PORTVERSION=	3.02.02
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
DISTFILES=	tesseract-ocr-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Commercial quality open source OCR engine

OPTIONS_DEFINE=	DOCS EXAMPLES

LICENSE=	APACHE20

LIB_DEPENDS=	liblept.so:graphics/leptonica

DIST_SUBDIR=	${PORTNAME}
PROJECTHOST=	tesseract-ocr
WRKSRC=		${WRKDIR}/tesseract-ocr

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LIBLEPT_HEADERSDIR="${LOCALBASE}/include/leptonica"
LIBS+=		-L${LOCALBASE}/lib

DATADIR=	${PREFIX}/share/tessdata
PORTDATA=	*
PORTDOCS=	AUTHORS ChangeLog README ReleaseNotes html
PORTEXAMPLES=	eurotext.tif phototest.tif

DOCS_DISTFILES=	tesseract-ocr-${PORTVERSION}-doc-html${EXTRACT_SUFX}

post-patch:
	@${REINPLACE_CMD} -e 's|-O3 -DNDEBUG||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
	's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
	${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS:Nhtml} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
