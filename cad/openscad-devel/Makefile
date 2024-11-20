PORTNAME=	openscad
PORTVERSION=	2024.10.11
PORTREVISION=	5
CATEGORIES=	cad
PKGNAMESUFFIX=	-devel

#PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
#PATCHFILES+=	cc49ad8dac24.patch:-p1

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Programmer's solid 3D CAD modeller #'
WWW=		https://www.openscad.org/

BUILD_DEPENDS=	cgal>0:math/cgal \
		evdev-proto>0:devel/evdev-proto \
		${LOCALBASE}/include/glm/glm.hpp:math/glm \
		${LOCALBASE}/include/clipper2/clipper.h:cad/Clipper2 \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libzip.so:archivers/libzip \
		libhidapi.so:comms/hidapi \
		libboost_regex.so:devel/boost-libs \
		libqscintilla2_qt5.so:devel/qscintilla2@qt5 \
		libopencsg.so:graphics/opencsg \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libdouble-conversion.so:devel/double-conversion \
		libtbb.so:devel/onetbb

CONFLICTS=	openscad

USES=		bison cmake compiler:c++14-lang cpe desktop-file-utils eigen:3 gettext \
		gl gnome pkgconfig python qt:5 shared-mime-info xorg
USE_GITHUB=	yes
USE_GL=		gl glu glew
USE_GNOME=	cairo glib20 libxml2
USE_QT=		buildtools:build core concurrent:build dbus gui multimedia qmake svg widgets
USE_XORG=	x11
GH_ACCOUNT=	microsoft:mimalloc elalish:manifold arsenm:sanitizerscmake openscad:opencsg
GH_PROJECT=	MCAD:mcad mimalloc:mimalloc manifold:manifold sanitizers-cmake:sanitizerscmake OpenCSG:opencsg
GH_TAGNAME=	19a4d67 bd0a7ba3f042bfbced5ca1894b236cea08904e26:mcad \
		fe61be8:mimalloc 22c6605:manifold c3dc841:sanitizerscmake 059a173:opencsg
GH_SUBDIR=	libraries/MCAD:mcad submodules/mimalloc:mimalloc submodules/manifold:manifold \
		submodules/sanitizers-cmake:sanitizerscmake submodules/OpenCSG:opencsg
# Avoid overlinking: kvm, procstat, boost(thread, system), Qt5(concurrent, network, printsupport)
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,--as-needed -L${LOCALBASE}/lib
#CMAKE_OFF=	USE_GLAD:BOOL=OFF
#CMAKE_ON=	USE_GLEW:BOOL=ON

.include <bsd.port.pre.mk>

do-install:
	${CMAKE_BIN} --install ${BUILD_WRKSRC} --prefix ${STAGEDIR}${PREFIX}

.include <bsd.port.post.mk>
