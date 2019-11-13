# $FreeBSD$

PORTNAME=	photoflow
DISTVERSION=	0.2.8-1260
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Non-destructive photo retouching program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		no matching function for call to 'vips_image_get_blob'
BROKEN_i386=	see https://github.com/aferrero2707/PhotoFlow/issues/192

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
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
#Disable optimization for the builder CPU when building official packages
.if defined(PACKAGE_BUILDING)
CMAKE_ON=	BINARY_PACKAGE_BUILD
.endif

LDFLAGS+=	-lexecinfo

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		OCIO
OPTIONS_DEFAULT=	OCIO
OPTIONS_SUB=		yes

OCIO_DESC=		Enable the integration of OpenColorIO
OCIO_CMAKE_BOOL=	OCIO_ENABLED
OCIO_LIB_DEPENDS=	libOpenColorIO.so:graphics/opencolorio
OCIO_VARS=		GH_TUPLE+=sobotka:filmic-blender:1.1.1:fb/../.build/data/filmic-blender \
			GH_TUPLE+=imageworks:OpenColorIO-Configs:0bb079c08be410030669cbf5f19ff869b88af953:c/../.build/data/ocio-configs

.include <bsd.port.mk>
