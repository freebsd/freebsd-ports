# New ports collection makefile for: Japanese Aladdin ghostscript + vector font library(FreeType)
# Date created:		26 Aug 1997
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vfghostscript
PORTVERSION=	5.10
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/gnu/gs510/ \
		ftp://ftp.cs.wisc.edu/ghost/aladdin/fonts/ \
		ftp://ftp.uu.net/graphics/png/src/ \
		ftp://ftp.uu.net/graphics/jpeg/ \
		ftp://ftp.mei.co.jp/free/gnu/util/ghostscript/drivers/ \
		${MASTER_SITE_LOCAL} \
		${MASTER_SITE_PORTS_JP} \
		http://www.bukka.p.chiba-u.ac.jp/~ohmori/gs/ \
		http://www.ldl.jaist.ac.jp/~akr/nonresearch/free-software/ghostscript/ \
		http://www.jaist.ac.jp/~daisuke/Linux/gs/gs5/Original-sources/OLD/ \
		http://www.rd.nacsis.ac.jp/~katayama/homepage/ghostscript/jpdf/ \
		http://itohws03.ee.noda.sut.ac.jp/~matsuda/VFlib-FT/ \
		http://www.necs.co.jp/~umi/ \
		http://plaza26.mbn.or.jp/~higamasa/gdevmd2k/ \
		http://www.aial.hiroshima-u.ac.jp/~sakai/Linux/gs${PORTVERSION}/ \
		http://www.ceres.dti.ne.jp/~owatanab/gdevnpdl/ \
		ftp://ftp.humblesoft.com/pub/
# former for ${MASTER_SITE_LOCAL}, latter for ${MASTER_SITE_PORTS_JP}
MASTER_SITE_SUBDIR=	asami/LOCAL_PORTS .
DISTFILES=	${GS_SOURCES} ${GS_DRIVERS} ${GS_FONTS_STD} ${GS_FONTS_OTHER}
DISTNAME=	ghostscript-${PORTVERSION}

MAINTAINER=	mita@jp.FreeBSD.org

LIB_DEPENDS=	VFlib2.24:${PORTSDIR}/japanese/vflib

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} jpegsrc.v6a.tar.gz libpng-0.96.tgz
WRKSRC=		${WRKDIR}/gs${PORTVERSION}
MAKEFILE=	unix-gcc.mak
MAKE_FLAGS=	prefix=${PREFIX} zlibc_=-lz CFLAGS="${CFLAGS}" -f
MAN1=		gs.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1 pdf2dsc.1

CFLAGS+=	-DA4
GSINST_DIR=	${PREFIX}/share/ghostscript/${PORTVERSION}vflib
DOC_DIR=	${GSINST_DIR}/doc
PRINTER=	${WRKSRC}/jp-printers
GS_SOURCES=	${DISTNAME}.tar.gz
GS_SOURCES+=	jpegsrc.v6a.tar.gz
GS_SOURCES+=	libpng-0.96.tgz
GS_DRIVERS=	gs${PORTVERSION}-vflib-1.2.tar.gz
GS_DRIVERS+=	gs${PORTVERSION}-jpdf-0.2.tar.gz
GS_DRIVERS+=	gs${PORTVERSION}-VFlibBM-PL2.diff.gz
GS_DRIVERS+=	gdevlips-2.3.2-510.tar.gz
GS_DRIVERS+=	gdevmjc-0.8.tar.gz
GS_DRIVERS+=	gdev10v.tar.gz
GS_DRIVERS+=	dmprt-2.01.tar.gz
GS_DRIVERS+=	gdevalps-0.2.tar.gz
GS_DRIVERS+=	gdevmd2k-0.2a.tar.gz
GS_DRIVERS+=	gdevrpdl-1.2-510.tar.gz
GS_DRIVERS+=	gdevnpdl-1.6.2.tar.gz
GS_DRIVERS+=	epag-3.08.tar.gz
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	ghostscript-fonts-std-5.50.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-${PORTVERSION}.tar.gz

pre-fetch:
.if !defined(PDFENCRYPT)
	@${ECHO_MSG} "NOTE: You can have encrypted PDF support by adding "
	@${ECHO_MSG} "\"PDFENCRYPT=yes\" to argument of make."
.endif

pre-patch:
	@(cd ${WRKSRC} ; tar xzf ${DISTDIR}/gs${PORTVERSION}-vflib-1.2.tar.gz )
	@(cd ${WRKSRC} ; tar xzf ${DISTDIR}/gs${PORTVERSION}-jpdf-0.2.tar.gz )
	@(cd ${WRKDIR} ; \
	  ${PATCH} -p < ${WRKSRC}/gs${PORTVERSION}-vflib-1.2/gs${PORTVERSION}-vflib-1.2.diff \
		>/dev/null 2>&1)
	@(cd ${WRKDIR} ; \
	  ${PATCH} -p < ${WRKSRC}/gs${PORTVERSION}-jpdf-0.2/gs${PORTVERSION}-jpdf-0.2.diff \
		>/dev/null 2>&1)
	@(cd ${WRKDIR} ;  zcat ${DISTDIR}/gs${PORTVERSION}-VFlibBM-PL2.diff.gz | \
		${PATCH} -p >/dev/null 2>&1)

post-patch:
	@( ${MKDIR} ${PRINTER} ; \
	  cd ${PRINTER} ; \
	  tar xzf ${DISTDIR}/gdevlips-2.3.2-510.tar.gz ; \
	  tar xzf ${DISTDIR}/epag-3.08.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevmjc-0.8.tar.gz ; \
	  tar xzf ${DISTDIR}/gdev10v.tar.gz ; \
	  ${MKDIR} ${PRINTER}/gdevdmpr ; \
	  tar -C gdevdmpr -xzf ${DISTDIR}/dmprt-2.01.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevalps-0.2.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevmd2k-0.2a.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevrpdl-1.2-510.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevnpdl-1.6.2.tar.gz ; \
	  ${CP} gdev10v/gdev10v.c gdev10v/gdev10v.mak ${WRKSRC}; \
	  ${CP} gdevmjc-0.8/*.[ch] gdevmjc-0.8/gdevmjc.mak ${WRKSRC}; \
	  ${CP} gdevlips-2.3.2-510/gdevlips.c gdevlips-2.3.2-510/gdevlips.mak ${WRKSRC}; \
	  ${CP} gdevlips-2.3.2-510/gdevl4r.c gdevlips-2.3.2-510/gdevl4v.c gdevlips-2.3.2-510/gdevlips.h ${WRKSRC}; \
	  ${CP} gdevlips-2.3.2-510/gdevlprn.c gdevlips-2.3.2-510/gdevlprn.h ${WRKSRC}; \
	  ${CP} gdevdmpr/gdevdmpr.c gdevdmpr/gdevdmpr.mak ${WRKSRC}; \
	  ${CP} gdevdmpr/dviprlib.c gdevdmpr/dviprlib.h   ${WRKSRC}; \
	  ${CP} epag-3.08/gdevepag.c epag-3.08/gdevepag.mak ${WRKSRC}; \
	  ${CP} gdevalps-0.2/gdevalps.c gdevalps-0.2/gdevalps.mak ${WRKSRC}; \
	  ${CP} gdevmd2k-0.2a/gdevmd2k.c gdevmd2k-0.2a/gdevmd2k.mak ${WRKSRC}; \
	  ${CP} gdevrpdl-1.2-510/gdevrpdl.c gdevrpdl-1.2-510/gdevrpdl.mak ${WRKSRC}; \
	  ${PATCH} -d gdevnpdl < ${PRINTER}/gdevnpdl/gdevnpdl.patch-gs${PORTVERSION} ; \
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
	@tar -C ${PREFIX}/share/ghostscript -xzf ${DISTDIR}/${GS_FONTS_STD}
	@tar -C ${PREFIX}/share/ghostscript/fonts -xzf ${DISTDIR}/${GS_FONTS_OTHER}

post-build:
	@(cd ${PRINTER}/epag-3.08 ;  ${MAKE})

post-install:
	${INSTALL_PROGRAM} ${PRINTER}/epag-3.08/ert ${PREFIX}/bin
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
	  ${CP} ${PRINTER}/gdevrpdl-1.2-510/gdevrpdl.doc ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/gdevdmpr.sj ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevnpdl/gdevnpdl.jis ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/dmp_init.ps ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/dmp_site.ps ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/escp_24.src ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/testpage.ps ${GSINST_DIR} ; \
	  ${MKDIR} ${DOC_DIR}/epag-3.08 ; \
	  ${CP} ${PRINTER}/epag-3.08/FILES ${DOC_DIR}/epag-3.08 ; \
	  ${CP} ${PRINTER}/epag-3.08/*.txt ${DOC_DIR}/epag-3.08 ; \
	  ${CP} ${PRINTER}/epag-3.08/adjust.ps ${DOC_DIR}/epag-3.08 ; \
	  ${CP} ${PRINTER}/epag-3.08/gsepagif.sh ${DOC_DIR}/epag-3.08 ; \
	  ${CP} ${PRINTER}/epag-3.08/psprint ${DOC_DIR}/epag-3.08 ; \
	)
.if defined(PDFENCRYPT)
	@${CP} -f ${DISTDIR}/pdf_sec.ps ${GSINST_DIR}
.endif

# encrypted PDF support.  can't be packaged due to export control issues.
.if defined(PDFENCRYPT)
MASTER_SITES+=	http://www.ozemail.com.au/~geoffk/pdfencrypt/
DISTFILES+=	pdf_sec.ps
RESTRICTED=	"Crypto; export controlled, RC4 in PostScript code included"
.endif

.include <bsd.port.mk>
