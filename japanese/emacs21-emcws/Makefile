# New ports collection makefile for:	GNU emacs
# Version required:	20.7
# Date created:		08 Oct. 2000
# Whom:			NAKAJI Hiroyuki <nakaji@jp.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	emcws
PORTVERSION=	20.7
CATEGORIES=	japanese editors ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs
DISTNAME=	emacs-${PORTVERSION}

PATCH_SITES=	ftp://ftp.ki.nu/pub/emcws/ \
		ftp://ftp.jpl.org/pub/misc/
PATCHFILES=	emcws-${EMACS_VER}-20010622.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	nakaji@jp.freebsd.org

Y2K=            http://www.gnu.org/software/year2000.html

RUN_DEPENDS=	emacs-${EMACS_VER}:${PORTSDIR}/editors/emacs20

WRKSRC=		${WRKDIR}/emacs-${EMACS_VER}

USE_AUTOCONF=	YES
USE_GMAKE=	YES
EMACS_VER=	20.7

# Change these as you like.
USE_WNN6?=	YES
USE_FREEWNN?=	NO
USE_CANNA?=	YES
USE_SJ3?=	NO

CONFIGURE_TARGET=	${MACHINE_ARCH}--freebsd
.if !defined(NO_X11)
CONFIGURE_ARGS=	--with-x-toolkit --with-pop
USE_XLIB=	YES
.else
CONFIGURE_ARGS=	--with-x=no --with-pop
.endif
.if defined(USE_WNN6)
.if (${USE_WNN6} == "yes" || ${USE_WNN6} == "YES")
CONFIGURE_ARGS+=--with-wnn6 --with-wnn-includes=${LOCALBASE}/include/wnn6/wnn \
		--with-wnn-libraries=${LOCALBASE}/lib/libwnn6.so
LIB_DEPENDS+=	wnn6.1:${PORTSDIR}/japanese/Wnn6-lib
.endif
.endif
.if defined(USE_FREEWNN)
.if (${USE_FREEWNN} == "yes" || ${USE_FREEWNN} == "YES")
CONFIGURE_ARGS+=--with-wnn4 --with-wnn-includes=${LOCALBASE}/include/wnn \
		--with-wnn-libraries=${LOCALBASE}/lib/libwnn.so
LIB_DEPENDS+=	wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
.endif
.endif
.if defined(USE_CANNA)
.if (${USE_CANNA} == "yes" || ${USE_CANNA} == "YES")
CONFIGURE_ARGS+=	--with-canna \
			--with-canna-includes=${LOCALBASE}/include \
			--with-canna-libraries=${LOCALBASE}/lib
LIB_DEPENDS+=		canna.1:${PORTSDIR}/japanese/Canna
.endif
.endif
.if defined(USE_SJ3)
.if (${USE_SJ3} == "yes" || ${USE_SJ3} == "YES")
CONFIGURE_ARGS+=	--with-sj3
BUILD_DEPENDS+=		sj3serv:${PORTSDIR}/japanese/sj3
.endif
.endif

DOC_FILE=	DOC-EMCWS-${EMACS_VER}.1
EMCWS_ELCS=	busyu.el \
		can-n-egg.el \
		canna.el \
		canna.elc \
		egg-jsymbol.el \
		egg-keymap.el \
		egg.el \
		egg.elc \
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
		wnn-egg.el \
		wnn-egg.elc

PLIST_SUB=	EMACS_VER=${EMACS_VER} EMACS_ARCH=${CONFIGURE_TARGET} \
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

pre-fetch:
	@${CAT} ${FILESDIR}/emcws-message

pre-build:
	find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
	${RM} -rf ${WRKSRC}/info/*
	${LN} -sf DOC ${WRKSRC}/etc/${DOC_FILE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/emacs ${PREFIX}/bin/emcws-${EMACS_VER}
	@${RM} -f ${PREFIX}/bin/emcws
	@${LN} ${PREFIX}/bin/emcws-${EMACS_VER} ${PREFIX}/bin/emcws
	@test -d ${PREFIX}/share/emacs/${EMACS_VER}-emcws/etc || \
		${MKDIR} ${PREFIX}/share/emacs/${EMACS_VER}-emcws/etc
	@${INSTALL_DATA} ${WRKSRC}/etc/DOC ${PREFIX}/share/emacs/${EMACS_VER}-emcws/etc/${DOC_FILE}
	@test -d ${PREFIX}/share/emacs/${EMACS_VER}-emcws/lisp/its || \
		${MKDIR} ${PREFIX}/share/emacs/${EMACS_VER}-emcws/lisp/its
	@for i in ${EMCWS_ELCS}; do \
		${CP} -p ${WRKSRC}/lisp/$$i \
		${PREFIX}/share/emacs/${EMACS_VER}-emcws/lisp/$$i; \
	done
	@test -d ${PREFIX}/share/emacs/${EMACS_VER}-emcws/site-lisp || \
		${MKDIR} ${PREFIX}/share/emacs/${EMACS_VER}-emcws/site-lisp
	@if [ ! -f ${PREFIX}/share/emacs/${EMACS_VER}-emcws/site-lisp/subdirs.el ]; then \
	  (${ECHO} "(if (fboundp 'normal-top-level-add-subdirs-to-load-path)"; \
	   ${ECHO} "    (normal-top-level-add-subdirs-to-load-path))") \
	  > ${PREFIX}/share/emacs/${EMACS_VER}-emcws/site-lisp/subdirs.el ; \
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
