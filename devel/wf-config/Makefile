PORTNAME=	wf-config
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for managing configuration files, written for wayfire
WWW=		https://wayfire.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols \
		glm>0:math/glm
LIB_DEPENDS=	libevdev.so:devel/libevdev
RUN_DEPENDS=	glm>0:math/glm
TEST_DEPENDS=	doctest>0:devel/doctest

USES=		cmake:indirect compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
GH_ACCOUNT=	WayfireWM
MESON_ARGS=	-Dtests=disabled
PLIST_SUB=	VERSION=${PORTVERSION}

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dtests=enabled"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
