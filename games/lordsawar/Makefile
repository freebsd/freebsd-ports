# New ports collection makefile for:   lordsawar
# Date created:                 12 February 2008
# Whom:                         spam@rm-rf.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	lordsawar
PORTVERSION=	0.0.9
CATEGORIES=	games
MASTER_SITES=	http://lordsawar.com/

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	A Warlords II clone

LIB_DEPENDS=	glademm-2.4:${PORTSDIR}/devel/libglademm24 \
		gnet-2.0:${PORTSDIR}/net/gnet2

USE_GZIP=	yes
USE_GETTEXT=	yes
USE_SDL=	sdl image

OPTIONS=	SOUND	"Enable sound"	on

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=--disable-nls

.if !defined(WITHOUT_SOUND)
USE_SDL+=	mixer
.else
CONFIGURE_ARGS+=--disable-sound
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.post.mk>
