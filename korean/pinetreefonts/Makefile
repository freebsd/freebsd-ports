# New ports collection makefile for:	pinetree fonts
# Version required:     1.0
# Date created:		22 Mar 1997
# Whom:			Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.1.1.1 1997/03/29 12:58:32 max Exp $
#

DISTNAME=       pinetree.precomposed-1.0
PKGNAME=	kr-pinetreefonts-1.0
CATEGORIES=	korean x11
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/fonts/ \
		ftp://cglab.snu.ac.kr/pub/hangul/n3f/fonts/ \
		ftp://sunsite.kren.nm.kr/pub/packages/hangul/fonts/
EXTRACT_SUFX=	.bdf.tar.gz
MAINTAINER=	junker@jazz.snu.ac.kr

USE_X11=	yes

do-build:
	@cd ${WRKSRC}/; \
	sh Makepcf; \
	compress *.pcf; \
	mkfontdir .

do-install:
	@cd ${WRKSRC}; \
	${MKDIR} ${PREFIX}/lib/X11/fonts/korean/pinetree; \
	${INSTALL_DATA} ptpR08.pcf.Z ${PREFIX}/lib/X11/fonts/korean/pinetree; \
	${INSTALL_DATA} ptpR10.pcf.Z ${PREFIX}/lib/X11/fonts/korean/pinetree; \
	${INSTALL_DATA} ptpR12.pcf.Z ${PREFIX}/lib/X11/fonts/korean/pinetree; \
	${INSTALL_DATA} ptpR14.pcf.Z ${PREFIX}/lib/X11/fonts/korean/pinetree; \
	${INSTALL_DATA} ptpR18.pcf.Z ${PREFIX}/lib/X11/fonts/korean/pinetree; \
	${INSTALL_DATA} ptpR24.pcf.Z ${PREFIX}/lib/X11/fonts/korean/pinetree; \
	${INSTALL_DATA} ptpB08.pcf.Z ${PREFIX}/lib/X11/fonts/korean/pinetree; \
	${INSTALL_DATA} ptpB10.pcf.Z ${PREFIX}/lib/X11/fonts/korean/pinetree; \
	${INSTALL_DATA} ptpB12.pcf.Z ${PREFIX}/lib/X11/fonts/korean/pinetree; \
	${INSTALL_DATA} ptpB14.pcf.Z ${PREFIX}/lib/X11/fonts/korean/pinetree; \
	${INSTALL_DATA} ptpB18.pcf.Z ${PREFIX}/lib/X11/fonts/korean/pinetree; \
	${INSTALL_DATA} ptpB24.pcf.Z ${PREFIX}/lib/X11/fonts/korean/pinetree; \
	${INSTALL_DATA} fonts.dir ${PREFIX}/lib/X11/fonts/korean/pinetree

# to show a warning message to add fontpath for these fonts
post-install:
	@${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

.include <bsd.port.mk>
