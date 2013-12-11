# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-main-menu
PORTVERSION=	0.9.12
PORTREVISION=	8
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides easy access to sets of GNOME applications

LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gnomepanel intlhack eel2 gnomedesktop \
		libgnomeui
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="`pkg-config --libs libgnomeui-2.0`"
CPPFLAGS+=	-I${LOCALBASE}/include `pkg-config --cflags libgnomeui-2.0`
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	application-browser.schemas slab.schemas

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|glib/gmacros.h|glib.h|g' \
		-e 's|glib/gfileutils.h|glib.h|g' \
		-e 's|glib/gtypes.h|glib.h|g' \
		${WRKSRC}/libslab/system-tile.c \
		${WRKSRC}/libslab/application-tile.c \
		${WRKSRC}/main-menu/src/tomboykeybinder.h

.include <bsd.port.mk>
