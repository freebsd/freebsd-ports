# New ports collection makefile for:	mule
# Date created:		6 July 1997
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mule
PORTVERSION=	${MULE_VERSION}
PKGNAMESUFFIX=	${INPUT_METHOD}
PORTREVISION=	4
CATEGORIES+=	editors
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/ \
		ftp://ftp.jaist.ac.jp/pub/GNU/mule/ \
		http://www.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/mule/
DISTFILES=	mule-${MULE_VERSION}-${EMACS_VERSION}.tar.gz \
		mule-${MULE_VERSION}-${EMACS_VERSION}.patch-981002.tar.gz

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	A multilingual emacs based 19.34 (Only the executables)

RUN_DEPENDS=	${PREFIX}/share/${EMACS_PREFIX}/${EMACS_VERSION}/lisp/mule.el:${PORTSDIR}/editors/mule-common
LIB_DEPENDS=	${LIB_INPUT_METHOD}
BUILD_DEPENDS=	${BUILD_INPUT_METHOD}

MULE_VERSION=	2.3
EMACS_VERSION=	19.34

SLAVEDIRS=	chinese/mule-freewnn

USE_XLIB=	yes
WRKSRC=		${WRKDIR}/mule-${MULE_VERSION}-${EMACS_VERSION}
PATCHDIR=	${.CURDIR}/../../editors/mule-common/files
FILESDIR=	${.CURDIR}/../../editors/mule-common/files
MD5_FILE=	${.CURDIR}/../../editors/mule-common/distinfo
SCRIPTDIR=	${.CURDIR}/../../editors/mule-common/scripts
PLIST=		${.CURDIR}/../../editors/mule/pkg-plist
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ENV=	LIBDIR="${LIBDIR}"
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
INPUT_METHOD+=		canna
LIB_INPUT_METHOD+=	canna.1:${PORTSDIR}/japanese/Canna
WITH_INPUT_METHOD+=	--with-canna --with-canna-libraries=${PREFIX}/lib \
			--with-canna-includes=${PREFIX}/include
.endif
.if defined(FREEWNN)
INPUT_METHOD+=		freewnn
LIB_INPUT_METHOD+=	wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
WITH_INPUT_METHOD+=	--with-wnn4 --with-wnn-libraries=${LOCALBASE}/lib \
			--with-wnn-includes=${LOCALBASE}/include/wnn
.elif defined(CFREEWNN)
INPUT_METHOD+=		freewnn
LIB_INPUT_METHOD+=	cwnn.0:${PORTSDIR}/chinese/FreeWnn-lib
WITH_INPUT_METHOD+=	--with-wnn4 --with-cwnn4 --with-wnn-libraries=${LOCALBASE}/lib \
			--with-wnn-includes=${LOCALBASE}/include/cwnn
.elif defined(KFREEWNN)
INPUT_METHOD+=		freewnn
LIB_INPUT_METHOD+=	kwnn.0:${PORTSDIR}/korean/FreeWnn-lib
WITH_INPUT_METHOD+=	--with-wnn4 --with-kwnn4 --with-wnn-libraries=${LOCALBASE}/lib \
			--with-wnn-includes=${LOCALBASE}/include/kwnn
.endif
.if defined(SJ3)
INPUT_METHOD+=		sj3
BUILD_INPUT_METHOD+=	sj3serv:${PORTSDIR}/japanese/sj3
WITH_INPUT_METHOD+=	--with-sj3
.endif
.if !defined(FREEWNN) && !defined(CFREEWNN) && !defined(KFREEWNN)
.if defined(WNN6)
INPUT_METHOD+=		wnn6
LIB_INPUT_METHOD+=	wnn6.2:${PORTSDIR}/japanese/Wnn6-lib
WITH_INPUT_METHOD+=	--with-wnn6 --with-wnn-libraries=${LOCALBASE}/lib \
			--with-wnn-includes=${LOCALBASE}/include/wnn6/wnn
.elif defined(WNN7)
# mule 2.3 cannot use Wnn7SDK (Wnn7-lib) 
# so it should use Wnn6SDK (Wnn6-lib) instead of Wnn7SDK.
# But it can partly support Wnn7 by ${PREFIX}/share/mule/19.34/lisp/eggrc-wnn
INPUT_METHOD+=		wnn7
LIB_INPUT_METHOD+=	wnn6.2:${PORTSDIR}/japanese/Wnn6-lib
WITH_INPUT_METHOD+=	--with-wnn6=-lwnn6 --with-wnn-libraries=${LOCALBASE}/lib \
			--with-wnn-includes=${LOCALBASE}/include/wnn6/wnn
.endif
.endif
COMP_ELC=	egg.elc wnn-egg.elc sj3-client.elc sj3-egg.elc canna.elc
ELC_DIR=	../lisp

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" && ${OSVERSION} >= 600031
BROKEN=		"Configure fails on amd64 >= 6.x"
.endif

# Make a value of INPUT_METHOD
.if defined(INPUT_METHOD)
INPUT_METHOD!=	${ECHO_CMD} ${INPUT_METHOD} | sed -e 's/^/-/' -e 's/ /+/g'
.endif


WITH_DIALOGS=	--with-x-toolkit

SITE_START=${PREFIX}/share/${EMACS_PREFIX}/${EMACS_VERSION}/site-lisp/site-start.el

# ORIGINAL, MEW_ORG_PATCH and MEW_PATCH are used for debugging.
#
#   ORIGINAL: original mule 2.3 based on emacs 19.34
#   MEW_ORG_PATCH: apply mew's patches to original mule (http://www.mew.org)
#   MEW_PATCH: apply mew's patch after apply Mr. Katayama's patches
post-extract:
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
	${FIND} ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
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
	${STRIP_CMD} ${PREFIX}/bin/${EMACS_EXECUTABLE}-${EMACS_VERSION}
# for freewnn+sj3 or wnn6+sj3
	@if [ -e ${PKGINSTALL} ]; then \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL; \
	fi
# Installing site-start.el
#   (we redefun set-korean-environment etc)
.if defined(CFREEWNN)
	 ${SED} -e 's/;;\(.*\);;CHINESE$$/\1;;CHINESE/' \
		-e 's/;;\(.*\);;not KOREAN$$/\1;;not KOREAN/' \
		-e 's,%%X11BASE%%,${X11BASE},' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},' \
		 ${FILESDIR}/site-start.el.tmpl >> ${SITE_START}
.elif defined(KFREEWNN)
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

.include <bsd.port.post.mk>
