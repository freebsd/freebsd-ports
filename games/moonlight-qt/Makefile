PORTNAME=	moonlight
DISTVERSION=	6.1.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	https://github.com/moonlight-stream/moonlight-qt/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-qt
DISTNAME=	MoonlightSrc-${DISTVERSIONFULL}

PATCH_SITES=	https://github.com/moonlight-stream/moonlight-qt/commit/
# fix no <linux/dma-buf.h> for BSDs
PATCHFILES+=	1fd545ae1fea80179d8ac7addfd4cae48554bc63.patch:-p1
# Add fast AES detection for FreeBSD/OpenBSD
PATCHFILES+=	4ec549650dc3f976847e1592f970f36448a3b36f.patch:-p1
# fix compilation with ffmpeg 9
PATCHFILES+=	13880353d8741ae331bf13433c5ad80071d5f44f.patch:-p1 \
		6ce02616f04fb83cd7c5d1492b03367f2220ac46.patch:-p1

MAINTAINER=	lisp_25689@163.com
COMMENT=	Gamestream client
WWW=		https://github.com/moonlight-stream/moonlight-qt

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libdrm.so:graphics/libdrm \
		libopus.so:audio/opus \
		libplacebo.so:graphics/libplacebo \
		libva.so:multimedia/libva \
		libvdpau.so:multimedia/libvdpau \
		libwayland-client.so:graphics/wayland

USES=		desktop-file-utils gl localbase:ldflags pkgconfig \
		qmake:outsource sdl ssl xorg
USE_GL=		egl
USE_SDL=	sdl2 ttf2
USE_XORG=	x11

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/moonlight-qt \
		share/applications/com.moonlight_stream.Moonlight.desktop \
		share/icons/hicolor/scalable/apps/moonlight.svg \
		share/metainfo/com.moonlight_stream.Moonlight.appdata.xml

OPTIONS_DEFAULT=	QT6
OPTIONS_SINGLE=		QT
OPTIONS_SINGLE_QT=	QT5 QT6
QT5_USES=		qt:5
QT5_USE=		QT=core,declarative,gui,network,quickcontrols2,svg,widgets,buildtools:build
# fix errors for qt6.9
QT6_PATCHFILES+=	75359bb1c483ba9e52bba8c34a662d807e0cc3c4.patch:-p1 \
			7a769172a1f62e5198584dff9fd924e8a9e431a0.patch:-p1
QT6_USES=		qt:6
QT6_USE=		QT=base,declarative,svg

post-patch:
	@${REINPLACE_CMD} -e 's@Exec=moonlight.*@Exec=moonlight-qt@' \
		${WRKSRC}/app/deploy/linux/com.moonlight_stream.Moonlight.desktop
	@${REINPLACE_CMD} -e 's@^    TARGET = moonlight.*@    TARGET = moonlight-qt@' \
		${WRKSRC}/app/app.pro

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/moonlight-qt

.include <bsd.port.mk>
