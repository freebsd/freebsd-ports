# New ports collection makefile for:	urt
# Version required:	3.1b
# Date created:		Jan 5 1997
# Whom:			cfs@ing.puc.cl (original)
#
# $Id: Makefile,v 1.11 1998/11/25 09:01:20 asami Exp $
#

DISTNAME=	urt
PKGNAME=	urt-3.1b1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.utah.edu/pub/
DISTFILES=	urt-3.1b.tar.Z urt-doc.tar urt-img.tar

PATCH_SITES=	ftp://ptolemy.berkeley.edu/pub/misc/urt/
PATCHFILES=	urt-3.1b-3.1b1.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	giffunip@asme.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff34
BUILD_DEPENDS=	${X11BASE}/lib/libpbm.a:${PORTSDIR}/graphics/netpbm

EXTRACT_ONLY=	urt-3.1b.tar.Z

USE_XLIB=	yes
NO_WRKSUBDIR=   yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	config/urt
HAS_CONFIGURE=	yes
MAKEFILE=	makefile
ALL_TARGET=

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
#Note:	Don't compress man5, it won't work !

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/urt ${PREFIX}/share/examples/urt
	cd ${PREFIX}/share/doc/urt; \
	${EXTRACT_CMD} xf $(DISTDIR)/urt-doc.tar; \
	cd doc; \
	find -d . | cpio -dump ..; \
	cd ..; \
	${RM} -rf doc; \
	cd ${PREFIX}/share/examples/urt; \
	${EXTRACT_CMD} xf $(DISTDIR)/urt-img.tar; \
	chown -R root:wheel . ; \
	find . -type d -exec chmod 775 '{}' \; ; \
	find . -type f -exec chmod 664 '{}' \;
.endif

.include <bsd.port.mk>
