# New ports collection makefile for:	GNU emacs with mule 4.1 patch
# Date created:		25 April 2001
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	emacs-${MULE}
PORTVERSION=	${EMACS_VER}.${MULE_VER}
PORTREVISION=	2
CATEGORIES=	editors ipv6
MASTER_SITES=	http://www.ainet.or.jp/~inoue/software/emacs-xim/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs
DISTNAME=	emacs-${EMACS_VER}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${XIM_PATCH}${EXTRACT_SUFX}

PATCH_SITES=	http://www.teu.ac.jp/nsit/~yatagawa/comp/emacs/ \
		ftp://ftp.m17n.org/pub/mule/dynamic-loading/ \
		http://www.etl.go.jp/~tomo/comp/emacsen/
PATCHFILES=	emacs-${EMACS_VER}-mule-${MULE_VER}.patch \
		emacs-20.4-dl3.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	shige@FreeBSD.org
COMMENT=	GNU editing macros with dl module function and mule 4.1(binary only)

BUILD_DEPENDS=	emacs-${EMACS_VER}:${PORTSDIR}/editors/emacs20
RUN_DEPENDS=	emacs-${EMACS_VER}:${PORTSDIR}/editors/emacs20

WRKSRC=		${WRKDIR}/emacs-${EMACS_VER}

USE_AUTOCONF=	yes
USE_GMAKE=	yes
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
EMACS_VER=	20.7
CONFIGURE_TARGET=	${MACHINE_ARCH}--freebsd
.if !defined(WITHOUT_X11)
CONFIGURE_ARGS=	--with-x-toolkit --with-pop
USE_XLIB=	yes
.else
CONFIGURE_ARGS=	--with-x=no --with-pop
.endif

# for Mule patch
MULE=		mule
MULE_MAJOR_VER=	4
MULE_VER=	4.1
MULE_PATCHED_ELS=	international/ccl.el international/mule-cmds.el \
			international/mule-conf.el international/mule.el \
			international/titdic-cnv.el
MULE_ELS=	loaddefs.el loadup.el ${MULE_PATCHED_ELS}

# for XIM extension
XIM_PATCH=	emacs20-xim-20000713
.if defined(WITHOUT_XIM) && (${WITHOUT_XIM} == "yes")
MAKE_FLAGS=	MYCPPFLAG="-DX_I18N_INHIBITED"
.endif

DOC_FILE=	DOC-MULE-${EMACS_VER}.1

PLIST_SUB=	EMACS_VER=${EMACS_VER} EMACS_ARCH=${CONFIGURE_TARGET} \
		DOC_FILE=${DOC_FILE} \
		MULE=${MULE} MULE_MAJOR_VER=${MULE_MAJOR_VER}

SCRIPTS_ENV=	SED=${SED} MV=${MV} \
		DOC_FILE=${DOC_FILE}

.if defined(WITH_XPG4)
.if ${OSVERSION} >= 220000 && ${OSVERSION} < 400020 || \
	${OSVERSION} >= 500000 && ${OSVERSION} < 500005
CONFIGURE_ARGS+=	--with-xpg4
.endif
.endif

pre-patch:
	@(cd ${WRKSRC} ; \
	  ${PATCH} ${PATCH_ARGS} -p1 < ../${XIM_PATCH}/${XIM_PATCH}.diff ;\
	)

pre-build:
	@${RM} -rf ${WRKSRC}/info/*
	@${LN} -sf DOC ${WRKSRC}/etc/${DOC_FILE}

post-build:
# NEED twice times byte-compile mule.elc.
	@(cd ${WRKSRC}/lisp ; \
		${WRKSRC}/src/emacs -batch -q -no-init-file \
			-f batch-byte-compile ${MULE_PATCHED_ELS} ; \
	)
	@${RM} -f ${WRKSRC}/src/emacs ${WRKSRC}/src/emacs-${EMACS_VER}*
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@(cd ${WRKSRC}/lisp ; \
		${WRKSRC}/src/emacs -batch -q -no-init-file \
			-f batch-byte-compile ${MULE_PATCHED_ELS} ; \
	)
	@${RM} -f ${WRKSRC}/src/emacs ${WRKSRC}/src/emacs-${EMACS_VER}*
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
# Install ${MULE} binary.
	@${INSTALL} -c -s -m 555 -o root -g wheel ${WRKSRC}/src/emacs ${PREFIX}/bin/${MULE}-${EMACS_VER}
# Install ${MULE} own data file.
	@${INSTALL_DATA} ${WRKSRC}/etc/DOC ${PREFIX}/share/emacs/${EMACS_VER}/etc/${DOC_FILE}
# Making directories for ${MULE}.
	@for i in ${EMACS_VER}/lisp/international ${EMACS_VER}/leim ${EMACS_VER}/site-lisp site-lisp ; do \
	  ${MKDIR} ${PREFIX}/share/${MULE}${MULE_MAJOR_VER}/$${i} ; \
	done
# Install elisp files for ${MULE}.
	@for i in ${MULE_ELS}; do \
		${INSTALL_DATA} ${WRKSRC}/lisp/$${i} \
			${PREFIX}/share/${MULE}${MULE_MAJOR_VER}/${EMACS_VER}/lisp/$${i} ; \
	done
	@for i in ${MULE_PATCHED_ELS} ; do \
		${INSTALL_DATA} ${WRKSRC}/lisp/$${i}c \
			${PREFIX}/share/${MULE}${MULE_MAJOR_VER}/${EMACS_VER}/lisp/$${i}c ; \
	done
# Install subdirs.el files for ${MULE}.
	@${INSTALL_DATA} ${WRKSRC}/lisp/subdirs.el \
	  ${PREFIX}/share/${MULE}${MULE_MAJOR_VER}/${EMACS_VER}/lisp/subdirs.el
	@for i in site-lisp/subdirs.el ${EMACS_VER}/site-lisp/subdirs.el ; do \
	  if [ ! -f ${PREFIX}/share/${MULE}${MULE_MAJOR_VER}/$${i} ]; then \
	  (${ECHO_CMD} "(if (fboundp 'normal-top-level-add-subdirs-to-load-path)"; \
	   ${ECHO_CMD} "    (normal-top-level-add-subdirs-to-load-path))") \
	  > ${PREFIX}/share/${MULE}${MULE_MAJOR_VER}/$${i} ; \
	  fi ; \
	done

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
