# New ports collection makefile for:	xgalaga
# Date created:		27 August 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	xgalaga
PORTVERSION=	2.0.34
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://people.FreeBSD.org/~linimon/public_distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Galaga resurrected on X

USE_XORG=	xpm xmu
HAS_CONFIGURE=	yes
# xgalaga has a very strange usage of these variables...
CONFIGURE_ARGS=	--prefix=${LOCALBASE}/lib/X11/xgalaga \
		--exec_prefix=${LOCALBASE}/bin

.if defined(NOSOUND)
CONFIGURE_ARGS+=	--without-sound
PLIST_SUB=	SOUND="@comment "
.else
PLIST_SUB=	SOUND=""
pre-configure:
	@${ECHO_CMD} "*****************************************************"
	@${ECHO_CMD} "* Note that you can build a version of xgalaga that *"
	@${ECHO_CMD} "* doesn't use the sound driver by typing            *"
	@${ECHO_CMD} "* \"make -DNOSOUND\"                                  *"
	@${ECHO_CMD} "* following a \"make clean\".                         *"
	@${ECHO_CMD} "* Try it if you don't have a sound card and are     *"
	@${ECHO_CMD} "* getting core dumps.                               *"
	@${ECHO_CMD} "*****************************************************"
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/xgalaga

.include <bsd.port.mk>
