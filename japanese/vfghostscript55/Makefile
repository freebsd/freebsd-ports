# New ports collection makefile for: Japanese Aladdin ghostscript + vector font library(FreeType)
# Version required:	5.10
# Date created:		26 Aug 1997
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.24 1998/10/16 05:27:15 jseger Exp $
#

DISTNAME=	ghostscript-5.10
PKGNAME=	ja-vfghostscript-5.10
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/aladdin/gs510/ \
		ftp://ftp.cs.wisc.edu/ghost/aladdin/fonts/ \
		ftp://ftp.uu.net/graphics/png/src/ \
		ftp://ftp.uu.net/graphics/jpeg/ \
		ftp://i1nws2.fukui-u.ac.jp/pub/TeX/dvipr/ \
		ftp://ftp.mei.co.jp/free/gnu/util/ghostscript/drivers/ \
		${MASTER_SITE_LOCAL} \
		http://www.jp.FreeBSD.org/~mita/LOCAL_PORTS/ \
		http://www.ldl.jaist.ac.jp/~akr/nonresearch/free-software/ghostscript/ \
		http://www.jaist.ac.jp/~daisuke/Linux/gs/gs5/Original-sources/OLD/ \
		http://www.rd.nacsis.ac.jp/~katayama/homepage/ghostscript/jpdf/ \
		http://itohws03.ee.noda.sut.ac.jp/~matsuda/VFlib-FT/ \
		http://www.bpe.es.osaka-u.ac.jp/~watanabe/ \
		ftp://ftp.iijnet.or.jp/humbleSoft/pub/
DISTFILES=	${GS_SOURCES} ${GS_DRIVERS} ${GS_FONTS_STD} ${GS_FONTS_OTHER}

MAINTAINER=	mita@jp.FreeBSD.org

LIB_DEPENDS=	VFlib2.23:${PORTSDIR}/japanese/vflib

EXTRACT_ONLY=	ghostscript-5.10.tar.gz jpegsrc.v6a.tar.gz libpng-0.96.tgz
WRKSRC=		${WRKDIR}/gs5.10
MAKEFILE=	unix-gcc.mak
MAKE_FLAGS=	prefix=${PREFIX} zlibc_=-lz CFLAGS="${CFLAGS}" -f
MAN1=		gs.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1 pdf2dsc.1

CFLAGS+=	-DA4
GSINST_DIR=	${PREFIX}/share/ghostscript/5.10vflib
DOC_DIR=	${GSINST_DIR}/doc
PRINTER=	${WRKSRC}/jp-printers
GS_SOURCES=	ghostscript-5.10.tar.gz
GS_SOURCES+=	jpegsrc.v6a.tar.gz
GS_SOURCES+=	libpng-0.96.tgz
GS_DRIVERS=	gs5.10-vflib-1.2.tar.gz
GS_DRIVERS+=	gs5.10-jpdf-0.2.tar.gz
GS_DRIVERS+=	gs5.10-VFlibBM-PL2.diff.gz
GS_DRIVERS+=	gdevlips4-1.2.0.tar.gz
GS_DRIVERS+=	gdevmjc-0.7.tar.gz
GS_DRIVERS+=	gdevrpdl.tar.gz
GS_DRIVERS+=	gdev10v.tar.gz
GS_DRIVERS+=	dmprt-2.01.tar.gz
GS_DRIVERS+=	gdevnpdl-1.4.tar.gz
GS_DRIVERS+=	epag-3.01.tar.gz
#  Note: the following two are real files that have symlinks with
#  later version numbers pointing to them.  To avoid unnecessarily
#  downloading distfiles, do not change these when upgrading the port
#  unless the files really change.
GS_FONTS_STD=	ghostscript-fonts-std-5.10.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-5.10.tar.gz

pre-fetch:
.if !defined(PDFENCRYPT)
	@${ECHO_MSG} "NOTE: You can have encrypted PDF support by adding "
	@${ECHO_MSG} "\"PDFENCRYPT=yes\" to argument of make."
.endif

pre-patch:
	@(cd ${WRKSRC} ; tar xzf ${DISTDIR}/gs5.10-vflib-1.2.tar.gz )
	@(cd ${WRKSRC} ; tar xzf ${DISTDIR}/gs5.10-jpdf-0.2.tar.gz )
	@(cd ${WRKDIR} ; \
	  ${PATCH} -p < ${WRKSRC}/gs5.10-vflib-1.2/gs5.10-vflib-1.2.diff \
		>/dev/null 2>&1)
	@(cd ${WRKDIR} ; \
	  ${PATCH} -p < ${WRKSRC}/gs5.10-jpdf-0.2/gs5.10-jpdf-0.2.diff \
		>/dev/null 2>&1)
	@(cd ${WRKDIR} ;  zcat ${DISTDIR}/gs5.10-VFlibBM-PL2.diff.gz | \
		${PATCH} -p >/dev/null 2>&1)

post-patch:
	@( ${MKDIR} ${PRINTER} ; \
	  cd ${PRINTER} ; \
	  tar xzf ${DISTDIR}/gdevlips4-1.2.0.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevmjc-0.7.tar.gz ; \
	  tar xzf ${DISTDIR}/gdevrpdl.tar.gz ; \
	  tar xzf ${DISTDIR}/gdev10v.tar.gz ; \
	  ${MKDIR} ${PRINTER}/gdevdmpr ; \
	  tar -C gdevdmpr -xzf ${DISTDIR}/dmprt-2.01.tar.gz ; \
	  ${MKDIR} ${PRINTER}/gdevnpdl ; \
	  tar -C gdevnpdl -xzf ${DISTDIR}/gdevnpdl-1.4.tar.gz ; \
	  tar xzf ${DISTDIR}/epag-3.01.tar.gz ; \
	  ${CP} gdev10v/gdev10v.c gdev10v/gdev10v.mak ${WRKSRC}; \
	  ${CP} gdevmjc-0.7/gdevmjc.c gdevmjc-0.7/mjc.dev ${WRKSRC}; \
	  ${CP} gdevlips4-1.2.0/gdevlips4.c gdevlips4-1.2.0/gdevlips4.mak ${WRKSRC}; \
	  ${CP} gdevdmpr/gdevdmpr.c gdevdmpr/gdevdmpr.mak ${WRKSRC}; \
	  ${CP} gdevdmpr/dviprlib.c gdevdmpr/dviprlib.h   ${WRKSRC}; \
	  ${CP} epag-3.01/gdevepag.c epag-3.01/gdevepag.mak ${WRKSRC}; \
	  ${CP} gdevrpdl/gdevrpdl.c gdevrpdl/gdevrpdl.mak ${WRKSRC}; \
	  ${CP} gdevnpdl/gdevnpdl.c gdevnpdl/gdevnpdl.mak ${WRKSRC}; \
	  )
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdev10v.mak.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/mjc.dev.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevmjc.c.patch
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/gdevdmpr.patch
	@${CAT} ${WRKSRC}/gdev10v.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevdmpr.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevepag.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevlips4.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevrpdl.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/gdevnpdl.mak >> ${WRKSRC}/unix-gcc.mak
	@${CAT} ${WRKSRC}/mjc.dev >> ${WRKSRC}/unix-gcc.mak

post-build:
	@(cd ${PRINTER}/epag-3.01 ;  ${MAKE})

pre-install:
	@${MKDIR} ${PREFIX}/share/ghostscript
	@tar -C ${PREFIX}/share/ghostscript -xzf ${DISTDIR}/${GS_FONTS_STD}
	@tar -C ${PREFIX}/share/ghostscript/fonts -xzf ${DISTDIR}/${GS_FONTS_OTHER}

post-install:
	${INSTALL_PROGRAM} ${PRINTER}/epag-3.01/ert ${PREFIX}/bin
	@strip ${PREFIX}/bin/gs
	@( \
	  ${CP} ${WRKSRC}/gs5.10-vflib-1.2/README ${DOC_DIR}/README.gs5.10-vflib ; \
	  ${CP} ${WRKSRC}/gs5.10-vflib-1.2/README.CID ${DOC_DIR}/README.CID.gs5.10-vflib ; \
	  ${CP} ${WRKSRC}/gs5.10-vflib-1.2/OLD-DOC/gs261d13-doc/* ${DOC_DIR} ; \
	  ${CP} ${WRKSRC}/gs5.10-vflib-1.2/OLD-DOC/gs261j10-doc/* ${DOC_DIR} ; \
	  ${CP} ${WRKSRC}/gs5.10-jpdf-0.2/README ${DOC_DIR}/README.gs5.10-jpdf ; \
	  ${CP} ${PRINTER}/gdev10v/gdev10v.jis ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevlips4-1.2.0/Readme ${DOC_DIR}/gdevlips4.euc ; \
	  ${CP} ${PRINTER}/gdevmjc-0.7/README.jis ${DOC_DIR}/gdevmjc.jis ; \
	  ${CP} ${PRINTER}/gdevmjc-0.7/MJ700V2C.FAQ ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/gdevdmpr.sj ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevnpdl/gdevnpdl.jis ${DOC_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/dmp_init.ps ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/dmp_site.ps ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/escp_24.src ${GSINST_DIR} ; \
	  ${CP} ${PRINTER}/gdevdmpr/testpage.ps ${GSINST_DIR} ; \
	  ${MKDIR} ${DOC_DIR}/epag-3.01 ; \
	  ${CP} ${PRINTER}/epag-3.01/FILES ${DOC_DIR}/epag-3.01 ; \
	  ${CP} ${PRINTER}/epag-3.01/*.txt ${DOC_DIR}/epag-3.01 ; \
	  ${CP} ${PRINTER}/epag-3.01/adjust.ps ${DOC_DIR}/epag-3.01 ; \
	  ${CP} ${PRINTER}/epag-3.01/gsepagif.sh ${DOC_DIR}/epag-3.01 ; \
	  ${CP} ${PRINTER}/epag-3.01/psprint ${DOC_DIR}/epag-3.01 ; \
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
