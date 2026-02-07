PORTNAME=	mangohud
PORTVERSION=	0.6.5
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	benchmarks graphics
MASTER_SITES=	https://wrapdb.mesonbuild.com/v1/projects/imgui/1.81/1/get_zip?dummy=/:igw
DISTFILES=	imgui-1.81-1-wrap.zip:igw

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Vulkan/OpenGL overlay for CPU/GPU monitoring
WWW=		https://github.com/flightlessmango/MangoHud

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		https://github.com/flightlessmango/MangoHud/issues/927

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		${LOCALBASE}/share/vulkan/registry/vk.xml:graphics/vulkan-headers \
		${PYTHON_PKGNAMEPREFIX}mako>=0:textproc/py-mako@${PY_FLAVOR}
LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		compiler:c++14-lang meson pkgconfig python:build xorg
USE_GITHUB=	yes
GH_ACCOUNT=	flightlessmango ocornut:ig
GH_PROJECT=	MangoHud imgui:ig
GH_TAGNAME=	v1.81:ig
GH_SUBDIR=	subprojects/imgui-1.81:ig
USE_XORG=	x11
MESON_ARGS=	-Duse_system_vulkan=enabled -Dwith_xnvctrl=disabled

CPPFLAGS+=	-DPROCDIR=\\\"${LINUXBASE}/proc\\\"

PLIST_FILES=	bin/mangohud lib/mangohud/libMangoHud.so \
		lib/mangohud/libMangoHud_dlsym.so share/man/man1/mangohud.1.gz \
		share/vulkan/implicit_layer.d/MangoHud.json
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
	@${REINPLACE_CMD} -e 's,libdl\.so,ld-elf.so,' \
		${WRKSRC}/src/real_dlsym.cpp
	@${REINPLACE_CMD} -e 's,def __gnu_linux__,ndef _WIN32,' \
		${WRKSRC}/src/logging.cpp

.include <bsd.port.mk>
