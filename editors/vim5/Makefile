# ex:ts=8
# Ports collection makefile for:  vim
# Date created:			  Sat June 29, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME?=	vim
PORTVERSION=	5.8.8
CATEGORIES?=	editors
MASTER_SITES=	ftp://nuxi.ucdavis.edu/pub/vim/unix/ \
		ftp://relay.nuxi.com/pub/vim/unreleased/unix/ \
		ftp://ftp.vim.org/pub/vim/unix/  \
		ftp://ftp.vim.org/pub/vim/unreleased/unix/  \
		ftp://ftp.is.co.za/applications/editors/vim/  \
		ftp://ftp.prz.tu-berlin.de/pub/unix/editors/vim/unix/  \
		ftp://ftp.progsoc.uts.edu.au/pub/vim/unix/
DISTNAME=	vim-${PORTVERSION:C/\.[0-9]+$//g}
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX} ${DISTNAME}-rt${EXTRACT_SUFX}

PATCH_SITES=	${MASTER_SITES:S/unix/patches/}
.for p in 01 02 03 04 05 06 07 08
PATCHFILES+=	5.8.0${p}
.endfor

MAINTAINER?=	obrien@FreeBSD.org
COMMENT=	Vi "workalike", with many additional features

.if defined(PACKAGE_BUILDING) && !defined(LITE)
BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80
LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80
USE_PERL5=	yes
.endif

LATEST_LINK?=	vim5
DIST_SUBDIR=	vim
WRKSRC=		${WRKDIR}/${DISTNAME}/src
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_DIST_STRIP}
MAKE_ARGS+=	CONF_ARGS="--prefix=${PREFIX} --with-tlib=termlib --disable-pythoninterp"
ALL_TARGET=	#
PLIST_SUB=	VIM_VER=${DISTNAME:S/-//:S/.//}
MAN1=		vim.1 vimtutor.1 xxd.1
MLINKS=		vim.1 rvim.1  vim.1 rview.1  ectags.1 etags.1
MLINKS+=	vim.1 gvim.1  vim.1 gview.1  vim.1 rgvim.1  vim.1 rgview.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500800
BROKEN=		"Does not compile with perl 5.8"
.endif

# Determine if we need xpg4.
# No xpg4 in libc below 400020 and 500005
.if ${OSVERSION} < 400020 && ${OSVERSION} < 500005
MAKE_ARGS+=	LIBS=-lxpg4
.endif

.if !defined(LITE)
MAKE_ARGS+=	CONF_OPT_MAX="--enable-max-features"
I18N=		CONF_OPT_MULTIBYTE="--enable-multibyte --enable-fontset --enable-xim"

.if defined(NO_GUI)
WITHOUT_X11=	yes
.endif

.if !defined(WITHOUT_X11)
.if defined(WITH_ATHENA)
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=athena" ${I18N}
#MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=yes" ${I18N}
.elif defined(WITH_GTK)
USE_GTK=	yes
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=gtk --with-gtk-prefix=${X11BASE}" ${I18N}
.else
USE_MOTIF=	yes
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=motif --with-motif-lib=\"${MOTIFLIB}\"" MOTIFHOME=${X11BASE} ${I18N}
.endif
.else  # WITHOUT_X11
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=no --without-x --enable-multibyte"
.endif # WITHOUT_X11

.if defined(PACKAGE_BUILDING)
MAKE_ARGS+=	CONF_OPT_PERL="--enable-perlinterp --enable-pythoninterp --enable-tclinterp --enable-cscope"
.endif

.else	# LITE
PKGNAMESUFFIX?=	-lite
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=no --without-x --enable-multibyte"
MAKE_ARGS+=	CONF_OPT_PERL="--disable-perlinterp --disable-pythoninterp --disable-tclinterp"
.endif	# LITE

pre-build:
	@(cd ${WRKSRC}; ${MAKE} distclean)

post-install:
	[ -e ${PREFIX}/bin/gvim ] || (cd ${PREFIX}/bin ; ${LN} -s vim gvim)
	#	below needed for `vim-lite' port
	${TEST} -e ${PREFIX}/bin/rgvim  || (cd ${PREFIX}/bin ; ${LN} -s vim rgvim)
	${TEST} -e ${PREFIX}/bin/gview || (cd ${PREFIX}/bin ; ${LN} -s vim gview)
	${TEST} -e ${PREFIX}/bin/rgview || (cd ${PREFIX}/bin ; ${LN} -s vim rgview)
	cd ${PREFIX} ;\
	    ${FIND} share/vim/${DISTNAME:S/-//:S/.//}/ -type f -o -type l	\
	    	| ${SORT} \
	    	>${WRKDIR}/PLIST.share-vim
	cd ${PREFIX} ;\
	    ${FIND} share/vim/${DISTNAME:S/-//:S/.//}/ -type d \
	    	| ${SORT} -r | ${SED} -e 's/^/@dirrm /g' \
		>>${WRKDIR}/PLIST.share-vim
	${ECHO_CMD} "r ${TMPPLIST}"			> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.share-vim"		>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"					>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.share-vim"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"				>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-share-vim
	cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.post.mk>
