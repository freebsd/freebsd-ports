# New ports collection makefile for:	kappafont
# Version required:	0.3
# Date created:		8 Oct 1998
# Whom: Kawaguti Ginga <ginga@athena.club.or.jp>
#
# $FreeBSD$
#

DISTNAME=	Kappa20-0.3
PKGNAME=	ja-kappa20-0.3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	ftp://ftp.jaist.ac.jp/pub/misc/character/fonts/kappa/

MAINTAINER=	ginga@athena.club.or.jp

ALL_TARGET=	default
USE_X_PREFIX=	yes
FONTSDIR=	lib/X11/fonts/local
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ARGS=	TARGETDIR="${PREFIX}/${FONTSDIR}"
PLIST_SUB=	FONTSDIR=${FONTSDIR}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

post-install:
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/kappa20
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/kappa20/
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/pcf/fonts.alias.kappa ${PREFIX}/share/doc/kappa20/
.endif

.include <bsd.port.mk>
