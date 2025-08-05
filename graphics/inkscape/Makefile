PORTNAME=	inkscape
DISTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	https://media.inkscape.org/dl/resources/file/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Full featured open source SVG editor
WWW=		https://inkscape.org

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

BUILD_DEPENDS=	ragel:devel/ragel
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libgc.so:devel/boehm-gc \
		libgsl.so:math/gsl \
		liblcms2.so:graphics/lcms2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpotrace.so:graphics/libpotrace \
		libpng.so:graphics/png \
		libenchant-2.so:textproc/enchant2 \
		libepoxy.so:graphics/libepoxy \
		lib2geom.so:math/lib2geom
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachecontrol>0:www/py-cachecontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssselect>0:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.7.1:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scour>0:textproc/py-scour@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss2>0:textproc/py-tinycss2@${PY_FLAVOR} \
		fig2dev:print/fig2dev
TEST_DEPENDS=	googletest>0:devel/googletest \
		bash:shells/bash

USES=		compiler:c++20-lang cmake:testing cpe desktop-file-utils ghostscript:run \
		gnome jpeg pathfix pkgconfig python \
		readline shebangfix tar:xz xorg
USE_GNOME=	cairo gdkpixbuf glibmm gtkmm30 gtksourceview4 libxml2 libxslt
USE_PYTHON=	cython3
USE_XORG=	sm ice x11 xext
USE_LDCONFIG=	yes

DATETAG=	2025-05-08_ebf0e940d0
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}_${DATETAG}

BINARY_ALIAS=	python3=${PYTHON_CMD}
SHEBANG_FILES=	share/extensions/*.py share/extensions/genpofiles.sh \
		share/templates/*.py man/fix-roff-punct

OPTIONS_DEFINE=		OPENMP POPPLER SCRIBUS VISIO CDR WPG GVFS NLS GSPELL
OPTIONS_DEFAULT=	POPPLER VISIO CDR WPG GM GSPELL
OPTIONS_DEFAULT_amd64=	OPENMP
OPTIONS_DEFAULT_powerpc64=	OPENMP
OPTIONS_DEFAULT_powerpc64le=	OPENMP
OPTIONS_RADIO=		IMAGICK
OPTIONS_RADIO_IMAGICK=	IMAGICK6 GM
OPTIONS_SUB=		yes

CDR_DESC=		Support for CorelDRAW graphics
CDR_CMAKE_BOOL=		WITH_LIBCDR
CDR_LIB_DEPENDS=	librevenge-stream-0.0.so:textproc/librevenge \
			libcdr-0.1.so:graphics/libcdr01

GVFS_USE=		GNOME=gvfs

OPENMP_CMAKE_BOOL=	WITH_OPENMP

POPPLER_DESC=		PDF preview rendering
POPPLER_CMAKE_BOOL=	ENABLE_POPPLER ENABLE_POPPLER_CAIRO
POPPLER_LIB_DEPENDS=	libpoppler.so:graphics/poppler \
			libpoppler-glib.so:graphics/poppler-glib

SCRIBUS_DESC=		Support color-managed PDF export using Scribus (experimental)
SCRIBUS_RUN_DEPENDS=	scribus:print/scribus

VISIO_DESC=		Support for Microsoft Visio diagrams
VISIO_CMAKE_BOOL=	WITH_LIBVISIO
VISIO_LIB_DEPENDS=	librevenge-stream-0.0.so:textproc/librevenge \
			libvisio-0.1.so:textproc/libvisio01

WPG_DESC=		Support for WordPerfect graphics
WPG_CMAKE_BOOL=		WITH_LIBWPG
WPG_LIB_DEPENDS=	libwpg-0.3.so:graphics/libwpg03

IMAGICK_DESC=		Raster image format library
IMAGICK6_DESC=		Use ImageMagick6
IMAGICK6_USES=		magick:6
IMAGICK6_CMAKE_BOOL=	WITH_IMAGE_MAGICK
GM_DESC=		Use GraphicsMagick
GM_LIB_DEPENDS=		libGraphicsMagick.so:graphics/GraphicsMagick
GM_CMAKE_BOOL=		WITH_GRAPHICS_MAGICK

NLS_CMAKE_BOOL=		WITH_NLS
NLS_USES=		gettext

GSPELL_DESC=		Support for spell checking through gspell
GSPELL_CMAKE_BOOL=	WITH_GSPELL
GSPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell

post-patch:
	@${REINPLACE_CMD} -e 's|COMMAND python3|COMMAND ${PYTHON_VERSION}|g' \
		${WRKSRC}/share/*/CMakeLists.txt
	# Third entry in the table of interpreters is basename of executable
	@${REINPLACE_CMD} -e 's|"python3"|"${PYTHON_VERSION}"|g' \
		${WRKSRC}/src/extension/implementation/script.cpp
	@${TOUCH} ${WRKSRC}/share/extensions/gcodetools_check_for_updates.inx.h

.include <bsd.port.mk>
