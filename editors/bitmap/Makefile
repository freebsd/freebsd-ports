# New ports collection makefile for:	bitmap for emacs21
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitmap
PORTVERSION=	${BITMAP_VER}
PORTREVISION=	8
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.jpl.org/pub/elisp/bitmap/ \
		ftp://ftp.jpl.org/pub/elisp/bitmap/snapshots/
DISTNAME=	bitmap-mule-${BITMAP_DISTVER}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Bitmap-mule, Package to use bitmap in Emacs

# ports version
BITMAP_VER=		${BITMAP_MVER}${BITMAP_SNAP_PREFIX}${BITMAP_SNAP}
# distfile version
BITMAP_MVER=		8.5
BITMAP_DISTVER=		${BITMAP_MVER}
# variables for snapshots version
###BITMAP_SNAP_PREFIX=	.p
###BITMAP_SNAP=		200109201221
###BITMAP_DISTVER=		${BITMAP_SNAP}

BITMAPDOCDIR=	share/doc/bitmap
BITMAP_SETUPEL=	bitmap-setupel.el
BITMAP_FONT=	${LOCALBASE}/lib/X11/fonts/local/bitmap16.pcf.gz

# bitmap install lispdir
BITMAP_LISPDIR?=		${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}
BITMAP_VERSION_SPECIFIC_LISPDIR?=${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}

# This is MASTER port.
PORTCLASS?=	master

# Setup EMACS_PORT_NAME variable.
.if (${PORTCLASS} == "master")
USE_EMACS=	yes
DEPPORT_SUFFIX=
.else
DEPPORT_SUFFIX=		-${EMACS_PORT_NAME}
.endif

EMACS_MASTERDIR_PKGFILES=	YES

# target name for make build
ALL_TARGET=	elc

BUILD_DEPENDS=	uncompface:${PORTSDIR}/mail/faces
RUN_DEPENDS=	${BITMAP_FONT}:${PORTSDIR}/x11-fonts/bitmap-fonts
PLIST_SUB=	BITMAPDOCDIR=${BITMAPDOCDIR} \
		BITMAP_SETUPEL=${BITMAP_SETUPEL}
SCRIPTS_ENV=	TARGETS=${BITMAP_SETUPEL}
MAKE_ARGS=	PREFIX="${LOCALBASE}" \
		LISPDIR="${BITMAP_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${BITMAP_VERSION_SPECIFIC_LISPDIR}"

.include <bsd.port.pre.mk>

.if defined(EMACS_PORT_NAME)
# depends on apel
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel${DEPPORT_SUFFIX}
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel${DEPPORT_SUFFIX}
.if (${EMACS_PORT_NAME} == "emacs21") || (${EMACS_PORT_NAME} == "emacs22") || (${EMACS_PORT_NAME} == "emacs-devel")
DESCR=		${PKGDIR}/pkg-descr.emacs21
PLIST=		${PKGDIR}/pkg-plist.emacs21
.endif
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_PORT_NAME."
	@${FALSE}
.endif

pre-configure:
.if defined(EMACS_NO_SUBDIRSEL) && (${EMACS_NO_SUBDIRSEL} == "YES")
	@${CP} ${FILESDIR}/${BITMAP_SETUPEL}.in ${WRKDIR}
.endif

post-install:
.if defined(EMACS_NO_SUBDIRSEL) && (${EMACS_NO_SUBDIRSEL} == "YES")
	@${INSTALL_DATA} ${WRKDIR}/${BITMAP_SETUPEL} \
		${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/${BITMAP_SETUPEL}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${LOCALBASE}/${BITMAPDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog NEWS README.* ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${LOCALBASE}/${BITMAPDOCDIR}/ ; \
	done)
.endif

.include <bsd.port.post.mk>
