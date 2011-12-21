# New ports collection makefile for:	tesseract-data
# Date created:		18 March 2011
# Whom:			bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tesseract-data
PORTVERSION=	3.01
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${TESSERACT_LANGS_300:O:u:S|$|.traineddata.gz|} \
		${TESSERACT_LANGS_301:O:u:S|^|tesseract-ocr-3.01.|:S|$|.tar.gz|}
EXTRACT_ONLY=	#empty

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Additional trained language data for the Tesseract OCR engine

LICENSE=	ASL

DIST_SUBDIR=	tesseract
PROJECTHOST=	tesseract-ocr

NO_BUILD=	yes

LANGS_300=	bul cat ces chi_sim chi_tra chr dan dan-frak deu deu-frak ell \
		fin fra hun ind ita jpn kor lav lit nld nor pol por ron rus slk \
		slv spa srp swe swe-frak tgl tur ukr vie

LANGS_301=	ara heb hin slk-frak tha

.if make(makesum)
TESSERACT_LANGS=	${LANGS_300} ${LANGS_301}
.else
TESSERACT_LANGS ?=	${LANGS_300} ${LANGS_301}
.endif

TESSERACT_LANGS_300=
TESSERACT_LANGS_301=

.for l in ${TESSERACT_LANGS}
TESSERACT_LANGS_300+=	${LANGS_300:M${l}}
TESSERACT_LANGS_301+=	${LANGS_301:M${l}}
.endfor

PLIST_DIRSTRY=	share/tessdata
PLIST_FILES=	${TESSERACT_LANGS:O:u:S|$|.traineddata|:S|^|share/tessdata/|}

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The choice of language data to be installed may"
	@${ECHO_MSG} "be overridden by defining TESSERACT_LANGS. "
	@${ECHO_MSG} ""

do-install:
	@${INSTALL_DATA} -d ${PREFIX}/share/tessdata
.for l in ${TESSERACT_LANGS_300:O:u:S|$|.traineddata|}
	@${GUNZIP_CMD} -c ${_DISTDIR}/${l}.gz > ${PREFIX}/share/tessdata/${l}
.endfor
.for l in ${TESSERACT_LANGS_301:O:u}
	@${TAR} --strip-components 2 -C ${PREFIX}/share/tessdata \
	-xf ${_DISTDIR}/tesseract-ocr-3.01.${l}.tar.gz *.traineddata
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/tessdata
	@${CHMOD} -R ${SHAREMODE} ${PREFIX}/share/tessdata

.include <bsd.port.mk>
