# New ports collection makefile for:	XEmacs
# Version required:	21.1.6
# Date created:		5 Dec 1997
# Whom:			Kazuyuki IENAGA <ienaga@jsys.co.jp>
#
# $FreeBSD$
#

DISTNAME=	xemacs-${VERSION}
PKGNAME=	${LANGPREFIX}xemacs${PKGNAMEEXT}-${VERSION}
CATEGORIES?=	editors
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/xemacs/${FTP_DIR}/ \
		ftp://ftp.xemacs.org/pub/xemacs/${FTP_DIR}/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/${FTP_DIR}/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/${FTP_DIR}/ \
		ftp://ftp.jpl.org/pub/elisp/
DISTFILES=	xemacs-${VERSION}.tar.gz xemacs-${VERSION}-elc.tar.gz \
		xemacs-${VERSION}-info.tar.gz \
		ps-print-jp.el.gz
DIST_SUBDIR=	xemacs

MAINTAINER?=	kiri@kiri.toba-cmt.ac.jp

BUILD_DEPENDS=	${PREFIX}/lib/xemacs/mule-packages/lisp/mule-base/japan-util.el:${PORTSDIR}/editors/xemacs-mule-base-packages \
		${BUILD_DEP_LIST}
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		compface.1:${PORTSDIR}/mail/faces \
		tiff.4:${PORTSDIR}/graphics/tiff \
		${LIB_INPUT_METHOD}
RUN_DEPENDS=	${PREFIX}/lib/xemacs/mule-packages/lisp/mule-base/japan-util.el:${PORTSDIR}/editors/xemacs-mule-base-packages \
		${RUN_DEP_LIST}

EXTRACT_ONLY=	xemacs-${VERSION}.tar.gz xemacs-${VERSION}-elc.tar.gz \
		xemacs-${VERSION}-info.tar.gz
WRKSRC=		${WRKDIR}/xemacs-${VERSION}
PATCHDIR=	${.CURDIR}/../../editors/xemacs-mule-common/patches
FILESDIR=	${.CURDIR}/../../editors/xemacs-mule-common/files
SCRIPTDIR=	${.CURDIR}/../../editors/xemacs-mule-common/scripts
INSTALL_COOKIE=	${WRKDIR}/.install_done-${PKGNAME}
PACKAGE_COOKIE=	${WRKDIR}/.package_done-${PKGNAME}
GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
CONFIGURE_TARGET=${MACHINE_ARCH}--freebsd
CONFIGURE_ARGS=	--with-x11 \
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
STRIP=
INSTALL_TARGET=	install-arch-dep
PLIST?=		${PKGLDIR}/PLIST
PLIST_SUB=	XEMACS_DIR=${XEMACS_DIR} ARCH_SUBDIR=${ARCH_SUBDIR}

MAJOR_VERSION=		21.1
VERSION=		21.1.6
EMACS_CMD=		xemacs-${VERSION}
XEMACS_DIR=		xemacs-${VERSION}
FTP_DIR=		xemacs-${MAJOR_VERSION}
ARCH_SUBDIR=		${MACHINE_ARCH}--freebsd
PKGNAMEEXT?=		-mule
PKGLDIR=		${.CURDIR}/../../editors/xemacs-mule/pkg
SITE_INCLUDES+=		${PREFIX}/include
SITE_LIBRARIES+=	${PREFIX}/lib
WITH_INPUT_METHOD?=	--with-canna=no --with-wnn=no --with-wnn6=no
RUN_DEP_LIST+=		${PREFIX}/lib/${XEMACS_DIR}/lisp/x-win-xfree86.elc:${PORTSDIR}/editors/xemacs-mule-common

pre-build:
	@find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
	@${RM} -f ${WRKSRC}/lib-src/DOC* ${WRKSRC}/src/xemacs

# for xemacs-mule-common in defining ${WRKDIRPREFIX}
.if !exists(${WRKDIRPREFIX}${.CURDIR}/../../editors/xemacs-mule-common)
post-build:
	@${MKDIR} ${WRKDIRPREFIX}${.CURDIR}/../../editors/xemacs-mule-common
.endif

post-install::
.for file in b2m ctags etags gnuclient xemacs-${VERSION}
	@strip ${PREFIX}/bin/${file}
.endfor
	@if [ -f ${PKGDIR}/INSTALL ]; then \
		${SETENV} PKG_PREFIX=${PREFIX} \
			${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL; \
	fi
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

post-package:
	@${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE}

.include <bsd.port.mk>
