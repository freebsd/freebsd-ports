# New ports collection makefile for:	XEmacs
# Version required:	21.1.8
# Date created:		5 Dec 1997
# Whom:			Kazuyuki IENAGA <ienaga@jsys.co.jp>
#
# $FreeBSD$
#

# This is the MASTER port of XEmacs Mule slave ports(japanese/xemacs-*)
# and provides `Architecture Dependent' parts of xemacs binary. 
#
# Caracteristic variables of XEmacs Mule ports family:
#	MULE_COMMON       : COMMON port if defined
#	PKGLDIR           : Local PKGDIR of MASTER port(editors/xemacs-mule/pkg)
#	SITE_INCLUDES     : site include path(configure arguments)
#	SITE_LIBRARIES    : site libraries path(configure arguments)
#	WITH_INPUT_METHOD : input methods(configure arguments)
#	LIB_INPUT_METHOD  : LIB_DEPENDS list of Input Methods
#	BUILD_INPUT_METHOD: BUILD_DEPENDS list of Input Methods

DISTNAME=	xemacs-${XEMACS_VER}
PKGNAME=	${LANGPREFIX}xemacs${PKGNAMEEXT}-${XEMACS_VER}
CATEGORIES?=	editors
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/xemacs/${FTP_DIR}/ \
		ftp://ftp.xemacs.org/pub/xemacs/${FTP_DIR}/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/${FTP_DIR}/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/${FTP_DIR}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-elc${EXTRACT_SUFX} \
		${DISTNAME}-info${EXTRACT_SUFX}
DIST_SUBDIR=	xemacs

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

.if !defined(MULE_COMMON)
BUILD_DEPENDS=	${PREFIX}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.xemacs-devel:${PORTSDIR}/editors/xemacs-packages \
		${PREFIX}/lib/xemacs/mule-packages/pkginfo/MANIFEST.skk:${PORTSDIR}/editors/xemacs-mule-packages \
		${BUILD_INPUT_METHOD}
RUN_DEPENDS=	${PREFIX}/lib/${XEMACS_DIR}/lisp/x-win-xfree86.elc:${PORTSDIR}/editors/xemacs-mule-common \
		${PREFIX}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.xemacs-devel:${PORTSDIR}/editors/xemacs-packages \
		${PREFIX}/lib/xemacs/mule-packages/pkginfo/MANIFEST.skk:${PORTSDIR}/editors/xemacs-mule-packages
.endif
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		compface.1:${PORTSDIR}/mail/faces \
		tiff.4:${PORTSDIR}/graphics/tiff \
		${LIB_INPUT_METHOD}

WRKSRC=		${WRKDIR}/xemacs-${XEMACS_VER}
USE_AUTOCONF=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=${MACHINE_ARCH}--freebsd
CONFIGURE_ARGS?=--with-x11 \
		--with-xim=no \
		--with-mule \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib \
		--site-libraries='${SITE_LIBRARIES}' \
		--site-includes='${SITE_INCLUDES}' \
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
		--infopath=${PREFIX}/lib/xemacs/info:${PREFIX}/info:${X11BASE}/info:/usr/info:${PREFIX}/lib/texmf/doc/info:/usr/lib/texmf/doc:/usr/share/info \
		--with-clash-detection \
		--lockdir=/var/run/emacs/lock \
		${WITH_INPUT_METHOD}
MAKE_ENV=	LANG=C
MAKE_ARGS=	prefix=${PREFIX}
PATCHDIR=	${.CURDIR}/../../editors/xemacs-mule/patches
FILESDIR=	${.CURDIR}/../../editors/xemacs-mule/files
INSTALL_COOKIE=	${WRKDIR}/.install_done-${PKGNAME}
PACKAGE_COOKIE=	${WRKDIR}/.package_done-${PKGNAME}
STRIP=
INSTALL_TARGET?=install-arch-dep
PLIST?=		${PKGLDIR}/PLIST
PLIST_SUB?=	XEMACS_DIR=${XEMACS_DIR} ARCH_SUBDIR=${ARCH_SUBDIR} EMACS_CMD=${EMACS_CMD}

XEMACS_MAJVER=		21.1
XEMACS_VER=		21.1.8
EMACS_CMD=		xemacs-${XEMACS_VER}
XEMACS_DIR=		xemacs-${XEMACS_VER}
FTP_DIR=		xemacs-${XEMACS_MAJVER}
ARCH_SUBDIR=		${MACHINE_ARCH}--freebsd
PKGNAMEEXT?=		-mule
DESCR_TMPL?=		${.CURDIR}/../xemacs-mule/files/DESCR.tmpl
.if !defined(MULE_COMMON)
PKGLDIR=		${.CURDIR}/../../editors/xemacs-mule/pkg
SITE_INCLUDES+=		${PREFIX}/include
SITE_LIBRARIES+=	${PREFIX}/lib
WITH_INPUT_METHOD?=	--with-canna=no --with-wnn=no --with-wnn6=no
.endif

.if !defined(MULE_COMMON)
pre-build:
	@find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
	@${RM} -f ${WRKSRC}/lib-src/DOC* ${WRKSRC}/src/xemacs

# for xemacs-mule-common in defining ${WRKDIRPREFIX}
.if !exists(${WRKDIRPREFIX}${.CURDIR}/../../editors/xemacs-mule-common)
post-build:
	@${MKDIR} ${WRKDIRPREFIX}${.CURDIR}/../../editors/xemacs-mule-common
.endif

post-install::
.for file in b2m ctags etags gnuclient xemacs-${XEMACS_VER}
	@strip ${PREFIX}/bin/${file}
.endfor
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}
.endif

post-package:
	@${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE}

# for make DESCR (only maintainer use)
arrange::
	@${MKDIR} ${PKGDIR}
	@${SED} -e "s/%%XEMACS_VER%%/${XEMACS_VER}/g" \
		${DESCR_TMPL} > ${DESCR}

.include <bsd.port.mk>
