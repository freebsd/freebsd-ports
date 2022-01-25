PORTNAME=	vulkan-caps-viewer
DISTVERSION=	3.1
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
GH_TUPLE=	KhronosGroup:Vulkan-Headers:v1.3.204:vkheaders/Vulkan-Headers
LDFLAGS+=	-Wl,--as-needed # avoid overlinking (GL, wayland)
PLIST_FILES=	bin/vulkanCapsViewer \
		share/applications/vulkanCapsViewer.desktop \
		share/icons/hicolor/256x256/apps/vulkanCapsViewer.png

OPTIONS_DEFINE=	WAYLAND X11
OPTIONS_DEFAULT=WAYLAND X11

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_USE=		QT=wayland_build
WAYLAND_QMAKE_ON=	DEFINES+=WAYLAND

X11_USE=		QT=x11extras
X11_QMAKE_ON=		DEFINES+=X11

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

.include <bsd.port.mk>
