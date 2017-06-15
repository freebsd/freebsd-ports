# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tesseract-data
PORTVERSION=	3.04.00
CATEGORIES=	graphics

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Trained language data for the Tesseract OCR engine

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	tesseract-ocr
GH_PROJECT=	tessdata

NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/tessdata
TESSERACT_LANGS?=afr amh ara asm aze aze_cyrl bel ben bod bos bul cat ceb ces \
		chi_sim chi_tra chr cym dan dan_frak deu deu_frak dzo ell eng \
		enm epo equ est eus fas fin fra frk frm gle glg grc guj hat heb \
		hin hrv hun iku ind isl ita ita_old jav jpn kan kat kat_old kaz \
		khm kir kor kur lao lat lav lit mal mar mkd mlt msa mya nep nld \
		nor ori osd pan pol por pus ron rus san sin slk slk_frak slv spa \
		spa_old sqi srp srp_latn swa swe syr tam tel tgk tgl tha tir tur \
		uig ukr urd uzb uzb_cyrl vie yid

PORTDATA=	${TESSERACT_LANGS:O:u:S|$|.traineddata|}

BROKEN_aarch64=		Fails to install: runaway process
BROKEN_sparc64=		Fails to install: runaway process

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for l in ${PORTDATA}
	@${CP} ${WRKSRC}/${l} ${STAGEDIR}${DATADIR}/
.endfor
	@cd ${STAGEDIR}${DATADIR} ; ${CHMOD} ${BINMODE} ${PORTDATA}

.include <bsd.port.mk>
