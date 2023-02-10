PORTNAME=	root
DISTVERSION=	6.26.10
CATEGORIES=	devel science math parallel python
MASTER_SITES=	https://root.cern/download/
DISTFILES=	${PORTNAME}_v${DISTVERSION}.source${EXTRACT_SUFX}

MAINTAINER=	erik@tenku.dk
COMMENT=	Data analysis framework made at CERN
WWW=		https://root.cern/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL2_1.txt

BUILD_DEPENDS=	${PYNUMPY} \
		bash:shells/bash \
		nlohmann-json>=3:devel/nlohmann-json
LIB_DEPENDS=	libAfterImage.so:graphics/libafterimage \
		libcfitsio.so:astro/cfitsio \
		libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libfreetype.so:print/freetype2 \
		libftgl.so:graphics/ftgl \
		libgif.so:graphics/giflib \
		libgl2ps.so:print/gl2ps \
		libgsl.so:math/gsl \
		liblz4.so:archivers/liblz4 \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libtbb.so:devel/onetbb \
		libtiff.so:graphics/tiff \
		libvdt.so:math/vdt \
		libxkbcommon.so:x11/libxkbcommon \
		libXrdCl.so:databases/xrootd \
		libxxhash.so:devel/xxhash \
		libzstd.so:archivers/zstd

USES=		blaslapack:openblas cmake compiler:c++17-lang desktop-file-utils \
		gettext-runtime gl gnome iconv jpeg mysql:57 pgsql:13.0+ python:3.9+ \
		shebangfix sqlite ssl xorg
USE_GL=		glew glu opengl
USE_GNOME=	cairo gdkpixbuf2 glib20 librsvg2 libxml2
USE_XORG=	ice sm x11 xau xaw xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xfont xfont2 xft xi xinerama xkbfile xmu xpm xrandr \
		xrender xres xscrnsaver xt xv xxf86vm

SHEBANG_FILES=	etc/dictpch/makepch.py etc/proof/utils/circle.sh \
		etc/proof/utils/crypt etc/proof/utils/pps \
		etc/proof/utils/proofctl.sh etc/proof/utils/proofinstall.sh

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17
CMAKE_ON=	gnuinstall soversion

CONFIGURE_WRKSRC?=	${WRKDIR}/.build
MAKE_ENV+=		ROOTSYS=${CONFIGURE_WRKSRC}

PLIST_SUB+=	SHLIB_SHVER="${DISTVERSION:R}" \
		SHLIB_VER="${DISTVERSION}" \
		NOT_INSTALLED_ON_AARCH64="${NOT_INSTALLED_ON_AARCH64}" \
		AARCH64_PCM_SUFFIX="${AARCH64_PCM_SUFFIX}"

OPTIONS_DEFINE=	DOCS ROOT7
OPTIONS_DEFAULT=	ROOT7
OPTIONS_SUB=	yes

ROOT7_DESC=	Enable supplementary preview features of ROOT version 7
ROOT7_CMAKE_BOOL=	root7

.include <bsd.port.options.mk>

# File only installed with LLVM/Clang 13 (used on FreeBSD 12.4 and 13.x)
.if 1204000 <= ${OSVERSION} && ${OSVERSION} < 1400000
PLIST_FILES+=	lib/root/std_config${AARCH64_PCM_SUFFIX}.pcm
.endif

.include <bsd.port.pre.mk>

# Some .modulemap files are not installed on aarch64, and files LIBRARY.pcm are renamed LIBRARY_rdict.pcm on aarch64
.if ${ARCH} == "aarch64"
NOT_INSTALLED_ON_AARCH64=	"@comment "
AARCH64_PCM_SUFFIX=	"_rdict"
.else
NOT_INSTALLED_ON_AARCH64=	""
AARCH64_PCM_SUFFIX=	""
.endif

# In LLVM/Clang 10.0.1 (used on FreeBSD 12.3), the cstdalign header is missing from the std modulemap, but it is declared included in ROOT's std modulemap - this has to be removed.
# See https://github.com/llvm/llvm-project/blob/main/libcxx/include/module.modulemap.in#L181
# The same seems to be the case for the other headers defined in the variable "modules" below.
.if ${OSVERSION} < 1204000
modules=	cstdalign cuchar "ext\/functional" "ext\/numeric" "bits\/allocator.h" "bits\/basic_ios.h" "bits\/cpp_type_traits.h" "bits\/exception_defines.h" "bits\/ios_base.h" "bits\/locale_facets.h" "bits\/stl_algobase.h" "bits\/stl_map.h" "bits\/stl_pair.h" bits_stl_tree_h
post-patch:
	@MODULEMAP=${WRKSRC}/interpreter/cling/include/cling/std.modulemap ${SH} ${SCRIPTDIR}/remove-modules-from-modulemap.sh ${modules}
.endif

.include <bsd.port.post.mk>
