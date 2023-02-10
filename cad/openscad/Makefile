PORTNAME=	openscad
DISTVERSION=	2021.01.01-20221206
PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Programmer's solid 3D CAD modeller #'
WWW=		https://openscad.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cgal>0:math/cgal \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libzip.so:archivers/libzip \
		libhidapi.so:comms/hidapi \
		libboost_regex.so:devel/boost-libs \
		libqscintilla2_qt5.so:devel/qscintilla2-qt5 \
		libopencsg.so:graphics/opencsg \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libdouble-conversion.so:devel/double-conversion

USES=		bison cmake compiler:c++14-lang cpe desktop-file-utils eigen:3 gettext \
		gl gnome localbase:ldflags pkgconfig qt:5 shared-mime-info xorg
USE_GL=		gl glu glew
USE_GNOME=	cairo glib20 libxml2
USE_QT=		buildtools:build core concurrent:build dbus gui multimedia network svg widgets qmake:build
USE_XORG=	x11
QMAKE_ARGS=	CONFIG+="experimental" VERSION=${PORTVERSION}
# Avoid overlinking: kvm, procstat, boost(thread, system), Qt5(concurrent, network, printsupport)
LDFLAGS+=	-Wl,--as-needed

USE_GITHUB=	yes
GH_TAGNAME=	972d184
GH_TUPLE=	openscad:MCAD:1ea4022:MCAD/libraries/MCAD \
		microsoft:mimalloc:fe61be8:mimalloc/submodules/mimalloc

CMAKE_ARGS=	-DQT5QSCINTILLA_LIBRARY=/usr/local/lib/qt5/libqscintilla2_qt5.so

CONFLICTS_INSTALL=	openscad-devel # bin/openscad

.include <bsd.port.mk>
