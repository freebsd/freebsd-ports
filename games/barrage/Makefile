# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	barrage
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Destroy as many targets as possible

USE_SDL=	sdl mixer
USES=		gmake
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-profile-path=/var/games

post-patch:
	@${REINPLACE_CMD} -e 's|/games/|/|g' ${WRKSRC}/configure

.include <bsd.port.mk>
