# New ports collection makefile for:	bitmap for mule
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitmap
PORTVERSION=	${BITMAP_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.jpl.org/pub/elisp/bitmap/
DISTNAME=	${PORTNAME}-mule-${BITMAP_VER}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	shige@FreeBSD.org

# distfile version
BITMAP_VER=	8.3
BITMAPDOCDIR=	share/doc/bitmap
BITMAP_SETUPEL=	bitmap-setupel.el
BITMAP_FONT=	${X11BASE}/lib/X11/fonts/local/etl8x16-bitmap.pcf.gz

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
