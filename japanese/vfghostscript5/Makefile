# New ports collection makefile for: Japanese GNU ghostscript + vector font library(FreeType)
# Date created:		26 Aug 1997
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vfghostscript
PORTVERSION=	5.10
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.cs.wisc.edu/ghost/gnu/gs510/ \
		ftp://ftp.cs.wisc.edu/ghost/aladdin/fonts/ \
		http://www.ozemail.com.au/~geoffk/pdfencrypt/ \
		${MASTER_SITE_LOCAL} \
		${MASTER_SITE_PORTS_JP} \
		http://www.bukka.p.chiba-u.ac.jp/~ohmori/gs/ \
		http://www.rd.nacsis.ac.jp/~katayama/homepage/ghostscript/jpdf/ \
		http://itohws03.ee.noda.sut.ac.jp/~matsuda/VFlib-FT/ \
		http://www6.vc-net.ne.jp/~umi/ \
		http://plaza26.mbn.or.jp/~higamasa/gdevmd2k/ \
		http://www.ceres.dti.ne.jp/~owatanab/gdevnpdl/ \
		http://www.humblesoft.com/pub/
# first for ${MASTER_SITE_GNU}, second for ${MASTER_SITE_LOCAL},
# third for ${MASTER_SITE_PORTS_JP}
MASTER_SITE_SUBDIR=	ghostscript asami/LOCAL_PORTS taoka .
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${DECRYPT_PDF} ${GS_DRIVERS}
EXTRACT_ONLY=	${GS_SOURCES}

MAINTAINER=	mita@jp.FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/graphics/jpeg:extract
LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png \
		VFlib2.24:${PORTSDIR}/japanese/vflib

WRKSRC=		${WRKDIR}/gs${PORTVERSION}
MAKEFILE=	unix-gcc.mak
MAN1=		gs.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1 pdf2dsc.1

CFLAGS+=	-DA4
GSINST_DIR=	${PREFIX}/share/ghostscript/${PORTVERSION}vflib
DOC_DIR=	${GSINST_DIR}/doc
PRINTER=	${WRKSRC}/jp-printers

GS_SOURCES=	ghostscript-${PORTVERSION}.tar.gz
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	ghostscript-fonts-std-5.50.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-${PORTVERSION}.tar.gz

GS_DRIVERS=	gs${PORTVERSION}-vflib-1.2.tar.gz
GS_DRIVERS+=	gs${PORTVERSION}-jpdf-0.2.tar.gz
GS_DRIVERS+=	gs${PORTVERSION}-VFlibBM-PL2.diff.gz
GS_DRIVERS+=	gdevlips-2.3.2-510.tar.gz
GS_DRIVERS+=	gdevmjc-0.8.tar.gz
GS_DRIVERS+=	gdev10v.tar.gz
GS_DRIVERS+=	dmprt-2.01.tar.gz
GS_DRIVERS+=	gdevalps-0.21.tar.gz
GS_DRIVERS+=	gdevmd2k-0.2a.tar.gz
GS_DRIVERS+=	gdevrpdl-1.4-510.tar.gz
GS_DRIVERS+=	gdevnpdl-1.6.2.tar.gz
GS_DRIVERS+=	epag-3.09.tar.gz

# replacement for pdf_sec.ps, that allows you to read encrypted PDF files
DECRYPT_PDF=	pdf_sec.ps

post-extract:
	${LN} -s ${WRKDIRPREFIX}${.CURDIR}/../../graphics/jpeg/work/jpeg-6b ${WRKSRC}/jpeg
	@${TAR} -C ${WRKSRC} --unlink -xzf ${DISTDIR}/gs${PORTVERSION}-vflib-1.2.tar.gz
	@${TAR} -C ${WRKSRC} --unlink -xzf ${DISTDIR}/gs${PORTVERSION}-jpdf-0.2.tar.gz
	@( ${MKDIR} ${PRINTER} ; \
	  cd ${PRINTER} ; \
	  ${TAR} --unlink -xzf ${DISTDIR}/gdevlips-2.3.2-510.tar.gz ; \
	  ${TAR} --unlink -xzf ${DISTDIR}/epag-3.09.tar.gz ; \
	  ${TAR} --unlink -xzf ${DISTDIR}/gdevmjc-0.8.tar.gz ; \
	  ${TAR} --unlink -xzf ${DISTDIR}/gdev10v.tar.gz ; \
	  ${MKDIR} ${PRINTER}/gdevdmpr ; \
	  ${TAR} -C gdevdmpr --unlink -xzf ${DISTDIR}/dmprt-2.01.tar.gz ; \
	  ${TAR} --unlink -xzf ${DISTDIR}/gdevalps-0.21.tar.gz ; \
	  ${TAR} --unlink -xzf ${DISTDIR}/gdevmd2k-0.2a.tar.gz ; \
	  ${TAR} --unlink -xzf ${DISTDIR}/gdevrpdl-1.4-510.tar.gz ; \
	  ${TAR} --unlink -xzf ${DISTDIR}/gdevnpdl-1.6.2.tar.gz ; \
	  )

pre-patch:
	@${CAT} ${WRKSRC}/gs${PORTVERSION}-vflib-1.2/gs${PORTVERSION}-vflib-1.2.diff | \
		${PATCH} -d ${WRKDIR} -p --forward --quiet -E
	@${CAT} ${WRKSRC}/gs${PORTVERSION}-jpdf-0.2/gs${PORTVERSION}-jpdf-0.2.diff | \
		${PATCH} -d ${WRKDIR} -p --forward --quiet -E
	@${GZCAT} ${DISTDIR}/gs${PORTVERSION}-VFlibBM-PL2.diff.gz | \
		${PATCH} -d ${WRKDIR} -p --forward --quiet -E

post-patch:
	@( cd ${PRINTER} ; \
	  ${CP} gdev10v/gdev10v.c gdev10v/gdev10v.mak ${WRKSRC}; \
	  ${CP} gdevmjc-0.8/*.[ch] gdevmjc-0.8/gdevmjc.mak ${WRKSRC}; \
	  ${CP} gdevlips-2.3.2-510/gdevlips.c gdevlips-2.3.2-510/gdevlips.mak ${WRKSRC}; \
	  ${CP} gdevlips-2.3.2-510/gdevl4r.c gdevlips-2.3.2-510/gdevl4v.c gdevlips-2.3.2-510/gdevlips.h ${WRKSRC}; \
	  ${CP} gdevlips-2.3.2-510/gdevlprn.c gdevlips-2.3.2-510/gdevlprn.h ${WRKSRC}; \
	  ${CP} gdevdmpr/gdevdmpr.c gdevdmpr/gdevdmpr.mak ${WRKSRC}; \
	  ${CP} gdevdmpr/dviprlib.c gdevdmpr/dviprlib.h   ${WRKSRC}; \
	  ${CP} epag-3.09/gdevepag.c epag-3.09/gdevepag.mak ${WRKSRC}; \
	  ${CP} gdevalps-0.2/gdevalps.c gdevalps-0.2/gdevalps.mak ${WRKSRC}; \
	  ${CP} gdevmd2k-0.2a/gdevmd2k.c gdevmd2k-0.2a/gdevmd2k.mak ${WRKSRC}; \
	  ${CP} gdevrpdl-1.4-510/gdevrpdl.c gdevrpdl-1.4-510/gdevrpdl.mak ${WRKSRC}; \
	  ${PATCH} -d gdevnpdl --forward --quiet -E < ${PRINTER}/gdevnpdl/gdevnpdl.patch-gs${PORTVERSION} ; \
	  ${CP} gdevnpdl/gdevnpdl.c gdevnpdl/gdevnpdl.mak ${WRKSRC}; \
	  )
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdev10v.mak.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/mjc.dev.patch
#	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevmjc.mak.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevmjc.c.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevlips.mak.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevdmpr.patch
	@${CAT} ${WRKSRC}/gdev10v.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevdmpr.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevepag.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevlips.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevrpdl.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevmjc.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevalps.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevmd2k.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevnpdl.mak >> ${WRKSRC}/unix-gcc.mak

pre-install:
	@${MKDIR} ${PREFIX}/share/ghostscript
	@${TAR} -C ${PREFIX}/share/ghostscript -xzf ${DISTDIR}/${GS_FONTS_STD}
	@${TAR} -C ${PREFIX}/share/ghostscript/fonts -xzf ${DISTDIR}/${GS_FONTS_OTHER}

post-build:
	@(cd ${PRINTER}/epag-3.09 ;  ${MAKE})

post-install:
	${INSTALL_DATA} ${DISTDIR}/pdf_sec.ps ${GSINST_DIR}
	${INSTALL_PROGRAM} ${PRINTER}/epag-3.09/ert ${PREFIX}/bin
	@strip ${PREFIX}/bin/gs
	@( \
	  ${CP} ${WRKSRC}/gs${PORTVERSION}-vflib-1.2/README ${DOC_DIR}/README.gs${PORTVERSION}-vflib ; \
	  ${CP} ${WRKSRC}/gs${PORTVERSION}-vflib-1.2/README.CID ${DOC_DIR}/README.CID.gs${PORTVERSION}-vflib ; \
	  ${CP} ${WRKSRC}/gs${PORTVERSION}-vflib-1.2/OLD-DOC/gs261d13-doc/* ${DOC_DIR} ; \
	  ${CP} ${WRKSRC}/gs${PORTVERSION}-vflib-1.2/OLD-DOC/gs261j10-doc/* ${DOC_DIR} ; \
	  ${CP} ${WRKSRC}/gs${PORTVERSION}-jpdf-0.2/README ${DOC_DIR}/README.gs${PORTVERSION}-jpdf ; \
	  ${CP} ${PRINTER}/gdev10v/gdev10v.jis ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevlips-2.3.2-510/Gdevlips.htm ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevlips-2.3.2-510/gs_statd.dif ${DOC_DIR} ; \
	  ${MKDIR} ${DOC_DIR}/gdevmjc-0.8; \
	  ${CP} ${PRINTER}/gdevmjc-0.8/README.mjc ${DOC_DIR}/gdevmjc-0.8/ ; \
	  ${CP} ${PRINTER}/gdevmjc-0.8/README.noz ${DOC_DIR}/gdevmjc-0.8/ ; \
	  ${CP} ${PRINTER}/gdevmjc-0.8/README.mje ${DOC_DIR}/gdevmjc-0.8/ ; \
	  ${CP} ${PRINTER}/gdevmjc-0.8/cpem.doc ${DOC_DIR}/gdevmjc-0.8/ ; \
	  ${CP} ${PRINTER}/gdevmjc-0.8/MJ700V2C.FAQ ${DOC_DIR}/gdevmjc-0.8/ ; \
	  ${CP} ${PRINTER}/gdevmjc-0.8/gdevmjc.ps ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevalps-0.2/README.gdevalps ${DOC_DIR}/README.gdevalps ; \
	  ${CP} ${PRINTER}/gdevmd2k-0.2a/README.jis ${DOC_DIR}/gdevmd2k.jis ; \
	  ${CP} ${PRINTER}/gdevrpdl-1.4-510/gdevrpdl.doc ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/gdevdmpr.sj ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevnpdl/gdevnpdl.jis ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/dmp_init.ps ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/dmp_site.ps ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/escp_24.src ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/testpage.ps ${GSINST_DIR} ; \
	  ${MKDIR} ${DOC_DIR}/epag-3.09 ; \
	  ${CP} ${PRINTER}/epag-3.09/FILES ${DOC_DIR}/epag-3.09 ; \
	  ${CP} ${PRINTER}/epag-3.09/*.txt ${DOC_DIR}/epag-3.09 ; \
	  ${CP} ${PRINTER}/epag-3.09/adjust.ps ${DOC_DIR}/epag-3.09 ; \
	  ${CP} ${PRINTER}/epag-3.09/gsepagif.sh ${DOC_DIR}/epag-3.09 ; \
	  ${CP} ${PRINTER}/epag-3.09/psprint ${DOC_DIR}/epag-3.09 ; \
	)

.include <bsd.port.mk>
