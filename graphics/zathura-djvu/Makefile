PORTNAME=	zathura-djvu
DISTVERSION=	0.2.11
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-djvu/download/

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	DjVu support for Zathura PDF viewer
WWW=		https://pwmt.org/projects/zathura-djvu/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	appstreamcli:devel/appstream \
		zathura:graphics/zathura
LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre \
		libgirara-gtk3.so:x11-toolkits/girara
RUN_DEPENDS=	zathura:graphics/zathura

USES=		compiler:c17 desktop-file-utils gnome meson pkgconfig tar:xz

USE_GNOME=	cairo glib20

PLIST_FILES=	lib/zathura/libdjvu.so \
		share/applications/org.pwmt.zathura-djvu.desktop \
		share/metainfo/org.pwmt.zathura-djvu.metainfo.xml

.include <bsd.port.mk>
