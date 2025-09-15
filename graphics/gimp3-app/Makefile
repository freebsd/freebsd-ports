PORTNAME=	gimp
DISTVERSION=	3.0.4
PORTREVISION=	2
CATEGORIES?=	graphics gnome
MASTER_SITES=	GIMP/gimp/v${PORTVERSION:R}
PKGNAMESUFFIX=	3-app

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNU Image Manipulation Program
WWW=		https://www.gimp.org/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		glib-networking>=0:net/glib-networking \
		mypaint-brushes>0:graphics/mypaint-brushes \
		bash:shells/bash \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		appstreamcli:devel/appstream

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libasound.so:audio/alsa-lib \
		liblcms2.so:graphics/lcms2 \
		libgegl-0.4.so:graphics/gegl \
		libbabl-0.1.so:x11/babl \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libpoppler-glib.so:graphics/poppler-glib \
		libgexiv2.so:graphics/gexiv2 \
		libjson-c.so:devel/json-c \
		libmypaint.so:graphics/libmypaint \
		libfreetype.so:print/freetype2 \
		libappstream-glib.so:devel/appstream-glib \
		libImath.so:math/Imath \
		libwebp.so:graphics/webp \
		libOpenEXR.so:graphics/openexr \
		libIex.so:graphics/openexr \
		libjson-glib-1.0.so:devel/json-glib \
		libgudev-1.0.so:devel/libgudev \
		${LIB_DEPENDS_${ARCH}}

LIB_DEPENDS_aarch64=		libunwind.so:devel/libunwind
LIB_DEPENDS_amd64=		libunwind.so:devel/libunwind
LIB_DEPENDS_i386=		libunwind.so:devel/libunwind
LIB_DEPENDS_powerpc64=		libunwind.so:devel/libunwind
LIB_DEPENDS_powerpc64le=	libunwind.so:devel/libunwind

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		glib-networking>=0:net/glib-networking \
		mypaint-brushes>0:graphics/mypaint-brushes

USES=		cpe desktop-file-utils gettext gnome jpeg libarchive \
		localbase:ldflags meson ninja perl5 pkgconfig python:3.7+ \
		shebangfix tar:xz xorg
USE_CXXSTD=	gnu++14
USE_GNOME=	gtk30 introspection cairo gdkpixbuf librsvg2 libxslt
USE_XORG=	ice sm x11 xcursor xext xfixes xmu xpm xt
USE_LDCONFIG=	yes

#LDFLAGS+=	-L${LOCALBASE}/lib -Wl,--allow-shlib-undefined
LDFLAGS+=	-Wl,--allow-shlib-undefined

CONFLICTS_INSTALL=	gimp-app

BINARY_ALIAS=	python3=${PYTHON_CMD}
INSTALL_TARGET=	install-strip

#MESON_ARGS=	-Denable-console-bin=false \
#		-Dwin32-debug-console=false \
MESON_ARGS=	-Dappdata-test=disabled \
		-Dheadless-tests=disabled \
		-Dicc-directory=${LOCALBASE}/share/color/icc \
		-Dilbm=disabled \
		-Diff=disabled \
		-Dfits=disabled

OPTIONS_DEFINE?=	AALIB GHOSTSCRIPT HEIF HELP OPENJPEG JS JXL LIBMNG WMF DOCS VALA CFITSIO
OPTIONS_DEFAULT?=	AALIB GHOSTSCRIPT HEIF OPENJPEG JS JXL WMF DOCS VALA LUA CFITSIO
OPTIONS_SINGLE=		SCRIPTS
OPTIONS_SINGLE_SCRIPTS=	LUA LUAJIT LUA_NONE
OPTIONS_SUB=	yes

AALIB_LIB_DEPENDS=	libaa.so:graphics/aalib
AALIB_MESON_ENABLED=	aa

CFITSIO_MESON_ENABLED=	fits
CFITSIO_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio

GHOSTSCRIPT_USES=		ghostscript
GHOSTSCRIPT_MESON_ENABLED=	ghostscript

HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_MESON_ENABLED=	heif

HELP_DESC=		GIMP User Manual
HELP_RUN_DEPENDS=	gimp-help-en>=0:misc/gimp-help-en

LIBMNG_BROKEN=		require rewrired mng port
LIBMNG_LIB_DEPENDS=	libmng.so:graphics/libmng
LIBMNG_MESON_ENABLED=	mng

OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
OPENJPEG_MESON_ENABLED=	jpeg2000

JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_MESON_ENABLED=	jpeg-xl

WMF_LIB_DEPENDS=	libexpat.so:textproc/expat2 \
			libwmf.so:graphics/libwmf
WMF_MESON_ENABLED=	wmf

JS_DESC=                Install Javascript plug-ins
JS_LIB_DEPENDS=         libgjs.so:lang/gjs
JS_RUN_DEPENDS=         gjs-console:lang/gjs
JS_MESON_ENABLED=       javascript

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_ENABLED=	gi-docgen

VALA_DESC=		Build VAPI and Vala plugins
VALA_USES=		vala:build
VALA_MESON_ENABLED=	vala

LUA_USES=		lua:51
LUA_BUILD_DEPENDS=	${LUA_REFMODLIBDIR}/lgi/corelgilua${LUA_VER_STR}.so:devel/lua-lgi@${LUA_FLAVOR}
LUA_RUN_DEPENDS=	${LUA_REFMODLIBDIR}/lgi/corelgilua${LUA_VER_STR}.so:devel/lua-lgi@${LUA_FLAVOR}

LUAJIT_DESC?=		Lua scripting language support via Luajit
LUAJIT_USES=		luajit
LUAJIT_BROKEN=		LuaJIT cannot use devel/lua-lgi module yet

LUA_NONE_DESC?=		Disable Lua scripting language support
LUA_NONE_MESON_FALSE=	lua

LIBS+=		-lexecinfo -lm
CPE_PRODUCT=	gimp
CPE_VENDOR=	gnu

SHEBANG_FILES=	plug-ins/python/*.py \
		plug-ins/python/python-console/*.py \
		extensions/goat-exercises/*.py \
		extensions/goat-exercises/*.js \
		extensions/goat-exercises/*.lua

SHEBANG_LANG+=	gjs

PLIST_SUB+=	BINVER=${PORTVERSION:R:R} ABIVER=${PORTVERSION:R} SHLIBVER=${PORTVERSION:E}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLUA} || ${PORT_OPTIONS:MLUAJIT}
PLIST_SUB+=	LUASCRIPTS=""
.else
PLIST_SUB+=	LUASCRIPTS="@comment "
.endif

#post-patch:
#.for s in 16 22 24 32 48 64 256
#	@${CP} ${WRKSRC}/desktop/${s}x${s}/gimp.png ${WRKSRC}/desktop/${s}x${s}/gimp3.png
#.endfor
#	@${CP} ${WRKSRC}/desktop/scalable/gimp.svg ${WRKSRC}/desktop/scalable/gimp3.svg

.include <bsd.port.mk>
