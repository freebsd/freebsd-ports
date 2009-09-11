# New ports collection makefile for:	tesseract
# Date created:		18 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tesseract
DISTVERSION=	2.04
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} CENKES
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LANGFILES}

MAINTAINER=	bf1783@gmail.com
COMMENT=	Commercial quality open source OCR engine

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

PROJECTHOST=	tesseract-ocr
LANGS2_00?=	deu eng fra ita nld spa
LANGS2_01?=	deu-f por vie
LANGS2_04?=	eus

.for _N in 2_00 2_01 2_04
LANGFILES+=	${LANGS${_N}:S|^|${PORTNAME}-${_N:S|_|.|}.|:S|$|${EXTRACT_SUFX}|}
.endfor

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBTIFF_CFLAGS="-I${LOCALBASE}/include"\
		LIBTIFF_LIBS="-L${LOCALBASE}/lib -ltiff"
PORTDOCS=	AUTHORS ChangeLog NEWS README ReleaseNotes
PORTEXAMPLES=	eurotext.tif phototest.tif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/X11/xterm|${LOCALBASE}/bin/xterm|'\
		${WRKSRC}/ccutil/debugwin.cpp
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|'\
		${WRKSRC}/configure

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
