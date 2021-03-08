# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	inkscape
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	https://media.inkscape.org/dl/resources/file/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Full featured open source SVG editor

LICENSE=	GPLv2 GPLv2+ GPLv3 GPLv3+ LGPL21 LGPL3 LGPL3+ MPL11
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2  =	${WRKSRC}/LICENSES/GPL-2.0.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt
LICENSE_FILE_GPLv3  =	${WRKSRC}/LICENSES/GPL-3.0.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt
LICENSE_FILE_LGPL21 =	${WRKSRC}/LICENSES/LGPL-2.1.txt
LICENSE_FILE_LGPL3  =	${WRKSRC}/LICENSES/LGPL-3.0.txt
LICENSE_FILE_LGPL3+ =	${WRKSRC}/LICENSES/LGPL-3.0-or-later.txt
LICENSE_FILE_MPL11  =	${WRKSRC}/LICENSES/MPL-1.1.txt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:devel/boost-libs
LIB_DEPENDS=	libpopt.so:devel/popt \
		libgc.so:devel/boehm-gc \
		libgdl-3.so:x11-toolkits/gdl \
		libgsl.so:math/gsl \
		libgtkspell3-3.so:textproc/gtkspell3 \
		liblcms2.so:graphics/lcms2 \
		libfribidi.so:converters/fribidi \
		libaspell.so:textproc/aspell \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpotrace.so:graphics/libpotrace \
		libpng.so:graphics/png \
		libsoup-2.4.so:devel/libsoup \
		libenchant-2.so:textproc/enchant2 \
		libyaml.so:textproc/libyaml \
		libdouble-conversion.so:devel/double-conversion
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scour>0:textproc/py-scour@${PY_FLAVOR} \
		ps2pdf:print/ghostscript9-agpl-base \
		fig2dev:print/fig2dev

USES=		compiler:c++11-lib cmake cpe desktop-file-utils gnome \
		iconv:wchar_t jpeg pathfix pkgconfig python:3.6+ \
		shebangfix tar:xz xorg
USE_GNOME=	gtkmm30 libxml2 libxslt
USE_XORG=	sm ice x11 xext
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}_2021-01-15_e86c870879

INSTALLS_ICONS=	yes

SHEBANG_FILES=	share/extensions/*.py share/extensions/genpofiles.sh \
		share/templates/*.py man/fix-roff-punct

OPTIONS_DEFINE=		OPENMP POPPLER SCRIBUS VISIO CDR DBUS WPG GVFS NLS
OPTIONS_DEFAULT=	POPPLER VISIO CDR WPG GM
OPTIONS_DEFAULT_amd64=	OPENMP
OPTIONS_RADIO=		IMAGICK
OPTIONS_RADIO_IMAGICK=	IMAGICK6 GM
OPTIONS_SUB=		yes

CDR_DESC=		Support for CorelDRAW graphics
CDR_CMAKE_BOOL=		WITH_LIBCDR
CDR_LIB_DEPENDS=	librevenge-stream-0.0.so:textproc/librevenge \
			libcdr-0.1.so:graphics/libcdr01

DBUS_CMAKE_BOOL=	WITH_DBUS
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
			libdbus-1.so:devel/dbus

GVFS_USE=		GNOME=gvfs

OPENMP_USES=		compiler:openmp
OPENMP_CMAKE_BOOL=	WITH_OPENMP

POPPLER_DESC=		PDF preview rendering
POPPLER_CMAKE_BOOL=	ENABLE_POPPLER ENABLE_POPPLER_CAIRO
POPPLER_LIB_DEPENDS=	libpoppler.so:graphics/poppler \
			libpoppler-glib.so:graphics/poppler-glib

SCRIBUS_DESC=		Support color-managed PDF export using Scribus (experimental)
SCRIBUS_RUN_DEPENDS=	scribus:print/scribus-devel

VISIO_DESC=		Support for Microsoft Visio diagrams
VISIO_CMAKE_BOOL=	WITH_LIBVISIO
VISIO_LIB_DEPENDS=	librevenge-stream-0.0.so:textproc/librevenge \
			libvisio-0.1.so:textproc/libvisio01

WPG_DESC=		Support for WordPerfect graphics
WPG_CMAKE_BOOL=		WITH_LIBWPG
WPG_LIB_DEPENDS=	libwpg-0.3.so:graphics/libwpg03

IMAGICK_DESC=		Raster image format library
IMAGICK6_DESC=		Use ImageMagick6
IMAGICK6_LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick6
IMAGICK6_CMAKE_BOOL=	WITH_IMAGE_MAGICK
GM_DESC=		Use GraphicsMagick
GM_LIB_DEPENDS=		libGraphicsMagick.so:graphics/GraphicsMagick
GM_CMAKE_BOOL=		WITH_GRAPHICS_MAGICK

NLS_CMAKE_BOOL=		WITH_NLS
NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} -e 's|COMMAND python3|COMMAND ${PYTHON_VERSION}|g' \
		${WRKSRC}/share/*/CMakeLists.txt
	# Third entry in the table of interpreters is basename of executable
	@${REINPLACE_CMD} -e 's|"python3"|"${PYTHON_VERSION}"|g' \
		${WRKSRC}/src/extension/implementation/script.cpp
	@${TOUCH} ${WRKSRC}/share/extensions/gcodetools_check_for_updates.inx.h

.include <bsd.port.mk>
