# New ports collection makefile for:	elisafont
# Version required:	1.0
# Date created:		26 Sep 1997
# Whom: Dai ISHIJIMA & ELISA Font Project <ishijima@tri.pref.osaka.jp>
#
# $FreeBSD$
#

DISTNAME=	ja-elisa8-1.0
PKGNAME=	ja-elisa10x8-1.0
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	ftp://ftp.tut.ac.jp/X11/Fonts/ \
		ftp://ftp.iij.ad.jp/pub/X/X11R6.3/%SUBDIR%/ \
		ftp://ftp.eu.net/X11/R6.3/%SUBDIR%/
MASTER_SITE_SUBDIR=	xc/fonts/bdf/misc
DISTFILES=	elisau10.tgz clR5x8.bdf

MAINTAINER=	ishijima@tri.pref.osaka.jp

USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes
EXTRACT_ONLY=	elisau10.tgz

FONTSDIR=	lib/X11/fonts/local
MAKE_ENV=	DISTDIR=${DISTDIR} FONTSDIR=${FONTSDIR}
PLIST_SUB=	FONTSDIR=${FONTSDIR}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

post-install:
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/elisa8
	@${CP} ${WRKSRC}/elisa100.doc ${PREFIX}/share/doc/elisa8/
	@${CP} ${WRKSRC}/elisau10.doc ${PREFIX}/share/doc/elisa8/
	@${CP} ${WRKSRC}/hosoku.txt ${PREFIX}/share/doc/elisa8/
.endif

.include <bsd.port.mk>
