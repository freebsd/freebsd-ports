# New ports collection makefile for:	freetype-ghostscript
# Version required:	5.10ft
# Date created:		Fri Mar 27 10:32:46 KST 1998
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.5 1998/12/22 08:12:20 asami Exp $
#
# based on print/ghostscript5 and japanese/vfghostscript5
# use Adobe's CID-keyed font sameple(korean) because there are no
# default korean font
#

DISTNAME=	ko-ftghostscript-5.10
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/aladdin/gs510/ \
		http://freefall.freebsd.org/~andreas/download/ \
		http://www.ozemail.com.au/~geoffk/pdfencrypt/ \
		http://www.ldl.jaist.ac.jp/~akr/nonresearch/free-software/ghostscript/ \
		http://itohws03.ee.noda.sut.ac.jp/~matsuda/VFlib-FT/ \
		ftp://jazz.snu.ac.kr/pub/unix/gs-ko/ \
		ftp://ftp.ora.com/pub/examples/nutshell/ujip/adobe/samples/ \
		ftp://ftp.ora.com/pub/examples/nutshell/ujip/adobe/
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${HP850_DRV} ${DECRYPT_PDF} ${VFLIB_GS} ${KFFTYPE} \
		${KFFTYPE_PATCH} ${HFFTYPE} ${GS_CID_PATCH} \
		${CID_FONTS_KO} ${CID_CMAP_KO}

MAINTAINER=	junker@jazz.snu.ac.kr


BROKEN_ELF=	yes

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/graphics/jpeg:extract \
		/nonexistent:${PORTSDIR}/graphics/png:extract \
		unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=    ttf.3:${PORTSDIR}/print/freetype

MAKE_ENV=	PORTSDIR=${PORTSDIR}
EXTRACT_ONLY=	${GS_SOURCES}
WRKSRC=		${WRKDIR}/gs5.10
MAKEFILE=	unix-gcc.mak
MAKE_FLAGS=	prefix=${PREFIX} zlibc_=-lz CFLAGS="${CFLAGS} -I${PREFIX}/include" -f
MAN1=		gs.1 pdf2dsc.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1

GS_SOURCES=	ghostscript-5.10.tar.gz
GS_SOURCES+=	ghostscript-5.10gnu.tar.gz
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	ghostscript-fonts-std-5.50.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-5.10.tar.gz

# Additional driver HP 850, see http://bonk.ethz.ch/hp850/hp850.html
HP850_DRV=	hp850-1.2.zip

# replacement for pdf_sec.ps, that allows you to read encrypted PDF files
DECRYPT_PDF=	pdf_sec.ps

# vflib patch
VFLIB_GS=	gs5.10-vflib-1.1.tar.gz

# kfftype
KFFTYPE=	gs5-kfftype.tar.gz

# kfftype patches
KFFTYPE_PATCH=	gs5-kfftype-patch1.diff gs5-kfftype-patch2.diff

# hfftype patch
HFFTYPE=	gs5-hfftype-0.2.tar.gz

# cid-keyed font bug patch for 5.10
GS_CID_PATCH=	gs5.10-cid-bugfix.diff

# sample fonts(cid, free Korean fonts is just only one.. :< )
CID_FONTS_KO=	Munhwa-Regular MunhwaGothic-Regular

# CID CMAP
CID_CMAP_KO=	ak11.tar.Z

# in Korea, A4 paper is default
.if !defined(NOA4)
CFLAGS+=	-DA4
.endif

pre-fetch:
.if !defined(NOA4)
	@${ECHO_MSG} "Type \"make NOA4=yes\" if you don't want A4 size default."
.else
	@${ECHO_MSG} "Default paper size is A4."
.endif
.if !defined(PDFENCRYPT)
	@${ECHO_MSG} "NOTE: You can have encrypted PDF support by adding "
	@${ECHO_MSG} "\"PDFENCRYPT=yes\" to argument of make."
.endif

post-extract:
	${TOUCH} ${WRKSRC}/adler32.c
	${TOUCH} ${WRKSRC}/deflate.c
	${TOUCH} ${WRKSRC}/trees.c
	${TOUCH} ${WRKSRC}/adler32.o
	${TOUCH} ${WRKSRC}/deflate.o
	${TOUCH} ${WRKSRC}/trees.o
	ln -s ${WRKDIRPREFIX}${PORTSDIR}/graphics/jpeg/work/jpeg-6* ${WRKSRC}/jpeg-6a
	ln -s ${WRKDIRPREFIX}${PORTSDIR}/graphics/png/work/libpng-1.* ${WRKSRC}/libpng
	cd ${WRKSRC} && unzip -La ${DISTDIR}/${HP850_DRV}
	cd ${WRKSRC} && tar -xzf ${DISTDIR}/${CID_CMAP_KO}

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
.if defined(BATCH)
	@${SETENV} PORTSDIR=${PORTSDIR} WRKSRC=${WRKSRC} \
		${SH} ${SCRIPTDIR}/configure.batch
.else
	@${SETENV} PORTSDIR=${PORTSDIR} WRKSRC=${WRKSRC} \
		${SH} ${SCRIPTDIR}/configure
.endif

pre-install:
	@${MKDIR} ${PREFIX}/share/ghostscript ${PREFIX}/bin ${PREFIX}/man/man1
	(cd ${PREFIX}/share/ghostscript ; \
			tar -xzf ${DISTDIR}/${GS_FONTS_STD})
	(cd ${PREFIX}/share/ghostscript/fonts ; \
			tar -xzf ${DISTDIR}/${GS_FONTS_OTHER})
	${CAT} ${FILESDIR}/Fontmap.addition >> ${WRKSRC}/Fontmap
	${INSTALL_DATA} ${FILESDIR}/Munhwa-Regular-KSC-EUC-H.gsf \
		${FILESDIR}/MunhwaGothic-Regular-KSC-EUC-H.gsf \
		${PREFIX}/share/ghostscript/fonts
	for file in ${CID_FONTS_KO}; do \
		${INSTALL_DATA} ${DISTDIR}/$$file \
			${PREFIX}/share/ghostscript/fonts; \
	done
	${MKDIR} ${PREFIX}/share/ghostscript/fonts/CMap; &&\
		${INSTALL_DATA} ${WRKSRC}/ak11/CMap/* \
			${PREFIX}/share/ghostscript/fonts/CMap

post-install:
	strip ${PREFIX}/bin/gs
	${INSTALL_DATA} ${DISTDIR}/${DECRYPT_PDF} \
		${PREFIX}/share/ghostscript/5.10ft
	${INSTALL_DATA} ${WRKSRC}/gs5-hfftype-0.2/README \
		${PREFIX}/share/ghostscript/5.10ft/doc/README.ko
.if defined(PDFENCRYPT)
	${CP} -f ${DISTDIR}/pdf_sec.ps ${PREFIX}/share/ghostscript/5.10ft
.endif

# encrypted PDF support.  can't be packaged due to export control issues.
# if you are outside in US, you can use this.
.if defined(PDFENCRYPT)
MASTER_SITES+=  http://www.ozemail.com.au/~geoffk/pdfencrypt/
DISTFILES+=     pdf_sec.ps
RESTRICTED=     "Crypto; export controlled, RC4 in PostScript code included"
.endif

.include <bsd.port.mk>
