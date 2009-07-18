# New ports collection makefile for:	GNU emacs
# Date created:		11 October 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	emacs
PORTVERSION=	21.3
PORTREVISION=	12
CATEGORIES=	editors ipv6
MASTER_SITES=	${MASTER_SITE_GNU:C/\/gnu\//\/old-gnu\//g}
MASTER_SITE_SUBDIR=	${PORTNAME}

.if defined(WITH_MENUBAR_FONTSET)
PATCH_SITES=		http://nijino.homelinux.net/emacs/
PATCHFILES=		emacs-21.1-fontset.patch emacs-21.2-menu-encode.patch
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	GNU editing macros

CONFLICTS=	emacs-19.* emacs-22.* \
		xemacs-[0-9]* xemacs-devel-[0-9]* \
		xemacs-mule-[0-9]* xemacs-devel-mule-[0-9]*

.if !defined(WITHOUT_X11)
LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png
USE_XORG=	xpm
.endif

USE_AUTOTOOLS=	autoconf:213
USE_GMAKE=	yes

CONFIGURE_TARGET=	${MACHINE_ARCH}--freebsd
.if defined(WITHOUT_X11)
CONFIGURE_ARGS=		--with-x=no
.endif
.if defined(WITHOUT_XIM)
CONFIGURE_ARGS+=	--without-xim
.endif

MAN1=		ctags.1 emacs.1 etags.1 gfdl.1
PLIST_SUB=	EMACS_VER=${PORTVERSION} EMACS_ARCH=${CONFIGURE_TARGET}
TEXIFILES=	ada-mode autotype cc-mode cl dired-x ebrowse ediff \
		faq emacs emacs-mime eshell eudc forms gnus idlwave \
		info message mh-e pcl-cvs reftex sc speedbar vip \
		viper widget woman
INFO=		ada-mode autotype ccmode cl dired-x ebrowse ediff \
		efaq emacs emacs-mime eshell eudc forms gnus idlwave \
		info message mh-e pcl-cvs reftex sc speedbar vip \
		viper widget woman

LATEST_LINK=	emacs21

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
CFLAGS:=	${CFLAGS:C/-O.?/-O0/g}
CONFIGURE_ENV=	CFLAGS="${CFLAGS}"
.endif

pre-everything::
.if !defined(WITH_MENUBAR_FONTSET)
	@${ECHO_MSG} "====>"
	@${ECHO_MSG} "====> To enable menubar fontset support, define WITH_MENUBAR_FONTSET"
	@${ECHO_MSG} "====>"
.endif

post-patch:
	@${RM} -f ${WRKSRC}/info/*
	@(cd ${WRKSRC}/man ; \
	for f in ${TEXIFILES} ; do \
	${CP} $${f}.texi $${f}.texi.orig ; \
	${SED} -e "s/@dircategory Emacs/@dircategory The Emacs editor and associated tools/" < $${f}.texi.orig > $${f}.texi ; \
	${RM} $${f}.texi.orig ; \
	done)

post-build:
	(cd ${WRKSRC}/lisp ; \
	 ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} recompile ; \
	 ${RM} ${WRKSRC}/src/emacs ${WRKSRC}/src/emacs-${PORTVERSION}.1 ; \
	 cd ${WRKSRC}/src ; \
	 ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
