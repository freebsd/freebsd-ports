PORTNAME=	zathura-cb
DISTVERSION=	0.1.12
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-cb/download/

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Comic book plugin for Zathura PDF viewer
WWW=		https://pwmt.org/projects/zathura-cb/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	appstreamcli:devel/appstream \
		zathura:graphics/zathura
LIB_DEPENDS=	libgirara-gtk3.so:x11-toolkits/girara
RUN_DEPENDS=	zathura:graphics/zathura

USES=		compiler:c17 desktop-file-utils gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 gtk30

PLIST_FILES=	lib/zathura/libcb.so \
		share/applications/org.pwmt.zathura-cb.desktop \
		share/metainfo/org.pwmt.zathura-cb.metainfo.xml

.include <bsd.port.mk>
