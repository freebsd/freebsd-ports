# New ports collection makefile for:	XEmacs with Mule
# Date created:		8 Dec 1999
# Whom:			KIRIYAMA Kazuhiko<kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

# This is the MASTER port of XEmacs Mule slave ports(japanese/xemacs${XEMACS_MAJOR_VER}-*)
# and provides `Architecture Dependent' parts of xemacs binary.
#
# Caracteristic variables of XEmacs Mule ports family:
#	MULE_PORT         : Mule port if defined(means COMMN or SLAVE)
#	MULE_COMMON       : COMMON port if defined
#	MULE_SLAVE        : SLAVE port if defined
#	SITE_INCLUDES     : site include path(configure arguments)
#	SITE_LIBRARIES    : site libraries path(configure arguments)
#	WITH_INPUT_METHOD : input methods(configure arguments)
#	LIB_INPUT_METHOD  : LIB_DEPENDS list of Input Methods
#	BUILD_INPUT_METHOD: BUILD_DEPENDS list of Input Methods
#	WITH_XIM          : X Input Method(configure arguments), xlib or motif

.if !defined(MULE_SLAVE) && !defined(MULE_COMMON)
MULE_SLAVE=	yes
.endif

MAINTAINER?=	kiri@FreeBSD.org

BUILD_DEPENDS=	${BUILD_INPUT_METHOD}
.if defined(MULE_SLAVE)
RUN_DEPENDS=	${LOCALBASE}/lib/xemacs-${XEMACS_VER}/lisp/x-win-xfree86.elc:${PORTSDIR}/editors/xemacs${XEMACS_MAJOR_VER}-mule-common \
		${LOCALBASE}/lib/xemacs/mule-packages/pkginfo/MANIFEST.skk:${PORTSDIR}/editors/xemacs-mule-packages
.else
RUN_DEPENDS=	${LOCALBASE}/lib/xemacs/mule-packages/pkginfo/MANIFEST.skk:${PORTSDIR}/editors/xemacs-mule-packages
.endif
LIB_DEPENDS=	compface.1:${PORTSDIR}/mail/faces \
		intl.1:${PORTSDIR}/devel/gettext \
		${LIB_INPUT_METHOD}

CONFIGURE_ARGS?=--with-x11 \
		--with-xim=${WITH_XIM} \
		--with-mule \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib \
		--site-libraries='${SITE_LIBRARIES}' \
		--site-includes='${SITE_INCLUDES}' \
		--gung-ho=yes \
		--with-xface \
		--with-xpm \
		--with-sound=native \
		--with-site-lisp \
		--with-pop \
		--with-xfs \
		--with-menubars=lucid \
		--with-scrollbars=lucid \
		--with-dialogs=athena \
		--with-jpeg \
		--with-png \
		--with-tiff \
		--infopath=${LOCALBASE}/lib/xemacs/info:${LOCALBASE}/info:${X11BASE}/info:/usr/info:${LOCALBASE}/lib/texmf/doc/info:/usr/lib/texmf/doc:/usr/share/info \
		--with-clash-detection \
		--lockdir=/var/run/emacs/lock \
		--with-database=berkdb \
		${WITH_INPUT_METHOD}
MAKE_ENV=	LANG=C
INSTALL_COOKIE=	${WRKDIR}/.install_done-${PKGNAME}
PACKAGE_COOKIE=	${WRKDIR}/.package_done-${PKGNAME}
STRIP=
INSTALL_TARGET?=install-arch-dep
FILESDIR=	${.CURDIR}/../../editors/xemacs${XEMACS_MAJOR_VER}/files
PATCHDIR=	${.CURDIR}/../../editors/xemacs${XEMACS_MAJOR_VER}/files
PKGDIR?=	${.CURDIR}/../../editors/xemacs${XEMACS_MAJOR_VER}-mule

SLAVEDIRS=	editors/xemacs21-mule-common editors/xemacs21-mule-sumo

XEMACS_MAJOR_VER?=	21
MULE_PORT=		yes
PKGNAMESUFFIX?=		-mule
DESCR_TMPL?=		${.CURDIR}/../xemacs${XEMACS_MAJOR_VER}-mule/files/DESCR.tmpl
COMMENT_TEXT?=		XEmacs(version ${XEMACS_MAJOR_VER}) text editor with mule(Only the executables)
.if defined(MULE_SLAVE)
BINNAMEEXT=		-mule
SITE_INCLUDES+=		${LOCALBASE}/include
SITE_LIBRARIES+=	${LOCALBASE}/lib
WITH_INPUT_METHOD?=	--with-canna=no --with-wnn=no --with-wnn6=no
.endif
WITH_XIM?=		xlib

.if defined(MULE_SLAVE)
pre-build:
	@find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
	@${RM} -f ${WRKSRC}/lib-src/DOC* ${WRKSRC}/src/xemacs

# for xemacs${XEMACS_MAJOR_VER}-mule-common in defining ${WRKDIRPREFIX}
.if !exists(${WRKDIRPREFIX}${.CURDIR}/../../editors/xemacs${XEMACS_MAJOR_VER}-mule-common)
post-build:
	@${MKDIR} ${WRKDIRPREFIX}${.CURDIR}/../../editors/xemacs${XEMACS_MAJOR_VER}-mule-common
.endif

post-install::
	@${LN} -sf ja ${PREFIX}/lib/xemacs/mule-packages/etc/app-defaults/ja_JP.EUC
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}
.endif

post-package:
	@${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE}

## for make DESCR and COMMENT (only maintainer use)
#pre-arrange::
#	@${MKDIR} ${PKGDIR}
#	@${ECHO} "${COMMENT_TEXT}" > ${COMMENT}
#.if (${PKGNAMESUFFIX} == "-canna") || (${PKGNAMESUFFIX} == "-mule") || (${PKGNAMESUFFIX} == "-mule-common")
#	@${SED} -e "s/%%XEMACS_VER%%/${XEMACS_VER}/g" \
#		-e "s/%%XEMACS_REL%%/${XEMACS_REL}/g" \
#		-e "s/%%XEMACS_MAJOR_VER%%/${XEMACS_MAJOR_VER}/g" \
#		${DESCR_TMPL} > ${DESCR}
#.endif
#	${CHOWN} kiri:staff ${COMMENT} ${DESCR}
#
## for make PLIST (only maintainer use)
#arrange::
#.if (${PKGNAMESUFFIX} == "-mule")
#	${RM} -f ${WRKPLIST}
#	if [ -f ${PLIST} ]; then ${MV} ${PLIST} ${PLIST}.org; fi
#	${MAKE} build
#	${MAKE} DIRRM2RMDIRS="lib/xemacs/mule-packages/etc lib/xemacs/mule-packages lib/xemacs/mule-packages/etc/app-defaults" \
#		DIRRMDEPTH=2 plist
#	${RM} -f ${PLIST}.org
#.endif
#.if ${PKGNAMESUFFIX} == "-mule-common"
#	${RM} -f ${WRKPLIST}.tmp
#	if [ -f ${PLIST} ]; then ${MV} ${PLIST} ${PLIST}.org; fi
#	${TOUCH} ${PLIST}
#	${MAKE} build
#	${MAKE} DIRRM2RMDIRS="lib/xemacs-${XEMACS_VER}" PLIST_EXCLS="etc/rc.d" \
#		DIRRMDEPTH=1 plist
#.for dirp in site mule xemacs
#.for dir in etc info man pkginfo
#	${ECHO} "@exec mkdir -p %D/lib/xemacs/${dirp}-packages/${dir}" >> ${WRKPLIST}.tmp
#	${ECHO} "@unexec rmdir %D/lib/xemacs/${dirp}-packages/${dir} 2>/dev/null || true" >> ${WRKPLIST}.tmp
#.endfor
#	${ECHO} "@unexec rmdir %D/lib/xemacs/${dirp}-packages 2>/dev/null || true" >> ${WRKPLIST}.tmp
#.endfor
#	${ECHO} "@exec mkdir -p /var/run/emacs/lock ; chmod 1777 /var/run/emacs/lock" >> ${WRKPLIST}.tmp
#	${CAT} ${WRKPLIST} >> ${WRKPLIST}.tmp
#	${MV} ${WRKPLIST}.tmp ${WRKPLIST}
#	${CHOWN} kiri:staff ${WRKPLIST}
#	if [ ! -s ${PLIST} ]; then \
#		${MV} ${WRKPLIST} ${PLIST}; \
#	fi
#	${RM} -f ${PLIST}.org
#.endif

.if ${PKGNAMESUFFIX} != "-mule-common"
pre-plist:
	@${ECHO} "===> pre-plist of ${PKGNAME}"
	${MKDIR} ${PREFIX}/lib/xemacs/mule-packages/etc/app-defaults/ja
.endif

MASTERDIR=	${.CURDIR}/../../editors/xemacs${XEMACS_MAJOR_VER}

.include "${MASTERDIR}/Makefile"
