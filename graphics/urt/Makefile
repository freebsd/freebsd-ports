# New ports collection makefile for:	urt
# Date created:		Jan 5 1997
# Whom:			cfs@ing.puc.cl (original)
#
# $FreeBSD$
#

PORTNAME=	urt
PORTVERSION=	3.1b1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.iastate.edu/pub/utah-raster/
DISTNAME=	urt
DISTFILES=	urt-3.1b.tar.Z urt-doc.tar.Z urt-img.tar.Z

PATCH_SITES=	http://www.funet.fi/pub/graphics/packages/urt/rel2/
PATCHFILES=	urt-3.1b-3.1b1.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit and library for raster image processing

LIB_DEPENDS=	netpbm.1:${PORTSDIR}/graphics/netpbm

NO_WRKSUBDIR=	yes

USE_XLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	config/urt
MAKEFILE=	makefile
ALL_TARGET=	# none
INSTALLS_SHLIB=	yes

MAN1=	aliastorle.1 applymap.1 avg4.1 crop.1 cubitorle.1 dvirle.1	\
	fant.1 getx11.1 giftorle.1 graytorle.1 into.1 mcut.1 mergechan.1\
	painttorle.1 pgmtorle.1 ppmtorle.1 pyrmask.1 rawtorle.1		\
	repos.1 rlatorle.1 rleClock.1 rleaddcom.1 rleaddeof.1 rlebg.1	\
	rlebox.1 rlecat.1 rleccube.1 rlecomp.1 rledither.1 rleflip.1	\
	rlegrid.1 rlehdr.1 rlehisto.1 rleinterp.1 rleldmap.1 rlemandl.1	\
	rlenoise.1 rlepatch.1 rleprint.1 rlequant.1 rlescale.1 		\
	rleselect.1 rlesetbg.1 rlespiff.1 rlesplice.1 rlesplit.1	\
	rlestereo.1 rleswap.1 rletoabA60.1 rletoabA62.1	rletoalias.1	\
	rletoascii.1 rletogif.1 rletogray.1 rletopaint.1 rletoppm.1	\
	rletops.1 rletoraw.1 rletorla.1 rletotarga.1 rletotiff.1	\
	rlezoom.1 smush.1 targatorle.1 tifftorle.1 to8.1 tobw.1 unexp.1	\
	unslice.1 urt.1 wasatchrle.1
MAN3=	buildmap.3 bwdithermap.3 colorquant.3 dither.3 ditherbw.3	\
	dithergb.3 dithermap.3 float_to_exp.3 hilbert.3 hilbert_c2i.3	\
	hilbert_i2c.3 inv_cmap.3 librle.3 make_square.3 rgb_to_bw.3	\
	rle_addhist.3 rle_cp.3 rle_debug.3 rle_delcom.3 rle_freeraw.3	\
	rle_get_error.3 rle_get_set.3 rle_get_setup.3			\
	rle_get_setup_ok.3 rle_getcom.3 rle_getraw.3 rle_getrow.3	\
	rle_getskip.3 rle_hdr.3 rle_op.3 rle_open_f.3			\
	rle_open_f_noexit.3 rle_put_init.3 rle_put_setup.3 rle_putcom.3	\
	rle_puteof.3 rle_putraw.3 rle_putrow.3 rle_raw_alloc.3		\
	rle_raw_free.3 rle_rawtorow.3 rle_row_alloc.3 rle_row_free.3	\
	rle_skiprow.3
MAN5=	rle.5
MLINKS=	rle.5 RLE.5

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/doc && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKDIR} && ${FIND} img | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
