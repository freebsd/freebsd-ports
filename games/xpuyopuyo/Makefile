# New ports collection makefile for:	xpuyopuyo
# Date created:		19 Sep 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xpuyopuyo
PORTVERSION=	0.9.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xpuyopuyo/

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A puzzle game, somewhat like Tetris

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_AUTOCONF_VER=	213
USE_GNOME=	gtk12
WANT_GNOME=	yes

MAN6=		xpuyopuyo.6

OPTIONS=	MIKMOD "libmikmod support" off \
		ROTATE_FIXED "Fix position of one blob during rotation"	off \
		AIBREED "Allow AI breeding" off

.include <bsd.port.pre.mk>

.if defined(WITH_MIKMOD) || exists(${LOCALBASE}/lib/libmikmod.a)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
CONFIGURE_ARGS+=--with-libmikmod-prefix=${LOCALBASE}
.endif

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomelibs gnomehack
PKGNAMESUFFIX=	-gnome
PLIST_SUB+=	DATADIR="share/gnome"
.else
CONFIGURE_ARGS+=	--without-gnome
PLIST_SUB+=	DATADIR="share"
.endif

.if defined(WITH_ROTATE_FIXED)
CONFIGURE_ARGS+=--enable-rotate-fixed
.endif
.if defined(WITH_AIBREED)
CONFIGURE_ARGS+=--enable-aibreed
.endif

.include <bsd.port.post.mk>
