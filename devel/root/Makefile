PORTNAME=	root
DISTVERSION=	6.28.02
PORTREVISION=	1
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
		gettext-runtime gl gnome iconv jpeg mysql:57 pgsql:13+ python:3.9+ \
		shebangfix sqlite ssl xorg
USE_GL=		glew glu opengl
USE_GNOME=	cairo gdkpixbuf2 glib20 librsvg2 libxml2
USE_XORG=	ice sm x11 xau xaw xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xfont xfont2 xft xi xinerama xkbfile xmu xpm xrandr \
		xrender xres xscrnsaver xt xv xxf86vm

SHEBANG_FILES=	config/rootssh etc/dictpch/makepch.py etc/proof/utils/circle.sh \
		etc/proof/utils/crypt etc/proof/utils/pps \
		etc/proof/utils/proofctl.sh etc/proof/utils/proofinstall.sh

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17
CMAKE_ON=	gnuinstall soversion
CMAKE_OFF=	builtin_gtest

CONFIGURE_WRKSRC?=	${WRKDIR}/.build
MAKE_ENV+=		ROOTSYS=${CONFIGURE_WRKSRC}

OPTIONS_DEFINE=	DOCS ROOT7
OPTIONS_DEFAULT=	ROOT7
OPTIONS_SUB=	yes

ROOT7_DESC=	Enable supplementary preview features of ROOT version 7
ROOT7_CMAKE_BOOL=	root7

.include <bsd.port.options.mk>

PLIST_SUB+=	SHLIB_SHVER="${DISTVERSION:R}" \
		SHLIB_VER="${DISTVERSION}"

# Some .modulemap, .pcm and .idx files are not installed on aarch64, a few .pcm files are exclusive to aarch64 and files LIBRARY.pcm are renamed libLIBRARY_rdict.pcm on aarch64
.if ${ARCH} == "aarch64"
PLIST_SUB+=	NOT_INSTALLED_ON_AARCH64="@comment " ONLY_INSTALLED_ON_AARCH64="" AARCH64_PCM_PREFIX="lib" AARCH64_PCM_SUFFIX="_rdict"
.else
PLIST_SUB+=	NOT_INSTALLED_ON_AARCH64="" ONLY_INSTALLED_ON_AARCH64="@comment " AARCH64_PCM_PREFIX="" AARCH64_PCM_SUFFIX=""
.endif

# Some files only installed with LLVM/Clang 13 (used on FreeBSD 12.4 and 13.x)
# TODO: Introduce USES+=llvm:min=14 instead when this can be deemed not too obtrusive on supported releases
#       -- the post-patch step further down can then be phased out as well
.if 1204000 <= ${OSVERSION} && ${OSVERSION} < 1302000 && ${OSVERSION} != 1301507
PLIST_SUB+=	ONLY_INSTALLED_WITH_LLVM_CLANG_13=""
.else
PLIST_SUB+=	ONLY_INSTALLED_WITH_LLVM_CLANG_13="@comment "
.endif

.include <bsd.port.mk>
