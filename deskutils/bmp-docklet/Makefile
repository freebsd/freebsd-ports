# New ports collection makefile for:	bmp-docklet
# Date created:				10 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmp-docklet
PORTVERSION=	1.3
PORTREVISION=	9
CATEGORIES=	deskutils audio
MASTER_SITES=	http://mark.xnull.de/bmp-docklet/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	novel

MAINTAINER=	novel@FreeBSD.org
COMMENT=	System tray controller for beep-media-player

BUILD_DEPENDS=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player
RUN_DEPENDS=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment"
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
