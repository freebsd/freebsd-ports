# New ports collection makefile for:	GNU emacs
# Date created:		10 Apr. 2002
# Whom:			NAKAJI Hiroyuki <nakaji@jp.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	emcws
PORTVERSION=	${EMACS_VER}
PORTREVISION=	3
CATEGORIES=	japanese editors ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs
DISTNAME=	emacs-${PORTVERSION}

PATCH_SITES=	ftp://ftp.ki.nu/pub/emcws/ \
		ftp://ftp.jpl.org/pub/misc/
PATCHFILES=	emcws-${EMACS_VER}-20031213.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	nakaji@jp.freebsd.org
COMMENT=	Emacs + Canna + Wnn + Sj3

BUILD_DEPENDS=	emacs-${EMACS_VER}:${PORTSDIR}/editors/emacs21

WRKSRC=		${WRKDIR}/emacs-${EMACS_VER}

USE_AUTOCONF=	YES
USE_GMAKE=	YES
EMACS_VER=	21.3

# Change these as you like.
WITH_WNN6?=	NO
WITH_WNN7?=	YES
WITH_FREEWNN?=	NO
WITH_CANNA?=	YES
WITH_SJ3?=	NO

CONFIGURE_TARGET=	${MACHINE_ARCH}--freebsd

.if !defined(NO_X11)
CONFIGURE_ARGS=	--with-x-toolkit --with-pop
USE_XLIB=	YES
.else
CONFIGURE_ARGS=	--with-x=no --with-pop
.endif

.if (${WITH_WNN6} == "yes" || ${WITH_WNN6} == "YES")
CONFIGURE_ARGS+=--with-wnn --with-wnn-includes=${LOCALBASE}/include/wnn6/wnn \
		--with-wnn-libraries=${LOCALBASE}/lib/libwnn6.so
LIB_DEPENDS+=	wnn6.2:${PORTSDIR}/japanese/Wnn6-lib
.endif

.if (${WITH_WNN7} == "yes" || ${WITH_WNN7} == "YES")
CONFIGURE_ARGS+=--with-wnn --with-wnn-includes=${LOCALBASE}/include/wnn7/wnn \
		--with-wnn-libraries=${LOCALBASE}/lib/libwnn7.so
LIB_DEPENDS+=	wnn7.1:${PORTSDIR}/japanese/Wnn7-lib
.endif

.if (${WITH_FREEWNN} == "yes" || ${WITH_FREEWNN} == "YES")
CONFIGURE_ARGS+=--with-wnn --with-wnn-includes=${LOCALBASE}/include/wnn \
		--with-wnn-libraries=${LOCALBASE}/lib/libwnn.so
LIB_DEPENDS+=	wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
.endif

.if (${WITH_CANNA} == "yes" || ${WITH_CANNA} == "YES")
CONFIGURE_ARGS+=	--with-canna \
			--with-canna-includes=${LOCALBASE}/include \
			--with-canna-libraries=${LOCALBASE}/lib
LIB_DEPENDS+=		canna.1:${PORTSDIR}/japanese/Canna
.endif

.if (${WITH_SJ3} == "yes" || ${WITH_SJ3} == "YES")
CONFIGURE_ARGS+=	--with-sj3
BUILD_DEPENDS+=		sj3serv:${PORTSDIR}/japanese/sj3
.endif

DOC_FILE=	DOC-EMCWS-${EMACS_VER}.1
EMCWS_ELCS=	busyu.el \
		can-n-egg.el \
		canna.el \
		egg-jsymbol.el \
		egg-keymap.el \
		egg.el \
		eggrc-sj3 \
		eggrc-v41 \
		eggrc-wnn \
		isearch-ext.el \
		isearch-ext.elc \
		its/han-kata.el \
		its/hankaku.el \
		its/hira.el \
		its/kanainput.el \
		its/kata.el \
		its/zenkaku.el \
		mule-inst.el \
		sj3-client.el \
		sj3-egg.el \
		wnn-client.el \
		wnn-egg.el

.if (${WITH_WNN6} == "yes" || ${WITH_WNN6} == "YES") || (${WITH_WNN7} == "yes" || ${WITH_WNN7} == "YES") || (${WITH_FREEWNN} == "yes" || ${WITH_FREEWNN} == "YES")
EMCWS_ELCS+=	egg.elc \
		wnn-egg.elc
PLIST_SUB+=	WITH_WNN=""
.else
PLIST_SUB+=	WITH_WNN="@comment "
.endif

.if (${WITH_CANNA} == "yes" || ${WITH_CANNA} == "YES")
EMCWS_ELCS+=	canna.elc
PLIST_SUB+=	WITH_CANNA=""
.else
PLIST_SUB+=	WITH_CANNA="@comment "
.endif

.if (${WITH_SJ3} == "yes" || ${WITH_SJ3} == "YES")
EMCWS_ELCS+=	sj3-client.elc \
		sj3-egg.elc
PLIST_SUB+=	WITH_SJ3=""
.else
PLIST_SUB+=	WITH_SJ3="@comment "
.endif

MULE_PATCHED_ELS=	help.el help.elc \
			international/ccl.el international/mule-cmds.el \
			international/mule-conf.el international/mule.el \
			international/titdic-cnv.el \
			international/ccl.elc international/mule-cmds.elc \
			international/mule.elc \
			international/titdic-cnv.elc \
			loaddefs.el loadup.el

PLIST_SUB+=	EMACS_VER=${EMACS_VER} EMACS_ARCH=${CONFIGURE_TARGET} \
		DOC_FILE=${DOC_FILE}

SCRIPTS_ENV=	SED=${SED} MV=${MV} \
		DOC_FILE=${DOC_FILE}

.if defined(WITH_XPG4)
.if ${OSVERSION} >= 220000 && ${OSVERSION} < 400020
CONFIGURE_ARGS+=	--with-xpg4
.endif
.if ${OSVERSION} >= 500000 && ${OSVERSION} < 500005
CONFIGURE_ARGS+=	--with-xpg4
.endif
.endif

.if exists(${PREFIX}/bin/emacs-${EMACS_VER})
EMACS_BASE=${PREFIX}
.else
EMACS_BASE=${LOCALBASE}
.endif

pre-fetch:
	@${CAT} ${FILESDIR}/emcws-message

pre-build:
	${FIND} ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
	${RM} -rf ${WRKSRC}/info/*
	@(cd ${WRKSRC}/src/../lisp; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} compile-files EMACS=${EMACS_BASE}/bin/emacs-${EMACS_VER})
	@(cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} emacs)
	@(cd ${WRKSRC}/src/../lisp; \
	${WRKSRC}/src/emacs -batch -q -f batch-byte-compile \
	egg.el wnn-egg.el \
	help.el international/ccl.el international/mule-cmds.el \
	international/mule.el international/titdic-cnv.el)
	${RM} -f ${WRKSRC}/src/emacs ${WRKSRC}/src/emacs-${EMACS_VER}.1
	${RM} -f ${WRKSRC}/etc/${DOC_FILE}
	${RM} -f ${WRKSRC}/lib-src/fns-emcws-${EMACS_VER}.1.el

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/emacs ${PREFIX}/bin/emcws-${EMACS_VER}
	@${RM} -f ${PREFIX}/bin/emcws
	@${LN} ${PREFIX}/bin/emcws-${EMACS_VER} ${PREFIX}/bin/emcws
	@test -d ${PREFIX}/share/emacs/${EMACS_VER}-emcws/etc || \
		${MKDIR} ${PREFIX}/share/emacs/${EMACS_VER}-emcws/etc
	@${INSTALL_DATA} ${WRKSRC}/etc/${DOC_FILE} ${PREFIX}/share/emacs/${EMACS_VER}-emcws/etc/${DOC_FILE}
	@test -d ${PREFIX}/share/emacs/${EMACS_VER}-emcws/lisp/its || \
		${MKDIR} ${PREFIX}/share/emacs/${EMACS_VER}-emcws/lisp/its
	@for i in ${EMCWS_ELCS}; do \
		${INSTALL_DATA} ${WRKSRC}/lisp/$$i \
		${PREFIX}/share/emacs/${EMACS_VER}-emcws/lisp/$$i; \
	done
	@test -d ${PREFIX}/share/emacs/${EMACS_VER}-emcws/lisp/international || \
		${MKDIR} ${PREFIX}/share/emacs/${EMACS_VER}-emcws/lisp/international
	@for i in ${MULE_PATCHED_ELS}; do \
		${INSTALL_DATA} ${WRKSRC}/lisp/$$i \
		${PREFIX}/share/emacs/${EMACS_VER}-emcws/lisp/$$i; \
	done
	@test -d ${PREFIX}/libexec/emacs/${EMACS_VER}/${CONFIGURE_TARGET} || \
		${MKDIR} ${PREFIX}/libexec/emacs/${EMACS_VER}/${CONFIGURE_TARGET}
	@${INSTALL_DATA} ${WRKSRC}/lib-src/fns-emcws-${EMACS_VER}.1.el \
		${PREFIX}/libexec/emacs/${EMACS_VER}/${CONFIGURE_TARGET}/fns-emcws-${EMACS_VER}.1.el
	@test -d ${PREFIX}/share/emacs/${EMACS_VER}-emcws/site-lisp || \
		${MKDIR} ${PREFIX}/share/emacs/${EMACS_VER}-emcws/site-lisp
	@if [ ! -f ${PREFIX}/share/emacs/${EMACS_VER}-emcws/site-lisp/subdirs.el ]; then \
	  (${ECHO_CMD} "(if (fboundp 'normal-top-level-add-subdirs-to-load-path)"; \
	   ${ECHO_CMD} "    (normal-top-level-add-subdirs-to-load-path))") \
	  > ${PREFIX}/share/emacs/${EMACS_VER}-emcws/site-lisp/subdirs.el ; \
	fi
	@if [ ! -f ${PREFIX}/share/emacs/${EMACS_VER}-emcws/lisp/subdirs.el ]; then \
	  (${ECHO_CMD} "(if (fboundp 'normal-top-level-add-subdirs-to-load-path)"; \
	   ${ECHO_CMD} "    (normal-top-level-add-subdirs-to-load-path))") \
	  > ${PREFIX}/share/emacs/${EMACS_VER}-emcws/lisp/subdirs.el ; \
	fi

.include <bsd.port.mk>
