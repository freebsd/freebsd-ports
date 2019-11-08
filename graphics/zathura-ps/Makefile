# $FreeBSD$

PORTNAME=	zathura-ps
PORTVERSION=	0.2.6
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/zathura-ps/download/ \
		http://www.madpilot.net/~mad/pwmt.org/

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	PostScript support for Zathura PDF viewer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libspectre.so:print/libspectre
BUILD_DEPENDS=	zathura:graphics/zathura
RUN_DEPENDS=	zathura:graphics/zathura

USES=		compiler:c11 desktop-file-utils gnome meson ninja pkgconfig ssl \
		tar:xz
USE_GNOME=	glib20 gtk30

PLIST_FILES=	lib/zathura/libps.so \
		share/applications/org.pwmt.zathura-ps.desktop \
		share/appdata/org.pwmt.zathura-ps.metainfo.xml

pre-configure:
	${REINPLACE_CMD} "s:join_paths(datadir, 'metainfo'):join_paths(datadir, 'appdata'):" ${WRKSRC}/meson.build

post-install:
	@${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/zathura/libps.so

.include <bsd.port.mk>
