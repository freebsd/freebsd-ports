# $FreeBSD$

PORTNAME=	photoflow
DISTVERSION=	0.2.8-1260
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Non-destructive photo retouching program

LICENSE=	APACHE20
xLICENSE_FILE=	${WRKSRC}/../LICENSE_Apache2

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libfftw3.so:math/fftw3 \
		libfftw3.so:math/fftw3 \
		liblcms2.so:graphics/lcms2 \
		liblensfun.so:graphics/lensfun \
		libtiff.so:graphics/tiff \
		libpugixml.so:textproc/pugixml \
		libvips.so:graphics/vips

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gnome jpeg pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	aferrero2707
GH_PROJECT=	PhotoFlow
GH_TAGNAME=	da84a071
USE_GNOME=	atkmm cairomm glib20 glibmm gtk20 gtkmm24 libsigc++20 pangomm

CMAKE_OFF=	BUNDLED_LENSFUN

LDFLAGS+=	-lexecinfo

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=			OCIO_ENABLED
OPTIONS_SUB=			yes

OCIO_ENABLED_DESC=		Enable the integration of OpenColorIO
OCIO_ENABLED_CMAKE_BOOL=	OCIO_ENABLED
OCIO_ENABLED_LIB_DEPENDS=	libOpenColorIO.so:graphics/opencolorio

.include <bsd.port.mk>
