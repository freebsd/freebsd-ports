# ex:ts=8
# Ports collection makefile for:  vim
# Date created:			  Sat June 29, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME?=	vim
PORTVERSION=	6.0aa
PORTREVISION=	0
CATEGORIES?=	editors
MASTER_SITES=	ftp://nuxi.ucdavis.edu/pub/vim/unreleased/unix/ \
		ftp://ftp.nuxi.com/pub/vim/unreleased/unix/ \
		ftp://ftp.freesoftware.com/pub/vim/unreleased/unix/ \
		ftp://ftp.vim.org/pub/vim/unreleased/unix/  \
		ftp://ftp.is.co.za/applications/editors/unreleased/vim/  \
		ftp://ftp.prz.tu-berlin.de/pub/unix/editors/vim/unreleased/unix/  \
		ftp://ftp.progsoc.uts.edu.au/pub/vim/unreleased/unix/
DISTNAME=	vim-${PORTVERSION}
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX} ${DISTNAME}-rt${EXTRACT_SUFX}

#PATCH_SITES=	${MASTER_SITES:S/unix/patches/}
#.for p in 01
#PATCHFILES+=	6.0.0${p}
#.endfor

MAINTAINER?=	obrien@FreeBSD.org

.if defined(PACKAGE_BUILDING) && !defined(LITE)
BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80
LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80
USE_PERL5=	yes
USE_PYTHON=	yes
.endif

DIST_SUBDIR=	vim
WRKSRC=		${WRKDIR}/vim${PORTVERSION:S/.//g}/src
PATCH_DIST_ARGS=	-d ${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//g} --forward --quiet -E ${PATCH_DIST_STRIP}
MAKE_ARGS+=	CONF_ARGS="--prefix=${PREFIX} --with-tlib=termlib"
ALL_TARGET=	#
PLIST_SUB=	VIM_VER=${DISTNAME:S/-//:S/.//}
MAN1=		vim.1 vimtutor.1 xxd.1
MLINKS=		vim.1 rvim.1  vim.1 rview.1

.include <bsd.port.pre.mk>

.if !defined(LITE)
MLINKS+=	vim.1 gvim.1  vim.1 gview.1  vim.1 rgvim.1  vim.1 rgview.1

MAKE_ARGS+=	CONF_OPT_MAX="--enable-max-features"
I18N=		CONF_OPT_MULTIBYTE="--enable-multibyte --enable-fontset --enable-xim"

.if defined(WITH_ATHENA)
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=athena" ${I18N}
#MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=yes" ${I18N}
.elif defined(WITH_GTK)
USE_GTK=	yes
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=gtk --with-gtk-prefix=${X11BASE}" ${I18N}
MAKE_ARGS+=	X_LIBS="$(X_LIBS) -lXt"
.else
USE_MOTIF=	yes
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=motif --with-motif-lib=\"${MOTIFLIB}\"" MOTIFHOME=${X11BASE} ${I18N}
.endif

.if defined(PACKAGE_BUILDING)
MAKE_ARGS+=	CONF_OPT_PERL="--enable-perlinterp --enable-pythoninterp --enable-tclinterp --enable-cscope"
.endif

.else	# LITE
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=no --without-x"
MAKE_ARGS+=	CONF_OPT_PERL="--disable-perlinterp --disable-pythoninterp --disable-tclinterp"
.endif	# LITE

pre-build:
	@(cd ${WRKSRC}; ${MAKE} distclean)

post-install:
	[ -e ${PREFIX}/bin/gvim ] || (cd ${PREFIX}/bin ; ${LN} -sf vim gvim)

.include <bsd.port.post.mk>
