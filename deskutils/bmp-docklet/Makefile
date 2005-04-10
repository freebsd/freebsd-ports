# New ports collection makefile for:	bmp-docklet
# Date created:				10 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmp-docklet
PORTVERSION=	1.1
CATEGORIES=	deskutils audio
MASTER_SITES=	http://mark.xnull.de/bmp-docklet/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System tray controller for beep-media-player

BUILD_DEPENDS=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_X_PREFIX=	yes

USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_GNOME=	gnomehack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
