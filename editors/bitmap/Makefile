# New ports collection makefile for:	bitmap for emacs20
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitmap
PORTVERSION=	${BITMAP_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.jpl.org/pub/elisp/bitmap/ \
		ftp://ftp.jpl.org/pub/elisp/bitmap/snapshots/
DISTNAME=	bitmap-mule-${BITMAP_DISTVER}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	shige@FreeBSD.org

# ports version
BITMAP_VER=		${BITMAP_MVER}${BITMAP_SNAP_PREFIX}${BITMAP_SNAP}
# distfile version
BITMAP_MVER=		8.4
BITMAP_DISTVER=		${BITMAP_MVER}
# variables for snapshots version
BITMAP_SNAP_PREFIX=	.p
BITMAP_SNAP=		200102280240
BITMAP_DISTVER=		${BITMAP_SNAP}

BITMAPDOCDIR=	share/doc/bitmap
BITMAP_FONT=	${X11BASE}/lib/X11/fonts/local/bitmap16.pcf.gz

# emacs20
EMACS_PORT_NAME=	emacs20

# target name for make build
ALL_TARGET=	elc

BUILD_DEPENDS=	uncompface:${PORTSDIR}/mail/faces
RUN_DEPENDS=	${BITMAP_FONT}:${PORTSDIR}/x11-fonts/bitmap-fonts
PLIST_SUB=	BITMAPDOCDIR=${BITMAPDOCDIR}

.include <bsd.port.pre.mk>

.if defined(EMACS_PORT_NAME)
# depends on apel
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_PORT_NAME."
	@${FALSE}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${LOCALBASE}/${BITMAPDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog NEWS README.* ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${LOCALBASE}/${BITMAPDOCDIR}/ ; \
	done)
.endif

.include <bsd.port.post.mk>
