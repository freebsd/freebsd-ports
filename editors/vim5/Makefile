# ex:ts=8
# New ports collection makefile for:    vim
# Version required:     5.x
# Date created:         Sat June 29, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.37 1999/04/22 00:16:55 scrappy Exp $
#

DISTNAME=	vim-5.3
CATEGORIES=	editors
MASTER_SITES=	ftp://nuxi.ucdavis.edu/pub/vim/unix/ \
		ftp://ftp.nuxi.com/pub/vim/unix/ \
		ftp://ftp.oce.nl/pub/misc/vim/unix/  \
		ftp://ftp.prz.tu-berlin.de/pub/unix/editors/vim/unix/  \
		ftp://ftp.is.co.za/applications/editors/vim/  \
		ftp://ftp.progsoc.uts.edu.au/pub/vim/
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX} ${DISTNAME}-rt${EXTRACT_SUFX}

MAINTAINER=     obrien@FreeBSD.org

Y2K=		http://www.vim.org/y2k.html

.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80
LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80
USE_PERL5=	yes
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/src
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_DIST_STRIP}
MAKE_FLAGS=	CONF_ARGS="--prefix=${PREFIX} --enable-max-features --with-tlib=termlib" -f
ALL_TARGET=	#
MAN1=		vim.1 xxd.1 ectags.1
MLINKS=		vim.1 gvim.1   vim.1 gview.1  \
		vim.1 rgvim.1  vim.1 rgview.1  vim.1 rvim.1  vim.1 rview.1


.if defined(HAVE_MOTIF)
REQUIRES_MOTIF=	yes
MAKE_FLAGS:=	CONF_OPT_GUI="--enable-gui=motif --with-motif-lib=\"${MOTIFLIB}\"" MOTIFHOME=${X11BASE} ${MAKE_FLAGS}
.else
MAKE_FLAGS:=	CONF_OPT_GUI="--enable-gui=athena" ${MAKE_FLAGS}
.endif

.if defined(PACKAGE_BUILDING)
MAKE_FLAGS:=	CONF_OPT_PERL="--enable-perlinterp --enable-tclinterp" ${MAKE_FLAGS}
.endif

pre-build:
	@(cd ${WRKSRC}; ${MAKE} distclean)

post-install:
	[ -e ${PREFIX}/bin/gvim ] || ${LN} -s ${PREFIX}/bin/vim ${PREFIX}/bin/gvim
	@${RM} -f ${PREFIX}/man/man1/etags.1
	@${MV} ${PREFIX}/man/man1/ctags.1 ${PREFIX}/man/man1/ectags.1
	@${LN} -sf ${PREFIX}/man/man1/ectags.1.gz ${PREFIX}/man/man1/etags.1.gz

.include <bsd.port.mk>
