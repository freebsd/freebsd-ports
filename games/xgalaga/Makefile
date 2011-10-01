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

MAINTAINER=	turutani@scphys.kyoto-u.ac.jp
COMMENT=	Galaga resurrected on X

USE_XORG=	xpm xmu
HAS_CONFIGURE=	yes
# xgalaga has a very strange usage of these variables...
CONFIGURE_ARGS=	--prefix=${LOCALBASE}/lib/X11/xgalaga \
		--exec_prefix=${LOCALBASE}/bin

OPTIONS=	SOUND	"Sound support"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SOUND) && !defined(NOSOUND)
CONFIGURE_ARGS+=	--without-sound
PLIST_SUB=	SOUND="@comment "
.else
PLIST_SUB=	SOUND=""
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/xgalaga

.include <bsd.port.post.mk>
