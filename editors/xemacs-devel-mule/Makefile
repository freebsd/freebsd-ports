# New ports collection makefile for:	X-Emacs with mule
# Date created:		3 Jan 2002
# Whom:			KIRIYAMA Kazuhiko<kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xemacs-devel-mule
PORTVERSION=	${XEMACS_VER:S/-/./}
CATEGORIES+=	editors
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|kiri/xemacs|} \
		${MASTER_SITE_XEMACS:S|%SUBDIR%|xemacs-${XEMACS_REL}|}
DISTNAME=	xemacs-${XEMACS_VER:S/-b/./}
DIST_SUBDIR=	xemacs

MAINTAINER=	kiri@FreeBSD.org
COMMENT?=	XEmacs(beta version) text editor with mule(Only the executables)

.include <bsd.port.pre.mk>

BUILD_DEPENDS=	${LOCALBASE}/lib/xemacs/mule-packages/pkginfo/MANIFEST.skk:${PORTSDIR}/editors/xemacs-mule-packages
RUN_DEPENDS=	${LOCALBASE}/lib/xemacs/xemacs-packages/etc/enriched.doc:${PORTSDIR}/editors/xemacs-packages \
		${LOCALBASE}/lib/xemacs/mule-packages/pkginfo/MANIFEST.skk:${PORTSDIR}/editors/xemacs-mule-packages
.if defined(PKGNAMEPREFIX)
RUN_DEPENDS+=	${LOCALBASE}/lib/xemacs-${XEMACS_VER}/lisp/x-win-xfree86.elc:${PORTSDIR}/editors/xemacs-devel-mule
.endif
.if !defined(WITHOUT_X11)
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		compface.1:${PORTSDIR}/mail/faces
USE_XLIB=	yes
USE_XPM=	yes
.endif
LIB_DEPENDS+=	intl.5:${PORTSDIR}/devel/gettext-old \
		${LIB_INPUT_METHOD}

XEMACS_MAJOR_VER?=	21
XEMACS_REL=		${XEMACS_MAJOR_VER}.5
XEMACS_VER=		${XEMACS_MAJOR_VER}.5-b16
XEMACS_ARCH=		${CONFIGURE_TARGET}

WRKSRC=		${WRKDIR}/xemacs-${XEMACS_VER:S/-b/./}
STRIP=
USE_AUTOCONF_VER=213
CONFIGURE_TARGET=${MACHINE_ARCH}--freebsd

CONFIGURE_ARGS=	--with-mule \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib \
		--site-libraries='${SITE_LIBRARIES}' \
		--site-includes='${SITE_INCLUDES}' \
		--with-sound=native \
		--with-site-lisp \
		--with-pop \
		--with-xfs \
		--with-ldap=no \
		--infopath=${LOCALBASE}/lib/xemacs/info:${LOCALBASE}/info:${X11BASE}/info:/usr/info:${LOCALBASE}/lib/texmf/doc/info:/usr/lib/texmf/doc:/usr/share/info \
		--with-clash-detection \
		--with-database=berkdb \
		${WITH_XPM} ${WITH_XIM} \
		${WITH_ATHENA} \
		${WITH_MENUBARS} ${WITH_SCROLLBARS} ${WITH_DIALOGS} ${WITH_WIDGETS} \
		${WITH_OFFIX} ${WITH_GTK} \
		${WITH_INPUT_METHOD}
MAKE_ARGS=	prefix=${PREFIX}
ALL_TARGET=	all dist
.if defined(PKGNAMEPREFIX)
INSTALL_TARGET=	install-arch-dep
PLIST=		${PKGDIR}/pkg-plist.arch-dep
.if ${PKGNAMEPREFIX} == "ja-"
DESCR=		${PKGDIR}/pkg-descr.ja
.endif
.else
MAN1=		ctags.1 etags.1 gnuattach.1 gnuclient.1 gnudoit.1 \
		gnuserv.1 xemacs.1
.endif
PKGDIR=		${.CURDIR}/../../editors/xemacs-devel-mule

PLIST_SUB=	XEMACS_VER=${XEMACS_VER} XEMACS_ARCH=${XEMACS_ARCH}

pre-fetch:
.if defined(WITHOUT_X11)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Set the environment variable WITHOUT_X11 if you "
	@${ECHO_MSG} "do not want to use X11."
CONFIGURE_ARGS+=	--without-x11
.else
.if !defined(WITHOUT_MOTIF)
.if !defined(MOTIF_STATIC)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If your MOTIF library is actually lesstif, you might occasionally"
	@${ECHO_MSG} "experience locked-up frames."
	@${ECHO_MSG} "In this case, set the environment variable MOTIF_STATIC and recompile, "
	@${ECHO_MSG} "which will force the use of athena widgets for dialogs."
.endif
CONFIG_ARGS+=	--with-jpeg=yes --with-png=yes --with-tiff=yes --with-xface=yes
USE_MOTIF=	yes

# hack to avoid shipping binaries linked with Motif
.if defined(MOTIF_STATIC)
WITH_DIALOGS=	--with-dialogs=athena
.else
WITH_DIALOGS=	--with-dialogs=motif
.endif

.if defined(PACKAGE_BUILDING)
WITH_OFFIX?=	--with-offix=no
.endif
WITH_ATHENA?=	--with-athena=xaw
WITH_MENUBARS?=	--with-menubars=lucid
WITH_SCROLLBARS?=--with-scrollbars=motif
WITH_WIDGETS?=	--with-widgets=motif
.endif
WITH_XPM?=	--with-xpm
WITH_XIM?=	--with-xim=xlib
WITH_ATHENA?=	--with-athena=xaw
WITH_MENUBARS?=	--with-menubars=athena
WITH_SCROLLBARS?=--with-scrollbars=athena
WITH_DIALOGS?=	--with-dialogs=athena
WITH_WIDGETS?=	--with-widgets=athena
.endif

BINNAMEEXT=		-mule
.if defined(CANNA) && defined(FREEWNN)
PKGNAMESUFFIX=		-canna+freewnn
WITH_INPUT_METHOD=	--with-canna --with-wnn --with-wnn6=no
LIB_INPUT_METHOD=	canna.1:${PORTSDIR}/japanese/Canna \
			wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
.elif defined(CANNA) && defined(WNN6)
PKGNAMESUFFIX=		-canna+wnn6
SITE_INCLUDES=		${LOCALBASE}/include/wnn6
WITH_INPUT_METHOD=	--with-canna --with-wnn6
LIB_INPUT_METHOD=	canna.1:${PORTSDIR}/japanese/Canna \
			wnn6.2:${PORTSDIR}/japanese/Wnn6-lib
.elif defined(FREEWNN)
PKGNAMESUFFIX=		-freewnn
WITH_INPUT_METHOD=	--with-wnn --with-canna=no --with-wnn6=no
LIB_INPUT_METHOD=	wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
.elif defined(WNN6)
PKGNAMESUFFIX=		-wnn6
SITE_INCLUDES=		${LOCALBASE}/include/wnn6
WITH_INPUT_METHOD=	--with-wnn6 --with-canna=no
LIB_INPUT_METHOD=	wnn6.2:${PORTSDIR}/japanese/Wnn6-lib
.elif defined(CANNA)
PKGNAMESUFFIX=		-canna
WITH_INPUT_METHOD=	--with-canna --with-wnn=no --with-wnn6=no
LIB_INPUT_METHOD=	canna.1:${PORTSDIR}/japanese/Canna
.endif
SITE_INCLUDES+=		${LOCALBASE}/include
SITE_LIBRARIES+=	${LOCALBASE}/lib
WITH_INPUT_METHOD?=	--with-canna=no --with-wnn=no --with-wnn6=no

# fix .so references in a few man pages
pre-configure::
.for file in etc/ctags.1 etc/gnuattach.1 etc/gnuclient.1 etc/gnudoit.1
	@${SED} -e 's/\.1/&.gz/' ${WRKSRC}/${file} > ${WRKDIR}/tmp_zot
	@${MV} ${WRKDIR}/tmp_zot ${WRKSRC}/${file}
.endfor

pre-build:
	@${FIND} ${WRKSRC} \( -name \*.orig -o -name \*~ \) \
		-exec ${RM} -f \{} \;
	@${RM} -f ${WRKSRC}/lib-src/DOC* ${WRKSRC}/src/xemacs

post-install::
.for file in b2m ctags ellcc etags gnuclient xemacs-${XEMACS_VER}
	${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
# For some reason install no longer makes ${PREFIX}/lib/xemacs/site-lisp.
# Do what PLIST does for pkg_add.
	${MKDIR} ${PREFIX}/lib/xemacs/site-lisp
	${CHMOD} 755 ${PREFIX}/lib/xemacs/site-lisp
	${RM} -f ${PREFIX}/bin/send-pr
.if defined(PKGNAMEPREFIX)
.if ${PKGNAMEPREFIX} == "ja-"
	@${LN} -sf ja ${PREFIX}/lib/xemacs/mule-packages/etc/app-defaults/ja_JP.eucJP
.endif
.endif

.include <bsd.port.post.mk>
