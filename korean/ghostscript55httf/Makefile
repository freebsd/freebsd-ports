# New ports collection makefile for:	freetype-ghostscript
# Version required:	5.10ft
# Date created:		27 Mar 1998
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#
# Based on print/ghostscript5 and japanese/vfghostscript5
#   use Adobe's CID-keyed Korean font because there are no wide accepted
#   default korean font yet
#

DISTNAME=	ko-ghostscript-ft-5.10
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.pdb.sni.de/pub/utilities/misc/	\
		http://www.ozemail.com.au/~geoffk/pdfencrypt/	\
		ftp://ftp.cs.wisc.edu/ghost/gnu/gs510/	\
		$(MASTER_SITE_GNU) \
		http://www.ldl.jaist.ac.jp/~akr/nonresearch/free-software/ghostscript/ \
		http://itohws03.ee.noda.sut.ac.jp/~matsuda/VFlib-FT/ \
		ftp://ftp.kr.freebsd.org/pub/users/cjh/gs-ko/ \
		ftp://ftp.kr.freebsd.org/pub/users/cjh/gs-ko/misc/
MASTER_SITE_SUBDIR=	ghostscript
DISTFILES=	${PCL3_DRV} ${DECRYPT_PDF} ${GS_SOURCES} \
		${VFLIB_GS} ${KFFTYPE} ${KFFTYPE_PATCH} \
		${HFFTYPE} ${GS_CID_PATCH}

MAINTAINER=	cjh@kr.FreeBSD.org

RUN_DEPENDS=	$(LOCALBASE)/share/ghostscript/fonts/CMap:${PORTSDIR}/korean/munhwafonts-cid \
		$(LOCALBASE)/share/ghostscript/fonts:${PORTSDIR}/print/gsfonts
BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/graphics/jpeg:extract \
		/nonexistent:${PORTSDIR}/graphics/png:extract
LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png \
		ttf.4:${PORTSDIR}/print/freetype

USE_XLIB=	yes
EXTRACT_ONLY=	${GS_SOURCES} ${PCL3_DRV}
WRKSRC=		${WRKDIR}/gs5.10

MAKEFILE=	unix-gcc.mak
#MAKE_FLAGS=	prefix=${PREFIX} CFLAGS="${CFLAGS}" -f
MAKE_FLAGS=	prefix=${PREFIX} -f
MAN1=		gs.1 pdf2dsc.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1 gs-hpdj.1

GS_SOURCES=	ghostscript-5.10.tar.gz

# Additional driver for HP PCL3 Printers
PCL3_DRV=	hpdj-2.5.tar.gz

# replacement for pdf_sec.ps, that allows you to read encrypted PDF files
DECRYPT_PDF=	pdf_sec.ps

# Korean patch files
# vflib patch
VFLIB_GS=       gs5.10-vflib-1.1.tar.gz
# kfftype
KFFTYPE=        gs5-kfftype.tar.gz
# kfftype patches
KFFTYPE_PATCH=  gs5-kfftype-patch1.diff gs5-kfftype-patch2.diff
# hfftype patch
HFFTYPE=        gs5-hfftype-0.2.tar.gz
# cid-keyed font bug patch for 5.10
GS_CID_PATCH=   gs5.10-cid-bugfix.diff

post-extract:
	${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../../graphics/jpeg/work/jpeg-6b ${WRKSRC}/jpeg
	${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../../graphics/png/work/libpng-1.0.3 ${WRKSRC}/libpng
	# additional PCL3  driver
	$(TAR) -xvf ${WRKDIR}/hpdj-2.5/hpdj.tar -C $(WRKSRC)
	${PATCH} --directory=${WRKSRC} <${WRKSRC}/devs.mak-5.10.diff
	${PATCH} --directory=${WRKSRC} <${WRKSRC}/zmedia2.c-5.10.diff

pre-patch:
	cd ${WRKSRC} && tar -xzf ${DISTDIR}/${VFLIB_GS} && \
	${PATCH} -s -p1 < gs5.10-vflib-1.1/gs5.10-vflib-1.1.diff
	cd ${WRKSRC} && tar -xzf ${DISTDIR}/${KFFTYPE} && \
	cd ${WRKSRC}/kfftype &&  \
	for file in ${KFFTYPE_PATCH}; do \
		${PATCH} -s -p0 < ${DISTDIR}/$$file; \
	done && \
	${CP} -r ${WRKSRC}/kfftype/* ${WRKSRC}/
	cd ${WRKSRC} && tar -xzf ${DISTDIR}/${HFFTYPE} && \
	${CP} -r ${WRKSRC}/gs5-hfftype-0.2/* ${WRKSRC}/
	cd ${WRKSRC} && ${PATCH} -s -p1 < \
	${WRKSRC}/gs5-hfftype-0.2/gs5.10-hfftype.diff
	cd ${WRKSRC} && ${PATCH} ${PATCH_DIST_ARGS} < \
	${DISTDIR}/${GS_CID_PATCH}

do-configure:
	@(cd ${WRKSRC}; ${SH} tar_cat )

pre-install:
	@${MKDIR} ${PREFIX}/share/ghostscript ${PREFIX}/bin ${PREFIX}/man/man1

post-install:
	strip ${PREFIX}/bin/gs
	${INSTALL_DATA} ${DISTDIR}/${DECRYPT_PDF} \
		${PREFIX}/share/ghostscript/5.10ft
	$(MKDIR) ${PREFIX}/libexec/lpr
	${INSTALL_SCRIPT} $(WRKSRC)/pj-gs.sh ${PREFIX}/libexec/lpr
	${INSTALL_SCRIPT} $(WRKSRC)/sysvlp.sh ${PREFIX}/libexec/lpr
	${INSTALL_SCRIPT} $(WRKSRC)/if-hpdj ${PREFIX}/libexec/lpr
	${INSTALL_DATA} ${WRKSRC}/gs5-hfftype-0.2/README \
		${PREFIX}/share/ghostscript/5.10ft/doc/README.ko

.include <bsd.port.mk>
