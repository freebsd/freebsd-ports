# New ports collection makefile for:	mule 2.3@19.34
# Date created:		6 July 1997
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mule
PORTVERSION=	${MULE_VERSION}
CATEGORIES+=	editors
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/mule/ \
		ftp://ftp.mei.co.jp/archive/free/gnu/emacs/Mule/ \
		ftp://ftp.iij.ad.jp/pub/misc/mule/ \
		http://www.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/mule/
DISTFILES=	emacs-${EMACS_VERSION}b${EXTRACT_SUFX} \
		mule-${MULE_VERSION}-${EMACS_VERSION}.patch-981002.tar.gz

PATCH_SITES=	ftp://etlport.etl.go.jp/pub/mule/
PATCHFILES=	mule-${MULE_VERSION:S/.//}-${EMACS_VERSION:S/.//}-alpha01.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER?=	taoka@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/share/${EMACS_PREFIX}/${EMACS_VERSION}/lisp/mule.el:${PORTSDIR}/editors/mule-common
LIB_DEPENDS=	${LIB_INPUT_METHOD}
BUILD_DEPENDS=	${BUILD_INPUT_METHOD}

MULE_VERSION=	2.3
EMACS_VERSION=	19.34

USE_XLIB=	yes
EXTRACT_ONLY=	emacs-${EMACS_VERSION}b${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/emacs-${EMACS_VERSION}
PATCHDIR=	${.CURDIR}/../../editors/mule-common/patches
FILESDIR=	${.CURDIR}/../../editors/mule-common/files
SCRIPTDIR=	${.CURDIR}/../../editors/mule-common/scripts
PLIST=		${.CURDIR}/../../editors/mule/pkg/PLIST
INSTALL_COOKIE=	${WRKDIR}/.install_done-${PKGNAME}
PACKAGE_COOKIE=	${WRKDIR}/.package_done-${PKGNAME}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ENV=      LIBDIR="${LIBDIR}"
# /usr/bin/sed should be used because configure script includes 'Ctrl-L'
CONFIGURE_ENV=	PATH=/usr/bin:$$PATH
EMACS_PREFIX=	mule
EMACS_EXECUTABLE =	mule
CONFIGURE_ARGS=	--with-executable=${EMACS_EXECUTABLE} \
		--with-emacs-prefix=${EMACS_PREFIX} \
		--with-terminal-face \
		--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib \
		${WITH_INPUT_METHOD} ${WITH_DIALOGS}
STRIP=

INSTALL_TARGET=	install-arch-dep

.if defined(CANNA)
LIB_INPUT_METHOD+=	canna.1:${PORTSDIR}/japanese/Canna
WITH_INPUT_METHOD+=	--with-canna --with-canna-libraries=${PREFIX}/lib \
		--with-canna-includes=${PREFIX}/include
.endif
.if defined(SJ3)
BUILD_INPUT_METHOD+=sj3serv:${PORTSDIR}/japanese/sj3
WITH_INPUT_METHOD+= --with-sj3
.endif
.if defined(WNN4)
BUILD_INPUT_METHOD+=${PREFIX}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
WITH_INPUT_METHOD+=	--with-wnn4 --with-wnn-libraries=${X11BASE}/lib \
		--with-wnn-includes=${X11BASE}/include/wnn
.elif defined(CWNN4)
BUILD_INPUT_METHOD+=${PREFIX}/bin/cWnn4/cserver:${PORTSDIR}/chinese/Wnn
WITH_INPUT_METHOD+=	--with-wnn4 --with-wnn-libraries=${X11BASE}/lib/libcwnn.a \
		--with-wnn-includes=${X11BASE}/include/cwnn
.elif defined(KWNN4)
BUILD_INPUT_METHOD+=${PREFIX}/bin/kWnn4/kserver:${PORTSDIR}/korean/Wnn
WITH_INPUT_METHOD+=	--with-wnn4 --with-wnn-libraries=${X11BASE}/lib/libkwnn.a \
		--with-wnn-includes=${X11BASE}/include/kwnn
.elif defined(WNN6)
BUILD_INPUT_METHOD+=${PREFIX}/include/wnn/jlib.h:${PORTSDIR}/japanese/Wnn6-lib
WITH_INPUT_METHOD+=	--with-wnn6 --with-wnn-libraries=${PREFIX}/lib/libwnn.a \
		--with-wnn-includes=${PREFIX}/include/wnn
.endif
COMP_ELC=	egg.elc wnn-egg.elc sj3-client.elc sj3-egg.elc canna.elc
ELC_DIR=	../lisp

WITH_DIALOGS=	--with-x-toolkit

SITE_START=${PREFIX}/share/${EMACS_PREFIX}/${EMACS_VERSION}/site-lisp/site-start.el

# ORIGINAL, MEW_ORG_PATCH and MEW_PATCH are used for debugging.
#
#   ORIGINAL: original mule 2.3 based on emacs 19.34
#   MEW_ORG_PATCH: apply mew's patches to original mule (http://www.mew.org)
#   MEW_PATCH: apply mew's patch after apply Mr. Katayama's patches
post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/mule-${MULE_VERSION}-${EMACS_VERSION}.patch-981002.tar.gz ${EXTRACT_AFTER_ARGS} -C ${WRKDIR}
	${CP} ${FILESDIR}/unexfreebsd.c ${WRKSRC}/src
.if !defined(ORIGINAL) && !defined(MEW_ORG_PATCH)
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKDIR}/takana-${EMACS_VERSION}.tar.gz ${EXTRACT_AFTER_ARGS} -C ${WRKDIR}
	${MKDIR} ${WRKSRC}/lisp/its
	${CP} ${WRKDIR}/lisp/its/* ${WRKSRC}/lisp/its/
.endif

.if !defined(ORIGINAL)
post-patch:
.if !defined(MEW_ORG_PATCH)
	cd ${WRKSRC}; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/patch-${EMACS_VERSION}
	cd ${WRKSRC}; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/Mule-${MULE_VERSION}-${EMACS_VERSION}.patch
	cd ${WRKSRC}; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/extra.patch
.if defined(MEW_PATCH)
	cd ${WRKSRC}/lisp; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/mew/egg.el-${EMACS_VERSION}.patch-for_katayama
.endif
.else
	cd ${WRKSRC}/lisp; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/mew/egg.el-${EMACS_VERSION}.patch
.endif
.if defined(MEW_PATCH) || defined(MEW_ORG_PATCH)
	cd ${WRKSRC}/lisp; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/mew/canna.el-${EMACS_VERSION}.patch
	cd ${WRKSRC}/lisp; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/mew/sj3-egg.el.patch
.endif
.endif

pre-build:
	find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
	${RM} -f ${WRKSRC}/etc/DOC* ${WRKSRC}/src/emacs ${WRKSRC}/src/emacs-${EMACS_VERSION}.*

post-build:
# bytecompile elisps for Japanese input method
	for file in ${COMP_ELC}; do \
		target="$$target ${ELC_DIR}/$$file"; \
	done; \
	cd ${WRKSRC}/src; \
	./temacs -batch -l mule-inst.el $$target

# If site-start.el exists, you should run below when you install by
# this port
pre-install:
	@if [ -f ${SITE_START} ]; then \
		${MV} ${SITE_START} ${SITE_START}.orig ; \
		 ${SED} -e '/;; BEGIN mule-family/,/;; END mule-family/d' \
			 ${SITE_START}.orig > ${SITE_START}; \
	 fi

post-install:
	strip ${PREFIX}/bin/${EMACS_EXECUTABLE}-${EMACS_VERSION}
# for wnn4+sj3 or wnn6+sj3
	@if [ -e ${PKGDIR}/INSTALL ]; then \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL; \
	fi
# Installing site-start.el
#   (we redefun set-korean-environment etc)
.if defined(CWNN4)
	 ${SED} -e 's/;;\(.*\);;CHINESE$$/\1;;CHINESE/' \
		-e 's/;;\(.*\);;not KOREAN$$/\1;;not KOREAN/' \
		-e 's,%%X11BASE%%,${X11BASE},' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},' \
		 ${FILESDIR}/site-start.el.tmpl >> ${SITE_START}
.elif defined(KWNN4)
	 ${SED} -e 's/;;\(.*\);;KOREAN$$/\1;;KOREAN/' \
		-e 's,%%X11BASE%%,${X11BASE},' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},' \
		 ${FILESDIR}/site-start.el.tmpl >> ${SITE_START}
.else
	 ${SED} -e 's/;;\(.*\);;not KOREAN$$/\1;;not KOREAN/' \
		-e 's,%%X11BASE%%,${X11BASE},' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},' \
		 ${FILESDIR}/site-start.el.tmpl >> ${SITE_START}
.endif
	 @${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

post-package:
	@${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE}

.include <bsd.port.mk>
