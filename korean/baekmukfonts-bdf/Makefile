# New ports collection makefile for:	baekmuk fonts(x11)
# Version required:     1.1
# Date created:		23 Jul 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

DISTNAME=       baekmuk-1.1
PKGNAME=	ko-baekmukfonts-bdf-1.1
CATEGORIES=	korean x11-fonts
MASTER_SITES=	ftp://ftp.mizi.co.kr/pub/baekmuk/ \
		http://www.FreeBSD.org/~sada/distfiles/
DISTFILES=	baekmuk-1.1.tar.gz gulim12-19990903.bdf.gz
EXTRACT_ONLY=	baekmuk-1.1.tar.gz

MAINTAINER=	cjh@kr.freebsd.org

USE_X_PREFIX=	yes

FONTLIST=	batang10 batang10b batang12 batang12b batang14 batang14b \
		batang16 batang16b batang18 batang18b batang20 batang20b \
		batang24 batang24b \
		dotum10 dotum12 dotum14 dotum16 dotum18 dotum20 dotum24 \
		gulim10 gulim10b gulim12 gulim12b gulim14 gulim14b gulim16 \
		gulim16b gulim18 gulim18b gulim20 gulim20b gulim24 gulim24b \
		hline10 hline12 hline14 hline16 hline18 hline20 hline24

BDFTOPCF=	${PREFIX}/bin/bdftopcf
MKFONTDIR=	${PREFIX}/bin/mkfontdir

do-build:
	${GUNZIP_CMD} -c ${_DISTDIR}/gulim12-19990903.bdf.gz \
		> ${WRKDIR}/gulim12.bdf
.for FONTNAME in ${FONTLIST}
	${BDFTOPCF} ${WRKDIR}/${FONTNAME}.bdf | ${GZIP_CMD} -c \
		> ${WRKDIR}/${FONTNAME}.pcf.gz
.endfor

do-install:
	-mkdir -p ${PREFIX}/lib/X11/fonts/baekmuk
.for FONTNAME in ${FONTLIST}
	${INSTALL_DATA} ${WRKDIR}/${FONTNAME}.pcf.gz \
			${PREFIX}/lib/X11/fonts/baekmuk
.endfor
	${INSTALL_DATA} ${WRKDIR}/fonts.alias ${PREFIX}/lib/X11/fonts/baekmuk
	${MKFONTDIR} ${PREFIX}/lib/X11/fonts/baekmuk

post-install:
	@${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

.include <bsd.port.mk>
