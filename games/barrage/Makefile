# New ports collection makefile for:  	barrage
# Date created:       	23 April 2003
# Whom:  	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	barrage
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}/1.0
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Destroy as many targets as possible

USE_GMAKE=	yes
USE_SDL=	sdl mixer
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-profile-path=/var/games

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

post-patch:
	@${REINPLACE_CMD} -e 's|applications|applnk/Applications|g' \
		${WRKSRC}/Makefile.in

post-install:
	${CHMOD} 0755 ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
