# New ports collection makefile for:	bitmap for mule
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bitmap-${EMACS_PORT_NAME}
PORTVERSION=	${BITMAP_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.jpl.org/pub/elisp/bitmap/
DISTNAME=	bitmap-mule-${BITMAP_VER}

MAINTAINER=	shige@FreeBSD.org

# distfile version
BITMAP_VER=	8.3
BITMAPDOCDIR=	share/doc/bitmap
BITMAP_SETUPEL=	bitmap-setupel.el
BITMAP_FONT=	${X11BASE}/lib/X11/fonts/local/etl8x16-bitmap.pcf.gz

# mule-19.34
EMACS_PORT_NAME=	mule

.include <bsd.port.pre.mk>

# target name for make build
ALL_TARGET?=	elc

BUILD_DEPENDS+=	uncompface:${PORTSDIR}/mail/faces
RUN_DEPENDS+=	${BITMAP_FONT}:${PORTSDIR}/x11-fonts/bitmap-font
SCRIPTS_ENV+=	TARGETS=${BITMAP_SETUPEL}
PLIST_SUB+=	BITMAP_SETUPEL=${BITMAP_SETUPEL} \
		BITMAPDOCDIR=${BITMAPDOCDIR}

# depends on apel
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}

pre-configure:
	@${CP} ${FILESDIR}/${BITMAP_SETUPEL}.in ${WRKDIR}

post-install:
	@${INSTALL_DATA} ${WRKDIR}/${BITMAP_SETUPEL} \
		${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${BITMAPDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog NEWS README.* ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${BITMAPDOCDIR}/ ; \
	done)
.endif

.include <bsd.port.post.mk>
