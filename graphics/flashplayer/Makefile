# New ports collection makefile for:   flashplayer
# Version required:    0.4.3
# Date created:        2 October 1999
# Whom:                Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

DISTNAME=	flash-0.4.3
PKGNAME=	flashplayer-0.4.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.geocities.com/TimesSquare/Labyrinth/5084/flash/Linux/ \
		http://perso.club-internet.fr/odebon/flash/Linux/
EXTRACT_SUFX=	.tgz

PATCH_SITES=   http://leed.t.u-tokyo.ac.jp/~yamagata/flash/
PATCHFILES=    flash-0.4.3-fbsd-19990512.patch

MAINTAINER=	knu@idaemons.org

USE_X_PREFIX=	yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} swfplayer

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} swfplayer ${X11BASE}/bin

.include <bsd.port.mk>
