PORTNAME=	openscad
PORTVERSION=	${GIT_SRC_DATE}
#PORTREVISION=	1
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
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

LIB_DEPENDS=	libzip.so:archivers/libzip \
		libhidapi.so:comms/hidapi \
		libboost_regex.so:devel/boost-libs \
		libqscintilla2_qt6.so:devel/qscintilla2@qt6 \
		libopencsg.so:graphics/opencsg \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libdouble-conversion.so:devel/double-conversion \
		libtbb.so:devel/onetbb

CONFLICTS=	openscad

USES=		bison cmake compiler:c++17-lang cpe desktop-file-utils eigen:3 gettext \
		gl gnome pkgconfig python qt:6 shared-mime-info xorg
USE_GITHUB=	yes
USE_GL=		gl glu glew
USE_GNOME=	cairo glib20 libxml2
USE_QT=		base 5compat multimedia svg tools
USE_XORG=	x11
GH_ACCOUNT=	microsoft:mimalloc elalish:manifold arsenm:sanitizerscmake \
		openscad:opencsg AngusJohnson:clipper2
GH_PROJECT=	MCAD:mcad mimalloc:mimalloc manifold:manifold sanitizers-cmake:sanitizerscmake \
		OpenCSG:opencsg Clipper2:clipper2
GH_TAGNAME=	${GIT_SRC_HASH} ${GIT_MCAD_HASH}:mcad \
		${GIT_CLIPPER2_HASH}:clipper2 ${GIT_OPENCSG_HASH}:opencsg \
		${GIT_MANIFOLD_HASH}:manifold ${GIT_MIMALLOC_HASH}:mimalloc \
		${GIT_SANITIZERSCMAKE_HASH}:sanitizerscmake
GH_SUBDIR=	libraries/MCAD:mcad submodules/mimalloc:mimalloc submodules/manifold:manifold \
		submodules/sanitizers-cmake:sanitizerscmake submodules/OpenCSG:opencsg \
		submodules/Clipper2:clipper2
# Avoid overlinking: kvm, procstat, boost(thread, system), Qt5(concurrent, network, printsupport)
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,--as-needed -L${LOCALBASE}/lib
CMAKE_ARGS+=	-DUSE_QT6="ON" -DUSE_MIMALLOC="OFF" -DENABLE_CGAL="ON" -DUSE_BUILTIN_OPENCSG="ON" -DENABLE_GLX="ON" -DCMAKE_BUILD_TYPE=Debug

.include "Makefile.git_rev"

.include <bsd.port.pre.mk>

do-install:
	${CMAKE_BIN} --install ${BUILD_WRKSRC} --prefix ${STAGEDIR}${PREFIX}

.include <bsd.port.post.mk>
