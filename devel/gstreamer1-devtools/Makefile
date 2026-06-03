PORTNAME=	gstreamer1-devtools
PORTVERSION=	${_GST_VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-devtools/
DISTNAME=	gst-devtools-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Gstreamer element validation suite
WWW=		https://gstreamer.freedesktop.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/validate/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib

USES=		compiler:c11 gettext-runtime gnome gstreamer \
		meson pkgconfig python shebangfix tar:xz
USE_GNOME=	cairo gtk30 introspection:build
USE_GSTREAMER=	bad rtsp-server
USE_LDCONFIG=	yes
USE_PYTHON=	noflavors

SHEBANG_FILES=	validate/launcher/RangeHTTPServer.py \
		validate/tools/gst-validate-launcher.in

MESON_ARGS=	-Ddots_viewer=disabled

BINARY_ALIAS=	python3=${PYTHON_VERSION}

PLIST_SUB=	SOVERSION=${_GST_SOVERSION} \
		VERSION=${_GST_LIB_VER}

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PREFIX}/lib/gst-validate-launcher/python \
		${STAGEDIR}${PREFIX}/lib/gst-validate-launcher/python
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PREFIX}/lib/gst-validate-launcher/python \
		${STAGEDIR}${PREFIX}/lib/gst-validate-launcher/python

.include <bsd.port.mk>
