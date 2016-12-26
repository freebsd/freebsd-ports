# Created by: Vincent Tantardini <vinc@freebsd-fr.org>
# $FreeBSD$

PORTNAME=	hsetroot
PORTVERSION=	1.0.2
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	http://cdn.thegraveyard.org/releases/hsetroot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wallpaper manipulation utility for X11

LICENSE=	GPLv2

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

BROKEN=		unfetchable (apparently abandoned upstream)

GNU_CONFIGURE=	yes
USES=		gmake
USE_XORG=	x11
LDFLAGS+=	-L${LOCALBASE}/lib -lX11

PLIST_FILES=	bin/hsetroot

.include <bsd.port.mk>
