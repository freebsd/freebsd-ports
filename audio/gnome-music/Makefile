PORTNAME=	gnome-music
PORTVERSION=	47.1
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME music playing application
WWW=		https://wiki.gnome.org/Apps/Music

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		grilo-plugins>0:net/grilo-plugins \
		itstool:textproc/itstool
LIB_DEPENDS=	libgoa-1.0.so:net/gnome-online-accounts \
		libgrilo-0.3.so:net/grilo \
		libmediaart-2.0.so:multimedia/libmediaart \
		libtinysparql-3.0.so:devel/tinysparql
RUN_DEPENDS=	grilo-plugins>0:net/grilo-plugins

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gnome gstreamer localbase meson pkgconfig \
		python shebangfix tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo gtk40 libadwaita introspection pygobject3
USE_GSTREAMER=	mpg123 ogg
SHEBANG_FILES=	gnome-music.in
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.Music.gschema.xml

.include <bsd.port.mk>
