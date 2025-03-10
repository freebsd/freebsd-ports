PORTNAME=	zathura-djvu
DISTVERSION=	0.2.10
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-djvu/download/

MAINTAINER=	alexander.4mail@gmail.com
COMMENT=	DjVu support for zathura
WWW=		https://pwmt.org/projects/zathura-djvu/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		zathura:graphics/zathura
LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre \
		libgirara-gtk3.so:x11-toolkits/girara
RUN_DEPENDS=	zathura:graphics/zathura

USES=		compiler:c11 desktop-file-utils gnome meson ninja pkgconfig \
		tar:xz

USE_GNOME=	cairo glib20

PLIST_FILES=	lib/zathura/libdjvu.so \
		share/applications/org.pwmt.zathura-djvu.desktop \
		share/metainfo/org.pwmt.zathura-djvu.metainfo.xml

.include <bsd.port.mk>
