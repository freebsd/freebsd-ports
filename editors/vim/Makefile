# ex:ts=8
# New ports collection makefile for:    vim
# Version required:     5.x
# Date created:         Sat June 29, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.14 1997/12/08 19:03:51 obrien Exp $
#

DISTNAME=	vim-5.0t
CATEGORIES=	editors
MASTER_SITES=	ftp://nuxi.ucdavis.edu/pub/vim/beta-test/unix/ \
		ftp://ftp.nuxi.com/pub/vim/beta-test/unix/ \
		ftp://ftp.oce.nl/pub/misc/vim/beta-test/unix/  \
		ftp://ftp.prz.tu-berlin.de/pub/unix/editors/vim/beta-test/unix/  \
		ftp://ftp.is.co.za/applications/editors/beta-test/vim/  \
		ftp://ftp.progsoc.uts.edu.au/pub/beta-test/vim/

MAINTAINER=     obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_FLAGS=	CONF_ARGS=--prefix=${PREFIX} -f
ALL_TARGET=	#
MAN1=		vim.1 xxd.1 ctags.1

.if defined(HAVE_MOTIF)
REQUIRES_MOTIF=	yes
MAKE_FLAGS:=	CONF_OPT_GUI="--enable-gui=motif" MOTIFHOME=${X11BASE} ${MAKE_FLAGS}
.else
MAKE_FLAGS:=	CONF_OPT_GUI="--enable-gui=yes" ${MAKE_FLAGS}
.endif

pre-build:
	@(cd ${WRKSRC}; ${GMAKE} distclean)

post-install:
	[ -e ${PREFIX}/bin/gvim ] || /bin/ln -s ${PREFIX}/bin/vim ${PREFIX}/bin/gvim
	@${RM} -f ${PREFIX}/man/man1/etags.1
	@/bin/ln -sf ${PREFIX}/man/man1/ctags.1.gz ${PREFIX}/man/man1/etags.1.gz

.include <bsd.port.mk>
