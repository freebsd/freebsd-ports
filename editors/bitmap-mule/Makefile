# New ports collection makefile for:	bitmap for mule
# Version required:	8.0
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	bitmap-mule-${BITMAP_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.jpl.org/pub/elisp/bitmap/

MAINTAINER=	shige@FreeBSD.org

# distfile version
BITMAP_VER=		8.0
BITMAP_PKG_VER=		${BITMAP_VER}
BITMAPDOCDIR=	share/doc/bitmap
BITMAP_SETUPEL=	bitmap-setupel.el
BITMAP_FONT=	${X11BASE}/lib/X11/fonts/local/etl8x16-bitmap.pcf.gz

# mule-19.34
EMACS_NAME=	mule
EMACS_PORT=	mule
EMACS_VER=	19.34
EMACS_LIBDIR=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER=	${EMACS_LIBDIR}/${EMACS_VER}

# target name for make build
ALL_TARGET?=	elc

PKGNAME=	bitmap-${EMACS_PORT}-${BITMAP_PKG_VER}
EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}-common \
		${BITMAP_FONT}:${PORTSDIR}/x11-fonts/bitmap-font
SCRIPTS_ENV=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		TARGETS=${BITMAP_SETUPEL}
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		BITMAP_SETUPEL=${BITMAP_SETUPEL} \
		BITMAPDOCDIR=${BITMAPDOCDIR}
MAKE_FLAGS=	EMACS=${EMACS_CMD}

# depends on apel
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}

# depends on flim
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/site-lisp/flim/std11.el:${PORTSDIR}/editors/flim-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/site-lisp/flim/std11.el:${PORTSDIR}/editors/flim-${EMACS_PORT}

pre-configure:
	@${CP} ${FILESDIR}/${BITMAP_SETUPEL}.in ${WRKDIR}

post-install:
	@${INSTALL_DATA} ${WRKDIR}/${BITMAP_SETUPEL} \
		${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${BITMAPDOCDIR}
	@for i in ChangeLog README.* ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${BITMAPDOCDIR}/ ; \
	done
.endif

.include <bsd.port.mk>
