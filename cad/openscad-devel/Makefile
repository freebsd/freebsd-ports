PORTNAME=	openscad
PORTVERSION=	2022.05.20
#PORTREVISION=	1
CATEGORIES=	cad
PKGNAMESUFFIX=	-devel

#PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
#PATCHFILES+=	cc49ad8dac24.patch:-p1

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Programmer's solid 3D CAD modeller #'

BROKEN=		fails to configure: The imported target "Qt5::Core" references the file "/usr/local/lib/qt5/bin/qmake" but this file does not exist.

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cgal>0:math/cgal
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

CONFLICTS=	openscad

USES=		bison cmake compiler:c++14-lang cpe desktop-file-utils eigen:3 gettext \
		gl gnome pkgconfig qt:5 shared-mime-info xorg
USE_GITHUB=	yes
USE_GL=		gl glu glew
USE_GNOME=	cairo glib20 libxml2
USE_QT=		buildtools_build core concurrent_build dbus gui multimedia widgets
USE_XORG=	x11
GH_ACCOUNT=	microsoft:mimalloc
GH_PROJECT=	MCAD:mcad mimalloc:mimalloc
GH_TAGNAME=	6aae7963498675dfb5bedaaef2cb8e56bdcddcab bd0a7ba3f042bfbced5ca1894b236cea08904e26:mcad v2.0.3:mimalloc
GH_SUBDIR=	libraries/MCAD:mcad submodules/mimalloc:mimalloc
#QMAKE_ARGS=	CONFIG+="experimental" VERSION=${PORTVERSION}
# Avoid overlinking: kvm, procstat, boost(thread, system), Qt5(concurrent, network, printsupport)
LDFLAGS+=	-Wl,--as-needed -L${LOCALBASE}/lib

#post-patch:
#	@${REINPLACE_CMD} 's/-libusb//' ${WRKSRC}/features/hidapi.prf
#	@${REINPLACE_CMD} -e 's,share/man,man,' \
#		${WRKSRC}/openscad.pro

.include <bsd.port.mk>
