# New ports collection makefile for:	mule
# Version required:	2.3
# Date created:		6 July 1997
# Whom:			Satoshi Taoka <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id: Makefile,v 1.30 1997/09/10 08:49:29 asami Exp $
#

DISTNAME=	mule-2.3
PKGNAME?=	mule-2.3
CATEGORIES?=	editors
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/mule/ \
		ftp://ftp.mei.co.jp/archive/free/gnu/emacs/Mule/ \
		ftp://ftp.iij.ad.jp/pub/misc/mule/ \
		ftp://ports.jp.FreeBSD.org/pub/incoming/distfiles/
DISTFILES=	mule-2.3.tar.gz mule-2.3.patch-970819.tar.gz

MAINTAINER?=	taoka@infonets.hiroshima-u.ac.jp

RUN_DEPENDS=	${PREFIX}/lib/mule/19.28/lisp/mule.el:${PORTSDIR}/editors/mule-common
LIB_DEPENDS=	${LIB_INPUT_METHOD}
BUILD_DEPENDS=	${BUILD_INPUT_METHOD}

EXTRACT_ONLY=	mule-2.3.tar.gz
WRKSRC=		${WRKDIR}/mule
PATCHDIR=	${.CURDIR}/../../editors/mule-common/patches
FILESDIR=	${.CURDIR}/../../editors/mule-common/files
SCRIPTDIR=	${.CURDIR}/../../editors/mule-common/scripts
PLIST=		${.CURDIR}/../../editors/mule/pkg/PLIST
INSTALL_COOKIE=	${WRKDIR}/.install_done-${PKGNAME}
PACKAGE_COOKIE=	${WRKDIR}/.package_done-${PKGNAME}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --terminal-face \
		--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib \
		--locallisppath=${PREFIX}/lib/mule/site-lisp:${PREFIX}/share/emacs/site-lisp \
		${WITH_INPUT_METHOD} ${WITH_DIALOGS}
STRIP=

INSTALL_TARGET=	install-arch-dep

.if defined(CANNA)
LIB_INPUT_METHOD+=	canna\\.1\\.:${PORTSDIR}/japanese/Canna
WITH_INPUT_METHOD+=	--canna --canna-libraries=${PREFIX}/lib \
		--canna-includes=${PREFIX}/include
.endif
.if defined(SJ3)
BUILD_INPUT_METHOD+=sj3serv:${PORTSDIR}/japanese/sj3
WITH_INPUT_METHOD+= --sj3
.endif
.if defined(WNN4)
BUILD_INPUT_METHOD+=${PREFIX}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
WITH_INPUT_METHOD+=	--with-wnn4 --wnn-libraries=${X11BASE}/lib/libwnn.a \
		--wnn-includes=${X11BASE}/include/wnn
.elif defined(CWNN4)
BUILD_INPUT_METHOD+=${PREFIX}/bin/cWnn4/cserver:${PORTSDIR}/chinese/Wnn
WITH_INPUT_METHOD+=	--with-wnn4 --wnn-libraries=${X11BASE}/lib/libcwnn.a \
		--wnn-includes=${X11BASE}/include/cwnn
.elif defined(KWNN4)
BUILD_INPUT_METHOD+=${PREFIX}/bin/kWnn4/kserver:${PORTSDIR}/korean/Wnn
WITH_INPUT_METHOD+=	--with-wnn4 --wnn-libraries=${X11BASE}/lib/libkwnn.a \
		--wnn-includes=${X11BASE}/include/kwnn
.elif defined(WNN6)
BUILD_INPUT_METHOD+=${PREFIX}/include/wnn/jlib.h:${PORTSDIR}/japanese/Wnn6-lib
WITH_INPUT_METHOD+=	--with-wnn6 --wnn-libraries=${PREFIX}/lib/libwnn.a \
		--wnn-includes=${PREFIX}/include/wnn
.endif

WITH_DIALOGS=	--with-x-toolkit

SITE_START=${PREFIX}/lib/mule/site-lisp/site-start.el

post-extract:
	${EXTRACT_CMD} -C ${WRKSRC} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/mule-2.3.patch-970819.tar.gz
	cd ${WRKSRC}; ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ./takana.tar.gz

pre-patch:
	cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < ${WRKSRC}/patch

post-patch:
	cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < ${WRKSRC}/Mule-2.3.patch

pre-build:
	find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
	${RM} -f ${WRKSRC}/etc/DOC* ${WRKSRC}/src/emacs ${WRKSRC}/src/emacs-19.28.*

# If site-start.el exists, you should run below when you install by
# this port
pre-install:
	@if [ -f ${SITE_START} ]; then \
		${MV} ${SITE_START} ${SITE_START}.orig ; \
		${SED} -e '/;; BEGIN mule-family/,/;; END mule-family/d' \
			${SITE_START}.orig > ${SITE_START}; \
	fi

post-install:
# note that any2ps is a script
.for file in b2m coco ctags emacsclient etags m2ps mule-19.28
	strip ${PREFIX}/bin/${file}
.endfor
# for wnn4+sj3 or wnn6+sj3
	@if [ -e ${PKGDIR}/INSTALL ]; then \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL; \
	fi
# Installing site-start.el
#   (we redefun set-korean-environment etc)
.if defined(CWNN4)
	${SED} -e 's/;;\(.*\);;CHINESE$$/\1;;CHINESE/' \
		-e 's/;;\(.*\);;not KOREAN$$/\1;;not KOREAN/' \
		${FILESDIR}/site-start.el.tmpl >> ${SITE_START}
.elif defined(KWNN4)
	${SED} -e 's/;;\(.*\);;KOREAN$$/\1;;KOREAN/' \
		${FILESDIR}/site-start.el.tmpl >> ${SITE_START}
.else
	${SED} -e 's/;;\(.*\);;not KOREAN$$/\1;;not KOREAN/' \
		${FILESDIR}/site-start.el.tmpl >> ${SITE_START}
.endif
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

post-package:
	@${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE}

.include <bsd.port.mk>
