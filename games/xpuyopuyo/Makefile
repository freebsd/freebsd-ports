# Created by: Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	xpuyopuyo
PORTVERSION=	0.9.8
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xpuyopuyo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle game, somewhat like Tetris

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome
USES=		gmake libtool
USE_XORG=	xpm
USE_GNOME=	gtk12

OPTIONS_DEFINE=	MIKMOD ROTATE_FIXED AIBREED
ROTATE_FIXED_DESC=	Fix position of one blob during rotation
AIBREED_DESC=	Allow AI breeding

MIKMOD_LIB_DEPENDS=	libmikmod.so:audio/libmikmod
MIKMOD_CONFIGURE_ON=	--with-libmikmod-prefix=${LOCALBASE}

ROTATE_FIXED_CONFIGURE_ENABLE=	rotate-fixed

AIBREED_CONFIGURE_ENABLE=	aibreed

.include <bsd.port.mk>
