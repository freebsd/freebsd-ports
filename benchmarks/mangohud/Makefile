# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mangohud
PORTVERSION=	0.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	benchmarks graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	cec98369ae34d910476b78f98adece96016ab603.diff:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Vulkan/OpenGL overlay for CPU/GPU monitoring

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glslangValidator:devel/glslang \
		${LOCALBASE}/share/vulkan/registry/vk.xml:devel/vulkan-headers \
		${PYTHON_PKGNAMEPREFIX}mako>=0:textproc/py-mako@${PY_FLAVOR}
LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		compiler:c++14-lang meson pkgconfig python:build xorg
USE_GITHUB=	yes
GH_ACCOUNT=	flightlessmango
GH_PROJECT=	MangoHud
USE_XORG=	x11
MESON_ARGS=	-Duse_system_vulkan=enabled -Dwith_xnvctrl=disabled

PLIST_FILES=	bin/mangohud lib/mangohud/libMangoHud.so \
		lib/mangohud/libMangoHud_dlsym.so man/man1/mangohud.1.gz \
		share/vulkan/implicit_layer.d/MangoHud.json
PORTEXAMPLES=	MangoHud.conf.example

OPTIONS_DEFINE=	DBUS EXAMPLES
OPTIONS_DEFAULT=	DBUS

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MESON_OFF=	-Dwith_dbus=disabled

post-patch:
	@${REINPLACE_CMD} -e '/version : /s,0\.4\.0,${PORTVERSION}, ; \
		/^prog_python = /s,3,${PYTHON_VER},' ${WRKSRC}/meson.build
	@${REINPLACE_CMD} -e '1s,usr/bin/env ba,bin/,' \
		${WRKSRC}/bin/mangohud.in
	@${REINPLACE_CMD} -e 's,/usr/share/doc,${PREFIX}/share/examples,' \
		${WRKSRC}/data/mangohud.1
	@${REINPLACE_CMD} -e '/#include <sys\/sysinfo\.h>/d' \
		${WRKSRC}/src/overlay_params.cpp
	@${REINPLACE_CMD} -e 's,libdl\.so,ld-elf.so,' \
		${WRKSRC}/src/real_dlsym.cpp

.include <bsd.port.mk>
