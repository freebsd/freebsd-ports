PORTNAME=	moonlight
DISTVERSION=	6.2.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://github.com/moonlight-stream/moonlight-qt/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-qt
DISTNAME=	MoonlightSrc-${DISTVERSIONFULL}

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
		qmake:outsource qt:6 sdl ssl xorg
USE_GL=		egl
USE_QT=		base declarative svg
USE_SDL=	sdl2 ttf2
USE_XORG=	x11

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/moonlight-qt \
		share/applications/com.moonlight_stream.Moonlight.desktop \
		share/icons/hicolor/scalable/apps/moonlight.svg \
		share/metainfo/com.moonlight_stream.Moonlight.appdata.xml

post-patch:
	@${REINPLACE_CMD} -e 's@Exec=moonlight.*@Exec=moonlight-qt@' \
		${WRKSRC}/app/deploy/linux/com.moonlight_stream.Moonlight.desktop
	@${REINPLACE_CMD} -e 's@^    TARGET = moonlight.*@    TARGET = moonlight-qt@' \
		${WRKSRC}/app/app.pro

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/moonlight-qt

.include <bsd.port.mk>
