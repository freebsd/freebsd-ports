# New ports collection makefile for:	kappafont
# Date created:		8 Oct 1998
# Whom: Kawaguti Ginga <ginga@athena.club.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	kappa20
PORTVERSION=	0.3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	ftp://ftp.jaist.ac.jp/pub/misc/character/fonts/kappa/
DISTNAME=	Kappa20-${PORTVERSION}

MAINTAINER=	ginga@athena.club.ne.jp

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
