# $FreeBSD$

PORTNAME=	vulkan-caps-viewer
DISTVERSION=	2.21
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Vulkan Hardware Capability Viewer

LICENSE=	LGPL3 # based on license headers

LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

USES=		compiler:c++11-lib pkgconfig qmake qt:5
USE_GITHUB=	yes
USE_QT=		qmake_build buildtools_build core gui network widgets
GH_ACCOUNT=	SaschaWillems
GH_PROJECT=	VulkanCapsViewer
GH_TUPLE=	KhronosGroup:Vulkan-Headers:v1.2.154:vkheaders/Vulkan-Headers
LDFLAGS+=	-Wl,--as-needed # avoid overlinking (GL, wayland)
PLIST_FILES=	bin/vulkanCapsViewer \
		share/applications/vulkanCapsViewer.desktop \
		share/icons/hicolor/256x256/apps/vulkanCapsViewer.png

OPTIONS_DEFINE=	WAYLAND X11
OPTIONS_DEFAULT=WAYLAND X11

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_USE=		QT=wayland_build

X11_USE=		QT=x11extras

post-patch:
# Hint qmake how to install generated file
	@${CP} ${WRKSRC}/gfx/android_icon_256.png \
		${WRKSRC}/vulkanCapsViewer.png
# Avoid platform whitelists for generic non-Windows code
	@${REINPLACE_CMD} -Ee 's/linux/unix/' \
		-e '/bin|share/s,/usr,$$$$PREFIX,' \
		${WRKSRC}/vulkanCapsViewer.pro
	@${REINPLACE_CMD} -e 's/__linux/__unix/' \
		${WRKSRC}/vulkancapsviewer.cpp \
		${WRKSRC}/Vulkan-Headers/include/vulkan/vulkan.hpp

post-patch-WAYLAND-off:
	@${REINPLACE_CMD} -i .nowayland '/qtHave/s/wayland/DISABLED&/' \
		${WRKSRC}/vulkanCapsViewer.pro

post-patch-X11-off:
	@${REINPLACE_CMD} -i .nox11 '/qtHave/s/x11/DISABLED&/' \
		${WRKSRC}/vulkanCapsViewer.pro

.include <bsd.port.mk>
