PORTNAME=	wayland
DISTVERSION=	1.24.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://gitlab.freedesktop.org/${PORTNAME}/${PORTNAME}/-/releases/${DISTVERSION}/downloads/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Core Wayland window system code and protocol
WWW=		https://wayland.freedesktop.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libepoll-shim.so:devel/libepoll-shim

USES=		cpe gnome meson pkgconfig tar:xz
USE_GNOME=	libxslt:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddocumentation=false

TESTING_UNSAFE=	"Assertion failed: (wrapped_calls_fcntl > n), function do_os_wrappers_dupfd_cloexec, file ../tests/os-wrappers-test.c, line 222"

.include <bsd.port.mk>
