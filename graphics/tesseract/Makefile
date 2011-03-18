# New ports collection makefile for:	tesseract
# Date created:		18 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tesseract
PORTVERSION=	3.00
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} eng.traineddata.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Commercial quality open source OCR engine

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

DIST_SUBDIR=	${PORTNAME}
PROJECTHOST=	tesseract-ocr

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBTIFF_CFLAGS="-I${LOCALBASE}/include"\
		LIBTIFF_LIBS="-L${LOCALBASE}/lib -ltiff"
LICENSE=	ASL
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

TESSERACT_XTERM ?=	${LOCALBASE}/bin/xterm

.ifndef NOPORTDATA
DATADIR=	${PREFIX}/share/tessdata
PORTDATA=	eng.traineddata
.endif

.ifndef NOPORTDOCS
PORTDOCS=	AUTHORS ChangeLog NEWS README ReleaseNotes
.endif

.ifndef NOPORTEXAMPLES
PORTEXAMPLES=	eurotext.tif phototest.tif
.endif

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The fallback xterm-compatible terminal to be used"
	@${ECHO_MSG} "for debugging purposes may be overridden by"
	@${ECHO_MSG} "defining TESSERACT_XTERM"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/xterm|${TESSERACT_XTERM}|'\
		${WRKSRC}/ccutil/debugwin.cpp
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|'\
		${WRKSRC}/configure

post-install:
.ifndef NOPORTDATA
	@${INSTALL} -d ${DATADIR}/
.for datafile in ${PORTDATA}
	@${GUNZIP_CMD} -c ${_DISTDIR}/${datafile}.gz > ${DATADIR}/${datafile}
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DATADIR}/${datafile}
	@${CHMOD} ${SHAREMODE} ${DATADIR}/${datafile}
.endfor
.endif
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
.ifndef NOPORTEXAMPLES
	@${INSTALL} -d ${EXAMPLESDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}/
.endif
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
