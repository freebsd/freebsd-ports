# New ports collection makefile for:	elisafont
# Date created:		26 Sep 1997
# Whom: Dai ISHIJIMA & ELISA Font Project <ishijima@tri.pref.osaka.jp>
#
# $FreeBSD$
#

PORTNAME=	elisa10x8
PORTVERSION=	1.0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	ftp://ftp.tut.ac.jp/X11/Fonts/ \
		ftp://ftp.iij.ad.jp/pub/X/X11R6.3/%SUBDIR%/ \
		ftp://ftp.eu.net/X11/R6.3/%SUBDIR%/
MASTER_SITE_SUBDIR=	xc/fonts/bdf/misc
DISTFILES=	elisau10.tgz \
		clR5x8.bdf
EXTRACT_ONLY=	elisau10.tgz

MAINTAINER=	ishijima@tri.pref.osaka.jp
COMMENT=	X11 8-dot kanji font 'elisa font'

RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

NO_WRKSUBDIR=	yes

FONTSDIR=	lib/X11/fonts/local
MAKE_ENV=	DISTDIR=${DISTDIR} FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

post-install:
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/elisa8
	@${CP} ${WRKSRC}/elisa100.doc ${PREFIX}/share/doc/elisa8/
	@${CP} ${WRKSRC}/elisau10.doc ${PREFIX}/share/doc/elisa8/
	@${CP} ${WRKSRC}/hosoku.txt ${PREFIX}/share/doc/elisa8/
.endif

.include <bsd.port.post.mk>
