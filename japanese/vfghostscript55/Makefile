# New ports collection makefile for: Japanese GNU ghostscript + vector font library(FreeType)
# Date created:		26 Aug 1997
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vfghostscript
PORTVERSION=	5.50a
PORTREVISION=	4
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/gnu/gs550/ \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/gnu/fonts/ \
		http://www.ozemail.com.au/~geoffk/pdfencrypt/ \
		${MASTER_SITE_LOCAL} \
		${MASTER_SITE_PORTS_JP} \
		http://www.ceres.dti.ne.jp/~owatanab/gdevnpdl/ \
		http://www.humblesoft.com/pub/ \
		http://plaza26.mbn.or.jp/~higamasa/gdevmd2k/ \
		http://www.epkowa.on.arena.ne.jp/pips/data/9400/\
		${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/hpinkjet/g}
# first for ${MASTER_SITE_GNU}, second for ${MASTER_SITE_LOCAL},
# third for ${MASTER_SITE_PORTS_JP}
MASTER_SITE_SUBDIR=	ghostscript asami/LOCAL_PORTS taoka .
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${DECRYPT_PDF} ${GS_DRIVERS}
DIST_SUBDIR=	ghostscript
EXTRACT_ONLY=	${GS_SOURCES}

MAINTAINER=	mita@jp.FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/graphics/jpeg:extract
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		VFlib2.24:${PORTSDIR}/japanese/vflib

WRKSRC=		${WRKDIR}/gs5.50

USE_XLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	CC="${CC}" CXX="${CXX}" XCFLAGS="${XCFLAGS}"
MAKEFILE=	unix-gcc.mak
MAN1=		gs.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1 pdf2dsc.1 ps2ps.1

XCFLAGS=	-DA4
GSINST_DIR=	${PREFIX}/share/ghostscript/5.50vflib
DOC_DIR=	${GSINST_DIR}/doc
PRINTER=	${WRKSRC}/jp-printers

GS_SOURCES=	gnu-gs-5.50a.tar.gz
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	gnu-gs-fonts-std-6.0.tar.gz
GS_FONTS_OTHER=	gnu-gs-fonts-other-6.0.tar.gz

GS_DRIVERS=	gs5.50-vflib-1.0.tar.gz
GS_DRIVERS+=	gdevlips-2.3.6-550.tar.gz
GS_DRIVERS+=	gdevmjc-0.8.tar.gz
GS_DRIVERS+=	gdev10v.tar.gz
GS_DRIVERS+=	dmprt-2.01.tar.gz
GS_DRIVERS+=	gdevnpdl-1.6.3.tar.gz
GS_DRIVERS+=	epag-3.09.tar.gz
GS_DRIVERS+=	gdevalps-0.21.tar.gz
GS_DRIVERS+=	gdevmd2k-0.2a.tar.gz
GS_DRIVERS+=	gdevrpdl-1.4.tar.gz
GS_DRIVERS+=	eplaser-2.0.6-550.tgz
GS_DRIVERS+=	hpijs-1.0.1.tar.gz

# replacement for pdf_sec.ps, that allows you to read encrypted PDF files
DECRYPT_PDF=	pdf_sec.ps

post-extract:
	${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../../graphics/jpeg/work/jpeg-6b ${WRKSRC}/jpeg
	@${TAR} -C ${WRKSRC} --unlink -xzf ${_DISTDIR}/gs5.50-vflib-1.0.tar.gz
	@( ${MKDIR} ${PRINTER} ; \
	  cd ${PRINTER} ; \
	  ${TAR} --unlink -xzf ${_DISTDIR}/gdevlips-2.3.6-550.tar.gz ; \
	  ${TAR} --unlink -xzf ${_DISTDIR}/gdevmjc-0.8.tar.gz ; \
	  ${TAR} --unlink -xzf ${_DISTDIR}/gdev10v.tar.gz ; \
	  ${MKDIR} ${PRINTER}/gdevdmpr ; \
	  ${TAR} -C gdevdmpr --unlink -xzf ${_DISTDIR}/dmprt-2.01.tar.gz ; \
	  ${TAR} --unlink -xzf ${_DISTDIR}/gdevnpdl-1.6.3.tar.gz ; \
	  ${TAR} --unlink -xzf ${_DISTDIR}/epag-3.09.tar.gz ; \
	  ${TAR} --unlink -xzf ${_DISTDIR}/gdevalps-0.21.tar.gz ; \
	  ${TAR} --unlink -xzf ${_DISTDIR}/gdevmd2k-0.2a.tar.gz ; \
	  ${TAR} --unlink -xzf ${_DISTDIR}/gdevrpdl-1.4.tar.gz ; \
	  ${TAR} --unlink -xzf ${_DISTDIR}/eplaser-2.0.6-550.tgz ; \
	  ${TAR} --unlink -xzf ${_DISTDIR}/hpijs-1.0.1.tar.gz ; \
	)

pre-patch:
	@${CAT} ${WRKSRC}/gs5.50-vflib-1.0/gs5.50-vflib-1.0.diff | \
		${PATCH} -d ${WRKSRC} -p1 --forward --quiet -E
	@${PERL} -pi -e 's|CFLAGS="-O2 -Wall"|CFLAGS=\$$CFLAGS"| ; \
	   s|CXXFLAGS="-O2 -Wall"|CXXFLAGS="\$$CXXFLAGS"|g ; \
	    ${WRKSRC}/hpijs-1.0.1/configure
	@find ${PRINTER}/hpijs-1.0.1 -name '*.h' | xargs ${PERL} -pi -e \
	  's|#include <malloc.h>||g'

post-patch:
	@( cd ${PRINTER} ; \
	  ${CP} gdev10v/gdev10v.c gdev10v/gdev10v.mak ${WRKSRC}; \
	  ${CP} gdevmjc-0.8/*.[ch] gdevmjc-0.8/gdevmjc.mak ${WRKSRC}; \
	  ${CP} gdevlips-2.3.6-550/gdevlips.[ch] gdevlips-2.3.6-550/gdevlips.mak ${WRKSRC}; \
	  ${CP} gdevlips-2.3.6-550/gdevl4[rv].c gdevlips-2.3.6-550/gdevlprn.[ch] ${WRKSRC}; \
	  ${CP} gdevdmpr/gdevdmpr.c gdevdmpr/gdevdmpr.mak ${WRKSRC}; \
	  ${CP} gdevdmpr/dviprlib.c gdevdmpr/dviprlib.h   ${WRKSRC}; \
	  ${CP} epag-3.09/gdevepag.c epag-3.09/gdevepag.mak ${WRKSRC}; \
	  ${CP} gdevnpdl-1.6.3/gdevnpdl.c gdevnpdl-1.6.3/gdevnpdl.mak ${WRKSRC}; \
	  ${CP} gdevalps-0.2/gdevalps.c gdevalps-0.2/gdevalps.mak-5.50 ${WRKSRC}; \
	  ${CP} gdevmd2k-0.2a/gdevmd2k.c gdevmd2k-0.2a/gdevmd2k.mak-5.50 ${WRKSRC}; \
	  ${CP} gdevrpdl-1.4/gdevrpdl.c gdevrpdl-1.4/gdevrpdl.mak ${WRKSRC}; \
	  ${CP} eplaser/gdevescv.[ch] eplaser/gdevescv.mak ${WRKSRC}; \
	  ${CP} eplaser/gdevesmv.c eplaser/gdevesmv.mak ${WRKSRC}; \
	  ${CP} hpijs-1.0.1/gdevijs.[ch] hpijs-1.0.1/ijs.[ch] ${WRKSRC}; \
	  ${CP} hpijs-1.0.1/ijs_client.[ch] hpijs-1.0.1/ijs_exec_unix.c ${WRKSRC}; \
	  ${CP}	hpijs-1.0.1/unistd_.h ${WRKSRC}; \
	  ${SED} -n -e '/^### -* IJS Interface -*/,/^###/p' \
	    hpijs-1.0.1/contrib.mak | ${SED} '$d' > ${WRKSRC}/gdevijs.mak; \
	  )
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdev10v.mak.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/mjc.dev.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevdmpr.mak.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevepag.mak.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevmjc.c.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevdmpr.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevlips.mak.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevescv.c.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevesmv.c.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevijs.mak.patch
	@${CAT} ${WRKSRC}/gdev10v.mak >> ${WRKSRC}/contrib.mak
	@${CAT} ${WRKSRC}/gdevdmpr.mak >> ${WRKSRC}/contrib.mak
	@${CAT} ${WRKSRC}/gdevepag.mak >> ${WRKSRC}/contrib.mak
	@${CAT} ${WRKSRC}/gdevlips.mak >> ${WRKSRC}/contrib.mak
	@${CAT} ${WRKSRC}/gdevnpdl.mak >> ${WRKSRC}/contrib.mak
	@${CAT} ${WRKSRC}/gdevrpdl.mak >> ${WRKSRC}/contrib.mak
	@${CAT} ${WRKSRC}/gdevmjc.mak >> ${WRKSRC}/contrib.mak
	@${CAT} ${WRKSRC}/gdevalps.mak-5.50 >> ${WRKSRC}/contrib.mak
	@${CAT} ${WRKSRC}/gdevmd2k.mak-5.50 >> ${WRKSRC}/contrib.mak
	@${CAT} ${WRKSRC}/gdevescv.mak >> ${WRKSRC}/contrib.mak
	@${CAT} ${WRKSRC}/gdevesmv.mak >> ${WRKSRC}/contrib.mak
	@${CAT} ${WRKSRC}/gdevijs.mak >> ${WRKSRC}/contrib.mak

post-configure:
	@(cd ${PRINTER}/hpijs-1.0.1 ; \
	  ${SETENV} ${MAKE_ENV} ${SH} ./configure --prefix=${PREFIX})

pre-build:
	${MKDIR} ${WRKSRC}/obj

post-build:
	@(cd ${PRINTER}/epag-3.09 ; \
	  ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile)
	@(cd ${PRINTER}/hpijs-1.0.1 ; \
	  ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile)

pre-install:
	@${MKDIR} ${PREFIX}/share/ghostscript
	@${TAR} -C ${PREFIX}/share/ghostscript -xzf ${_DISTDIR}/${GS_FONTS_STD}
	@${TAR} -C ${PREFIX}/share/ghostscript -xzf ${_DISTDIR}/${GS_FONTS_OTHER}

post-install:
	${INSTALL_DATA} ${_DISTDIR}/pdf_sec.ps ${GSINST_DIR}
	${INSTALL_PROGRAM} ${PRINTER}/epag-3.09/ert ${PREFIX}/bin
	${INSTALL_PROGRAM} ${PRINTER}/hpijs-1.0.1/hpijs ${PREFIX}/bin
	@strip ${PREFIX}/bin/gs
	@( \
	  ${CP} ${WRKSRC}/gs5.50-vflib-1.0/README ${DOC_DIR}/README.gs5.10-vflib ; \
	  ${CP} ${WRKSRC}/gs5.50-vflib-1.0/OLD-DOC/gs261d13-doc/*.sj ${DOC_DIR} ; \
	  ${CP} ${WRKSRC}/gs5.50-vflib-1.0/OLD-DOC/gs261j11-doc/* ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdev10v/gdev10v.jis ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevlips-2.3.6-550/Gdevlips.htm ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevlips-2.3.6-550/gs_statd.dif ${DOC_DIR} ; \
	  ${MKDIR} ${DOC_DIR}/gdevmjc-0.8 ; \
	  ${CP} ${PRINTER}/gdevmjc-0.8/README.mjc ${DOC_DIR}/gdevmjc-0.8/ ; \
	  ${CP} ${PRINTER}/gdevmjc-0.8/README.noz ${DOC_DIR}/gdevmjc-0.8/ ; \
	  ${CP} ${PRINTER}/gdevmjc-0.8/README.mje ${DOC_DIR}/gdevmjc-0.8/ ; \
	  ${CP} ${PRINTER}/gdevmjc-0.8/cpem.doc ${DOC_DIR}/gdevmjc-0.8/ ; \
	  ${CP} ${PRINTER}/gdevmjc-0.8/MJ700V2C.FAQ ${DOC_DIR}/gdevmjc-0.8/ ; \
	  ${CP} ${PRINTER}/gdevalps-0.2/README.gdevalps ${DOC_DIR}/README.gdevalps ; \
	  ${CP} ${PRINTER}/gdevmd2k-0.2a/README.jis ${DOC_DIR}/gdevmd2k.jis ; \
	  ${CP} ${PRINTER}/gdevrpdl-1.4/gdevrpdl.doc ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/gdevdmpr.sj ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/dmp_init.ps ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/dmp_site.ps ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/escp_24.src ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/testpage.ps ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevnpdl-1.6.3/gdevnpdl.jis ${DOC_DIR} ; \
	  ${MKDIR} ${DOC_DIR}/epag-3.09 ; \
	  ${CP} ${PRINTER}/epag-3.09/FILES ${DOC_DIR}/epag-3.09 ; \
	  ${CP} ${PRINTER}/epag-3.09/*.txt ${DOC_DIR}/epag-3.09 ; \
	  ${CP} ${PRINTER}/epag-3.09/adjust.ps ${DOC_DIR}/epag-3.09 ; \
	  ${CP} ${PRINTER}/epag-3.09/gsepagif.sh ${DOC_DIR}/epag-3.09 ; \
	  ${CP} ${PRINTER}/epag-3.09/psprint ${DOC_DIR}/epag-3.09 ; \
	  ${CP} ${PRINTER}/gdevmjc-0.8/gdevmjc.ps ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/eplaser/readme-eplaser.euc ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/hpijs-1.0.1/hpijs_readme.html ${DOC_DIR} ; \
	)

.include <bsd.port.mk>
