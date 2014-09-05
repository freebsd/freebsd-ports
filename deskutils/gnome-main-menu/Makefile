# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-main-menu
PORTVERSION=	0.9.12
PORTREVISION=	9
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides easy access to sets of GNOME applications

LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop

USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix gnomepanel intlhack eel2 gnomedesktop libgnomeui
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	application-browser.schemas slab.schemas

post-patch:
	${REINPLACE_CMD} -e 's|glib/gmacros.h|glib.h|g' \
		-e 's|glib/gfileutils.h|glib.h|g' \
		-e 's|glib/gtypes.h|glib.h|g' \
		${WRKSRC}/libslab/system-tile.c \
		${WRKSRC}/libslab/application-tile.c \
		${WRKSRC}/main-menu/src/tomboykeybinder.h

.include <bsd.port.mk>
