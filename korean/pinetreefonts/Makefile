# New ports collection makefile for:	pinetree fonts(x11)
# Date created:		22 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	pinetreefonts
PORTVERSION=	1.01
CATEGORIES=	korean x11-fonts
MASTER_SITES=	ftp://cglab.snu.ac.kr/pub/hangul/n3f/tar/ \
		ftp://ftp.kaist.ac.kr/pub/hangul/fonts/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/fonts/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
DISTNAME=	pinetree.precomposed-${PORTVERSION}-bdf

MAINTAINER=	cjh@FreeBSD.org

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

WRKSRC=		${WRKDIR}/pinetree.precomposed/bdf

FONTS=		ptpR08 ptpR10 ptpR12 ptpR14 ptpR18 ptpR24 \
		ptpB08 ptpB10 ptpB12 ptpB14 ptpB18 ptpB24 \
		ptptB14 pttpB14

do-build:
	@cd ${WRKSRC}/; \
	sh Makepcf; \
	${GZIP_CMD} *.pcf; \
	mkfontdir .

do-install:
	-${MKDIR} ${PREFIX}/lib/X11/fonts/local
	@cd ${WRKSRC}; \
	for file in ${FONTS}; do \
		${INSTALL_DATA} "$$file".pcf.gz ${PREFIX}/lib/X11/fonts/local; \
	done; \
	mkfontdir ${PREFIX}/lib/X11/fonts/local

.include <bsd.port.post.mk>
