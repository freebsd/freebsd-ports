# New ports collection makefile for:	pinetree fonts(x11)
# Version required:     1.0
# Date created:		22 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.4 1998/04/30 14:39:06 kuriyama Exp $
#

DISTNAME=       pinetree.precomposed-1.0
PKGNAME=	ko-pinetreefonts-1.0
CATEGORIES=	korean x11
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/fonts/ \
		ftp://cglab.snu.ac.kr/pub/hangul/n3f/fonts/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/fonts/
EXTRACT_SUFX=	.bdf.tar.gz

MAINTAINER=	junker@jazz.snu.ac.kr

USE_X_PREFIX=	yes

FONTS=		ptpR08 ptpR10 ptpR12 ptpR14 ptpR18 ptpR24 \
		ptpB08 ptpB10 ptpB12 ptpB14 ptpB18 ptpB24

do-build:
	@cd ${WRKSRC}/; \
	sh Makepcf; \
	${GZIP_CMD} *.pcf; \
	mkfontdir .

do-install:
	@cd ${WRKSRC}; \
	for file in ${FONTS}; do \
		${INSTALL_DATA} "$$file".pcf.gz ${PREFIX}/lib/X11/fonts/misc; \
	done; \
	mkfontdir ${PREFIX}/lib/X11/fonts/misc

.include <bsd.port.mk>
