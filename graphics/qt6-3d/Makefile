# TODO: fix build with CPUTYPE set -- see qt5-3d for the same issue:
# /wrkdirs/usr/ports/graphics/qt6-3d/work/qt3d-everywhere-src-6.2.1/src/render/jobs/abstractpickingjob.cpp:110:33: error: no viable conversion from 'const Matrix4x4' (aka 'const Qt3DCore::Matrix4x4_SSE') to incomplete type 'const Qt3DCore::Matrix4x4_AVX2'
#     nearPos = nearPos.unproject(viewMatrix, projectionMatrix, viewport);
#                                 ^~~~~~~~~~
# /wrkdirs/usr/ports/graphics/qt6-3d/work/.build/include/Qt3DCore/6.2.1/Qt3DCore/private/../../../../../../qt3d-everywhere-src-6.2.1/src/core/transforms/vector3d_sse_p.h:68:7: note: forward declaration of 'Qt3DCore::Matrix4x4_AVX2'
# class Matrix4x4_AVX2;

PORTNAME=	3d
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++ and QML APIs for easy inclusion of 3D graphics

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libassimp.so:multimedia/assimp \
		libdouble-conversion.so:devel/double-conversion \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgraphite2.so:graphics/graphite2 \
		libharfbuzz.so:print/harfbuzz \
		libicudata.so:devel/icu \
		libminizip.so:archivers/minizip \
		libpcre.so:devel/pcre \
		libpcre2-16.so:devel/pcre2 \
		libpng16.so:graphics/png \
		libxkbcommon.so:x11/libxkbcommon \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang gettext-runtime gl gnome python:build \
		pkgconfig qt-dist:6
USE_GL=		gl
USE_GNOME=	glib20
USE_QT=		base declarative shadertools
USE_XORG=	x11 xau xcb xdmcp
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
