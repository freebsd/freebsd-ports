# Created by: Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	xpuyopuyo
PORTVERSION=	0.9.8
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xpuyopuyo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle game, somewhat like Tetris

USES=		gmake
USE_XORG=	xpm
USE_AUTOTOOLS=	autoconf213
USE_GNOME=	gtk12
WANT_GNOME=	yes

OPTIONS_DEFINE=	MIKMOD ROTATE_FIXED AIBREED
ROTATE_FIXED_DESC=	Fix position of one blob during rotation
AIBREED_DESC=	Allow AI breeding

CONFIGURE_ARGS+=	--without-gnome

MIKMOD_LIB_DEPENDS=	libmikmod.so:${PORTSDIR}/audio/libmikmod
MIKMOD_CONFIGURE_ON=	--with-libmikmod-prefix=${LOCALBASE}

ROTATE_FIXED_CONFIGURE_ENABLE=	rotate-fixed

AIBREED_CONFIGURE_ENABLE=	aibreed

.include <bsd.port.mk>
