# New ports collection makefile for:	XEmacs
# Version required:	20.4
# Date created:		5 Dec 1997
# Whom:			Kazuyuki IENAGA <ienaga@jsys.co.jp>
#
# $Id: Makefile,v 1.11 1998/11/11 12:55:23 asami Exp $
#

DISTNAME=	xemacs-20.4
PKGNAME?=	xemacs-mule-20.4
CATEGORIES?=	editors
MASTER_SITES=	ftp://unipro.jsys.co.jp/pub/editor/xemacs/20.4/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/xemacs-20.4/ \
		ftp://ftp.xemacs.org/pub/xemacs-20.4/ \
		ftp://ftp2.xemacs.org/pub/xemacs/xemacs-20.4/ \
		ftp://ftp.jpl.org/pub/elisp/
DISTFILES=	xemacs-20.4.tar.gz xemacs-20.4-elc.tar.gz \
		xemacs-20.4-info.tar.gz xemacs-20.4-mule.tar.gz \
		ps-print-jp.el.gz

MAINTAINER?=	kiri@kiri.toba-cmt.ac.jp

BUILD_DEPENDS=	${BUILD_INPUT_METHOD}
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.2:${PORTSDIR}/graphics/png \
		compface.1:${PORTSDIR}/mail/faces \
		${LIB_INPUT_METHOD}
RUN_DEPENDS=	${PREFIX}/lib/${XEMACS_DIR}/etc/BABYL:${PORTSDIR}/editors/xemacs-mule-common

EXTRACT_ONLY=	xemacs-20.4.tar.gz xemacs-20.4-elc.tar.gz \
		xemacs-20.4-info.tar.gz xemacs-20.4-mule.tar.gz
WRKSRC=		${WRKDIR}/xemacs-20.4
PATCHDIR=	${.CURDIR}/../../editors/xemacs-mule-common/patches
FILESDIR=	${.CURDIR}/../../editors/xemacs-mule-common/files
SCRIPTDIR=	${.CURDIR}/../../editors/xemacs-mule-common/scripts
INSTALL_COOKIE=	${WRKDIR}/.install_done-${PKGNAME}
PACKAGE_COOKIE=	${WRKDIR}/.package_done-${PKGNAME}
GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	i386-unknown-freebsd \
		--with-clash-detection \
		--lockdir=/var/run/emacs/lock \
		--with-x11 \
		--with-mule \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib \
		--site-libraries='${SITE_LIBRARIES}' \
		--site-includes='${SITE_INCLUDES}' \
		--sitelispdir=${PREFIX}/lib/${XEMACS_DIR}/lisp:${PREFIX}/lib/${XEMACS_DIR}/site-lisp:${PREFIX}/lib/xemacs/site-lisp:${PREFIX}/share/emacs/site-lisp \
		--infopath=${PREFIX}/lib/xemacs/info:${PREFIX}/info:${X11BASE}/info:/usr/info:${PREFIX}/lib/texmf/doc/info:/usr/lib/texmf/doc:/usr/share/info \
		${MISC_OPTIONS} ${WITH_INPUT_METHOD} ${WITH_WIDGETS}

STRIP=

INSTALL_TARGET=	install-arch-dep

PLIST_SUB=	XEMACS_DIR=${XEMACS_DIR}

PKGLDIR=	${.CURDIR}/../../editors/xemacs-mule/pkg
XEMACS_DIR=	xemacs-20.4

.if defined(WNN4)
SITE_INCLUDES=		${X11BASE}/include
SITE_LIBRARIES=		${X11BASE}/lib
.endif
SITE_INCLUDES+=		${PREFIX}/include
SITE_LIBRARIES+=	${PREFIX}/lib
.if defined(CANNA)
LIB_INPUT_METHOD+=	canna.1:${PORTSDIR}/japanese/Canna
WITH_INPUT_METHOD+=	--with-canna
.endif
.if defined(WNN4)
BUILD_INPUT_METHOD+=	${PREFIX}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
WITH_INPUT_METHOD+=	--with-wnn
.elif defined(WNN6)
BUILD_INPUT_METHOD+=	${PREFIX}/include/wnn/jlib.h:${PORTSDIR}/japanese/Wnn6-lib
WITH_INPUT_METHOD+=	--with-wnn6
.endif
.if !defined(WITH_INPUT_METHOD)
WITH_INPUT_METHOD=	--with-wnn=no
WITH_INPUT_METHOD+=	--with-wnn6=no
WITH_INPUT_METHOD+=	--with-canna=no
.endif

WITH_WIDGETS=	--with-menubars=lucid --with-scrollbars=lucid --with-dialogs=athena
MISC_OPTIONS=	--with-xface --with-xpm --with-sound=native --with-pop --with-xfs

LANGUAGE?=
.if (${LANGUAGE} == "Japanese")
PLIST=	${PKGLDIR}/PLIST-ja
.else
PLIST=	${PKGLDIR}/PLIST
.endif

pre-build:
	@find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
	@${RM} -f ${WRKSRC}/lib-src/DOC* ${WRKSRC}/src/xemacs
.if (${LANGUAGE} == "Japanese")
	@if [ -e ${WRKSRC}/lisp/packages/ps-print.elc ]; then \
		${RM} -f ${WRKSRC}/lisp/packages/ps-print.elc; \
	fi
	@${GZCAT} ${DISTDIR}/ps-print-jp.el.gz > ${WRKSRC}/lisp/packages/ps-print.el
.endif

post-install::
.for file in b2m ctags etags gnuclient xemacs-20.4
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
