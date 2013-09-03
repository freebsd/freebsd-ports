# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bmp-docklet
PORTVERSION=	1.3
PORTREVISION=	10
CATEGORIES=	deskutils audio
MASTER_SITES=	http://mark.xnull.de/bmp-docklet/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	novel

MAINTAINER=	novel@FreeBSD.org
COMMENT=	System tray controller for beep-media-player

BUILD_DEPENDS=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player
RUN_DEPENDS=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GNOME=	gnomehack intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment"
.endif

.include <bsd.port.mk>
