# New ports collection makefile for:	bitmap for emacs20
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
BITMAP_FONT=	${X11BASE}/lib/X11/fonts/local/etl8x16-bitmap.pcf.gz

# emacs20
EMACS_NAME=	emacs
EMACS_PORT=	emacs20
EMACS_VER=	20.4
EMACS_LIBDIR=		share/${EMACS_NAME}
EMACS_LIBDIR_WITH_VER=	${EMACS_LIBDIR}/${EMACS_VER}

# target name for make build
ALL_TARGET=	elc

PKGNAME=	bitmap-${EMACS_PORT}-${BITMAP_PKG_VER}
EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT} \
		${BITMAP_FONT}:${PORTSDIR}/x11-fonts/bitmap-font
SCRIPTS_ENV=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER}
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		BITMAPDOCDIR=${BITMAPDOCDIR}
MAKE_FLAGS=	EMACS=${EMACS_CMD}

# depends on apel
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}

# depends on flim
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/site-lisp/flim/std11.el:${PORTSDIR}/editors/flim-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/site-lisp/flim/std11.el:${PORTSDIR}/editors/flim-${EMACS_PORT}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${BITMAPDOCDIR}
	@for i in ChangeLog NEWS README.* ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${BITMAPDOCDIR}/ ; \
	done
.endif

.include <bsd.port.mk>
