# New ports collection makefile for:	xgalaga
# Version required:	2.0
# Date created:		27 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.6 1997/12/25 22:29:20 asami Exp $
#

DISTNAME=	xgalaga-2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

HAS_CONFIGURE=	yes
USE_X11=	yes
# xgalaga has a very strange usage of these variables...
CONFIGURE_ARGS=	--prefix=${X11BASE}/lib/X11/xgalaga \
		--exec_prefix=${X11BASE}/bin

.if defined(NOSOUND)
CONFIGURE_ARGS+=	--without-sound
.endif

pre-configure:
	@${ECHO} "*****************************************************"
	@${ECHO} "* Note that you can build a version of xgalaga that *"
	@${ECHO} "* doesn't use the sound driver by typing            *"
	@${ECHO} "* \"make -DNOSOUND\"                                  *"
	@${ECHO} "* following a \"make clean\".                         *"
	@${ECHO} "* Try it if you don't have a sound card and are     *"
	@${ECHO} "* getting core dumps.                               *"
	@${ECHO} "*****************************************************"

.include <bsd.port.mk>
