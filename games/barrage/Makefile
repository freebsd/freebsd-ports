# New ports collection makefile for:  	barrage
# Date created:       	23 April 2003
# Whom:  	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	barrage
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lgames
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Destroy as many targets as possible

USE_SIZE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-profile-path=/var/games
USE_REINPLACE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include"

post-patch:
	@${REINPLACE_CMD} -e 's|applications|applnk/Applications|g' \
		${WRKSRC}/Makefile.in

post-install:
	${CHMOD} 0755 ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
