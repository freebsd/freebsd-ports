# New ports collection makefile for:	xgalaga
# Date created:		27 August 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	xgalaga
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=	ports@FreeBSD.org

HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
# xgalaga has a very strange usage of these variables...
CONFIGURE_ARGS=	--prefix=${X11BASE}/lib/X11/xgalaga \
		--exec_prefix=${X11BASE}/bin

.if defined(NOSOUND)
CONFIGURE_ARGS+=	--without-sound
PLIST=			${PKGDIR}/pkg-plist.nosound
.else
pre-configure:
	@${ECHO} "*****************************************************"
	@${ECHO} "* Note that you can build a version of xgalaga that *"
	@${ECHO} "* doesn't use the sound driver by typing            *"
	@${ECHO} "* \"make -DNOSOUND\"                                  *"
	@${ECHO} "* following a \"make clean\".                         *"
	@${ECHO} "* Try it if you don't have a sound card and are     *"
	@${ECHO} "* getting core dumps.                               *"
	@${ECHO} "*****************************************************"
.endif

.include <bsd.port.mk>
