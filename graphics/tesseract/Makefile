# New ports collection makefile for:	tesseract
# Date created:		18 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tesseract
DISTVERSION=	2.00
CATEGORIES=	graphics
MASTER_SITES=	http://tesseract-ocr.googlecode.com/files/ CENKES
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LANGFILES}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Commercial quality open source OCR engine

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	xterm:${PORTSDIR}/x11/xterm

LANGS=	deu eng fra ita nld spa
LANGFILES=	${LANGS:S|^|${DISTNAME}.|:S|$|${EXTRACT_SUFX}|}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBTIFF_CFLAGS="-I${LOCALBASE}/include"\
		LIBTIFF_LIBS="-L${LOCALBASE}/lib -ltiff"
PORTDOCS=	AUTHORS ChangeLog NEWS README ReleaseNotes
PORTEXAMPLES=	eurotext.tif phototest.tif
PORT_VERBS=	cntraining mftraining tessdata unicharset_extractor \
		wordlist2dawg ${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/X11/xterm|${LOCALBASE}/bin/xterm|'\
		${WRKSRC}/ccutil/debugwin.cpp

post-install:
	@cd ${WRKDIR}/tessdata/&&${COPYTREE_SHARE} . ${PREFIX}/share/tessdata/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
.ifndef NOPORTEXAMPLES
	@${INSTALL} -d ${EXAMPLESDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
