# New ports collection makefile for:	tesseract
# Date created:		18 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tesseract
PORTVERSION=	3.01
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
.if !defined(NOPORTDATA) || make(makesum)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		tesseract-ocr-3.01.eng.tar.gz tesseract-ocr-3.01.osd.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Commercial quality open source OCR engine

LICENSE=	ASL

LIB_DEPENDS=	lept.2:${PORTSDIR}/graphics/leptonica

DIST_SUBDIR=	${PORTNAME}
PROJECTHOST=	tesseract-ocr

USE_AUTOTOOLS=	automake
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LIBLEPT_HEADERSDIR="${LOCALBASE}/include/leptonica"
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=	cntraining.1 combine_tessdata.1 mftraining.1 tesseract.1 \
	unicharset_extractor.1 wordlist2dawg.1
MAN5=	unicharambigs.5 unicharset.5

.include <bsd.port.pre.mk>

.if defined(USE_GCC) || !empty(CC:M*gcc4*)
CXXFLAGS+=	-fpermissive
.endif

.ifndef NOPORTDATA
DATADIR=	${PREFIX}/share/tessdata
PORTDATA=	eng.traineddata osd.traineddata
.endif

.ifndef NOPORTDOCS
PORTDOCS=	AUTHORS ChangeLog README ReleaseNotes
.endif

.ifndef NOPORTEXAMPLES
PORTEXAMPLES=	eurotext.tif phototest.tif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|'\
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '1s|.*|/*|' ${WRKSRC}/ccutil/strngs.h

post-install:
.ifndef NOPORTDATA
	@${INSTALL_DATA} -d ${DATADIR}
.for f in ${PORTDATA:R}
	@${TAR} --strip-components 2 -C ${DATADIR} \
	-xf ${_DISTDIR}/tesseract-ocr-3.01.${f}.tar.gz *.traineddata
.endfor
	@cd ${DATADIR}; ${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PORTDATA}; \
	${CHMOD} ${SHAREMODE} ${PORTDATA}
.endif
.ifndef NOPORTDOCS
	@${INSTALL_DATA} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.ifndef NOPORTEXAMPLES
	@${INSTALL_DATA} -d ${EXAMPLESDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
