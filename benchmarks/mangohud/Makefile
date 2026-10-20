PORTNAME=	mangohud
PORTVERSION=	0.6.9
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks graphics
MASTER_SITES=	https://wrapdb.mesonbuild.com/v1/projects/imgui/1.81/1/get_zip?dummy=/:igw \
		https://wrapdb.mesonbuild.com/v1/projects/vulkan-headers/1.2.158/2/get_zip?dummy=/:vhw
DISTFILES=	imgui-1.81-1-wrap.zip:igw vulkan-headers-1.2.158-2-wrap.zip:vhw

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Vulkan/OpenGL overlay for CPU/GPU monitoring
WWW=		https://github.com/flightlessmango/MangoHud

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/nlohmann/json.hpp:devel/nlohmann-json \
		glslangValidator:graphics/glslang \
		${PYTHON_PKGNAMEPREFIX}mako>=0:textproc/py-mako@${PY_FLAVOR}
LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libspdlog.so:devel/spdlog

USES=		compiler:c++14-lang meson pkgconfig python:build xorg
USE_GITHUB=	yes
GH_ACCOUNT=	flightlessmango ocornut:ig KhronosGroup:vh
GH_PROJECT=	MangoHud imgui:ig Vulkan-Headers:vh
GH_TAGNAME=	v1.81:ig v1.2.158:vh
GH_SUBDIR=	subprojects/imgui-1.81:ig
GH_SUBDIR+=	subprojects/Vulkan-Headers-1.2.158:vh
USE_XORG=	x11
MESON_ARGS=	-Duse_system_spdlog=enabled -Dwith_xnvctrl=disabled -Dtests=disabled

CPPFLAGS+=	-DPROCDIR=\\\"${LINUXBASE}/proc\\\"

PLIST_FILES=	bin/mangohud lib/mangohud/libMangoHud.so \
		lib/mangohud/libMangoHud_dlsym.so share/man/man1/mangohud.1.gz \
		share/icons/hicolor/scalable/apps/io.github.flightlessmango.mangohud.svg \
		share/metainfo/io.github.flightlessmango.mangohud.metainfo.xml \
		share/vulkan/implicit_layer.d/MangoHud.${ARCH:S/amd64/x86_64/:S/i386/x86/}.json
PORTEXAMPLES=	MangoHud.conf.example

OPTIONS_DEFINE=	DBUS EXAMPLES
OPTIONS_DEFAULT=	DBUS

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MESON_OFF=	-Dwith_dbus=disabled

post-patch:
	@${REINPLACE_CMD} -e 's,cygwin,${OPSYS:tl}, ; \
		/^prog_python = /s,3,${PYTHON_VER},' ${WRKSRC}/meson.build
	@${REINPLACE_CMD} -e 's,/usr/share/doc,${PREFIX}/share/examples,' \
		${WRKSRC}/data/mangohud.1
	@${REINPLACE_CMD} -e 's,def __linux__,ndef _WIN32,' \
		${WRKSRC}/src/overlay_params.cpp

.include <bsd.port.mk>
