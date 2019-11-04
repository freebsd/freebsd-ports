# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	wininfo
PORTVERSION=	0.7
PORTREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	http://www.freedesktop.org/software/wininfo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window information utility

USES=		gnome pkgconfig xorg
USE_XORG=	xext xrender xinerama xrandr xi xfixes xcursor \
		xcomposite x11 xres
USE_GNOME=	gtk20 gnomeprefix
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
