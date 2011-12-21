# New ports collection makefile for:	tesseract-data
# Date created:		18 March 2011
# Whom:			bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tesseract-data
PORTVERSION=	3.00
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${TESSERACT_LANGS:O:u:S|$|.traineddata.gz|}
EXTRACT_ONLY=	#empty

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Additional trained language data for the Tesseract OCR engine

DIST_SUBDIR=	tesseract
PROJECTHOST=	tesseract-ocr

LICENSE=	ASL
NO_BUILD=	yes

EXTRA_LANGS=	bul cat ces chi_sim chi_tra chr dan dan-frak deu deu-frak ell \
		fin fra hun ind ita jpn kor lav lit nld nor pol por ron rus slk \
		slv spa srp swe swe-frak tgl tur ukr vie

.if make(makesum)
TESSERACT_LANGS=	${EXTRA_LANGS}
.else
TESSERACT_LANGS ?=	${EXTRA_LANGS}
.endif

PLIST_DIRSTRY=	share/tessdata
PLIST_FILES=	${TESSERACT_LANGS:O:u:S|$|.traineddata|:S|^|share/tessdata/|}

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The choice of language data to be installed may"
	@${ECHO_MSG} "be overridden by defining TESSERACT_LANGS. "
	@${ECHO_MSG} ""

do-install:
	@${INSTALL} -d ${PREFIX}/share/tessdata/
.for datafile in ${TESSERACT_LANGS:O:u:S|$|.traineddata|}
	@${GUNZIP_CMD} -c ${_DISTDIR}/${datafile}.gz > ${PREFIX}/share/tessdata/${datafile}
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/tessdata/${datafile}
	@${CHMOD} ${SHAREMODE} ${PREFIX}/share/tessdata/${datafile}
.endfor

.include <bsd.port.mk>
