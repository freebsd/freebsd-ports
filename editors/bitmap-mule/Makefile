# New ports collection makefile for:	bitmap for mule
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
DISTNAME=	${PORTNAME}-mule-${BITMAP_DISTVER}
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
BITMAP_SETUPEL=	bitmap-setupel.el
BITMAP_FONT=	${X11BASE}/lib/X11/fonts/local/bitmap16.pcf.gz

# mule-19.34
EMACS_PORT_NAME=	mule


# target name for make build
ALL_TARGET?=	elc

BUILD_DEPENDS=	uncompface:${PORTSDIR}/mail/faces
RUN_DEPENDS=	${BITMAP_FONT}:${PORTSDIR}/x11-fonts/bitmap-fonts
SCRIPTS_ENV=	TARGETS=${BITMAP_SETUPEL}
PLIST_SUB=	BITMAP_SETUPEL=${BITMAP_SETUPEL} \
		BITMAPDOCDIR=${BITMAPDOCDIR}

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

pre-configure:
	@${CP} ${FILESDIR}/${BITMAP_SETUPEL}.in ${WRKDIR}

post-install:
	@${INSTALL_DATA} ${WRKDIR}/${BITMAP_SETUPEL} \
		${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp
.if !defined(NOPORTDOCS)
	@${MKDIR} ${LOCALBASE}/${BITMAPDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog NEWS README.* ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${LOCALBASE}/${BITMAPDOCDIR}/ ; \
	done)
.endif

.include <bsd.port.post.mk>
