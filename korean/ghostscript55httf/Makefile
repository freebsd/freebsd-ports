# New ports collection makefile for:	ghostscript/ft
# Date created:		3 Jul 2000
# Whom:			CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ghostscript
PORTVERSION=	5.50
PORTREVISION=	1
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/aladdin/gs550/ \
		http://www.erdw.ethz.ch/~bonk/ftp/gs-driver-distrib/ \
		http://www.ozemail.com.au/~geoffk/pdfencrypt/
PKGNAMESUFFIX=	-httf
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${HP850_DRV} ${DECRYPT_PDF}
DIST_SUBDIR=	ghostscript

PATCH_SITES=	ftp://ftp.kr.FreeBSD.org/pub/users/cjh/gs-ko/
PATCHFILES=	gs5.50-httf-19990114_1.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	cjh@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/graphics/jpeg:extract \
		${NONEXISTENT}:${PORTSDIR}/graphics/png:extract \
		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	$(X11BASE)/lib/X11/fonts/TrueType/gulim.ttf:${PORTSDIR}/korean/baekmukfonts-ttf

USE_XLIB=	yes
USE_FREETYPE=	yes
EXTRACT_ONLY=	${GS_SOURCES}
WRKSRC=		${WRKDIR}/gs5.50
USE_GMAKE=	yes
MAKEFILE=	unix-gcc.mak
MAN1=		gs.1 pdf2dsc.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1 ps2ps.1

GS_SOURCES=	ghostscript-5.50.tar.gz
GS_SOURCES+=	ghostscript-5.50gnu.tar.gz
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	ghostscript-fonts-std-5.50.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-5.50.tar.gz

# Additional driver HP 850, see http://www.erdw.ethz.ch/~bonk/hp850/hp850.html
HP850_DRV=	hp8xxs13.zip

.if defined(NO_A4)
.else
CFLAGS+=	-DA4
.endif

pre-fetch:
.if !defined(NO_A4)
	@${ECHO_MSG} "Type \"make NO_A4=yes\" if you want not set A4 paper default."
.else
	@${ECHO_MSG} "Default paper size is A4."
.endif

post-extract:
	${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../../graphics/jpeg/work/jpeg-* ${WRKSRC}/jpeg
	${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../../graphics/png/work/libpng-* ${WRKSRC}/libpng
	${MV} ${WRKSRC}/devs.mak ${WRKSRC}/devs.mak.bak
	cd ${WRKSRC} && unzip -Lao ${_DISTDIR}/${HP850_DRV}
	${MV} ${WRKSRC}/devs.mak.bak ${WRKSRC}/devs.mak

do-configure:
.if defined(BATCH)
	@${SETENV} WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/configure.batch
.else
	@${SETENV} WRKSRC=${WRKSRC} ${SH} ${SCRIPTDIR}/configure
.endif

pre-build:
	${MKDIR} ${WRKSRC}/obj
	${SED}	-e "s@%%PREFIX%%@${X11BASE}@g" \
		${FILESDIR}/hconfig.ps.in > \
		${WRKSRC}/hangul/hconfig.ps

pre-install:
	@${MKDIR} ${PREFIX}/share/ghostscript ${PREFIX}/bin ${PREFIX}/man/man1
	(cd ${PREFIX}/share/ghostscript ; \
			${TAR} -xzf ${_DISTDIR}/${GS_FONTS_STD})
	(cd ${PREFIX}/share/ghostscript/fonts ; \
			${TAR} -xzf ${_DISTDIR}/${GS_FONTS_OTHER})

# install the readme and license file of the hp8xxx driver as well
post-install:
	strip ${PREFIX}/bin/gs
	${INSTALL_SCRIPT} ${WRKSRC}/unix-lpr.sh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lprsetup.sh ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/license.hp8 \
		${PREFIX}/share/ghostscript/5.50httf/doc
	${INSTALL_DATA} ${WRKSRC}/readme.hp8 \
		${PREFIX}/share/ghostscript/5.50httf/doc
	${RMDIR} ${PREFIX}/share/ghostscript/5.50httf/hangul/fonts
.if defined(PDFENCRYPT)
	${INSTALL_DATA} ${_DISTDIR}/pdf_sec.ps ${PREFIX}/share/ghostscript/5.50httf
.endif

# encrypted PDF support.  can't be packaged due to export control issues.
.if defined(PDFENCRYPT)
MASTER_SITES+=	http://www.ozemail.com.au/~geoffk/pdfencrypt/
DISTFILES+=	pdf_sec.ps
RESTRICTED=	"Crypto; export controlled, RC4 in PostScript code included"
.endif

.include <bsd.port.mk>
