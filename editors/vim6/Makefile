# ex:ts=8
# New ports collection makefile for:    vim
# Version required:     5.x
# Date created:         Sat June 29, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.29 1998/09/25 10:07:45 asami Exp $
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

.if defined(BATCH)
BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80 \
		python:${PORTSDIR}/lang/python
LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80
RUN_DEPENDS=	python:${PORTSDIR}/lang/python
USE_PERL5=	yes
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/src
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_DIST_STRIP}
MAKE_FLAGS=	CONF_ARGS="--prefix=${PREFIX} --enable-max-features" -f
ALL_TARGET=	#
MAN1=		vim.1 xxd.1 ectags.1


.if defined(HAVE_MOTIF)
REQUIRES_MOTIF=	yes
MAKE_FLAGS:=	CONF_OPT_GUI="--enable-gui=motif" MOTIFHOME=${X11BASE} ${MAKE_FLAGS}
.else
MAKE_FLAGS:=	CONF_OPT_GUI="--enable-gui=athena" ${MAKE_FLAGS}
.endif

.if defined(BATCH)
MAKE_FLAGS:=	CONF_OPT_PERL="--enable-perlinterp --enable-pythoninterp --enable-tclinterp" ${MAKE_FLAGS}
.endif

pre-build:
	@(cd ${WRKSRC}; ${MAKE} distclean)

post-install:
	[ -e ${PREFIX}/bin/gvim ] || ${LN} -s ${PREFIX}/bin/vim ${PREFIX}/bin/gvim
	@${RM} -f ${PREFIX}/man/man1/etags.1
	@${MV} ${PREFIX}/man/man1/ctags.1 ${PREFIX}/man/man1/ectags.1
	@${LN} -sf ${PREFIX}/man/man1/ectags.1.gz ${PREFIX}/man/man1/etags.1.gz

.include <bsd.port.mk>
