# New ports collection makefile for:   flashplayer
# Date created:        2 October 1999
# Whom:                Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	flashplayer
PORTVERSION=	0.4.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.geocities.com/TimesSquare/Labyrinth/5084/flash/Linux/ \
		http://perso.club-internet.fr/odebon/flash/Linux/
DISTNAME=	flash-${PORTVERSION}
EXTRACT_SUFX=	.tgz

PATCH_SITES=   http://leed.t.u-tokyo.ac.jp/~yamagata/flash/
PATCHFILES=    flash-0.4.3-fbsd-19990512.patch

MAINTAINER=	knu@FreeBSD.org

USE_X_PREFIX=	yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} swfplayer

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} swfplayer ${X11BASE}/bin

.include <bsd.port.mk>
