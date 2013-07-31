# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	baekmukfonts
PORTVERSION=	2.0
PORTREVISION=	5
CATEGORIES=	korean x11-fonts
MASTER_SITES=	ftp://ftp.mizi.com/pub/baekmuk/obsoletes/ \
		ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/
PKGNAMESUFFIX=	-bdf
DISTNAME=	baekmuk-${PORTVERSION}
DISTFILES=	baekmuk-${PORTVERSION}${EXTRACT_SUFX} \
		batang10.bdf.gz batang10b.bdf.gz \
		gulim10.bdf.gz gulim10b.bdf.gz
EXTRACT_ONLY=	baekmuk-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Hangul fonts for X11(baekmuk)

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

FONTLIST=	batang10 batang10b batang12 batang12b batang14 batang14b \
		batang16 batang16b batang18 batang18b batang20 batang20b \
		batang24 batang24b \
		dotum10 dotum12 dotum14 dotum16 dotum18 dotum20 dotum24 \
		gulim10 gulim10b gulim12 gulim12b gulim14 gulim14b gulim16 \
		gulim16b gulim18 gulim18b gulim20 gulim20b gulim24 gulim24b \
		hline10 hline12 hline14 hline16 hline18 hline20 hline24

FONTLIST_MANUAL =	batang10 batang10b gulim10 gulim10b

BDFTOPCF=	${PREFIX}/bin/bdftopcf
MKFONTDIR=	${PREFIX}/bin/mkfontdir
CHARSETSUB=	s/ksx1001.1997/ksc5601.1987/g
FONTSDIR=	lib/X11/fonts/local
MAKE_ENV=	FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}
USES=		perl5
USE_PERL5=	build

# manually install hinted fonts
do-configure:
.for FONTNAME in ${FONTLIST_MANUAL}
	${GZIP_CMD} -cd ${_DISTDIR}/${FONTNAME}.bdf.gz \
		> ${WRKDIR}/${FONTNAME}.bdf
.endfor

# change charset to ksc5601.1987...
do-build:
.for FONTNAME in ${FONTLIST}
	${PERL} -pi -e ${CHARSETSUB} ${WRKDIR}/${FONTNAME}.bdf
	${BDFTOPCF} ${WRKDIR}/${FONTNAME}.bdf | ${GZIP_CMD} -c \
		> ${WRKDIR}/${FONTNAME}.pcf.gz
.endfor

do-install:
	@${MKDIR} ${PREFIX}/${FONTSDIR}
.for FONTNAME in ${FONTLIST}
	${INSTALL_DATA} ${WRKDIR}/${FONTNAME}.pcf.gz \
			${PREFIX}/${FONTSDIR}
.endfor
	@(cd ${PREFIX}/${FONTSDIR} && mkfontdir .)

.include <bsd.port.mk>
