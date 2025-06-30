PORTNAME=	gnome-planner
PORTVERSION=	0.14.6.20220531
PORTREVISION=	3
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Project management tool based on the Work breakdown structure
WWW=		https://wiki.gnome.org/Apps/Planner

LICENSE=	GPLv3

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		itstool>0:textproc/itstool
LIB_DEPENDS=	libgoa-1.0.so:net/gnome-online-accounts \
		libgraphene-1.0.so:graphics/graphene \
		libical.so:devel/libical \
		libpeas-1.0.so:devel/libpeas1 \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libgda-5.0.so:databases/libgda5

USES=	desktop-file-utils gettext pathfix \
		shared-mime-info tar:xz meson pkgconfig
USE_GNOME=	gnomeprefix intlhack libgnomeui libgnomeprintui \
		libgsf
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	planner
GL_TAGNAME=	88e86815960a9f66e6f512d4d38d5119ffee3b90
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include -DGLIB_COMPILATION
LIBS+=		-L${LOCALBASE}/lib

GLIB_SCHEMAS=	planner.gschema

.include <bsd.port.mk>
