PORTNAME=	root
DISTVERSION=	6.28.06
PORTREVISION=	1
CATEGORIES=	devel science math parallel python
MASTER_SITES=	https://root.cern/download/
DISTFILES=	${PORTNAME}_v${DISTVERSION}.source${EXTRACT_SUFX}

MAINTAINER=	erik@tenku.dk
COMMENT=	Data analysis framework made at CERN
WWW=		https://root.cern/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL2_1.txt

BUILD_AND_RUN_DEPENDS=	bash:shells/bash \
			nlohmann-json>=3:devel/nlohmann-json
BUILD_DEPENDS=	${BUILD_AND_RUN_DEPENDS}
LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libfreetype.so:print/freetype2 \
		libgif.so:graphics/giflib \
		libgsl.so:math/gsl \
		liblz4.so:archivers/liblz4 \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libtbb.so:devel/onetbb \
		libtiff.so:graphics/tiff \
		libunwind.so:devel/libunwind \
		libvdt.so:math/vdt \
		libXrdCl.so:databases/xrootd \
		libxxhash.so:devel/xxhash \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	${BUILD_AND_RUN_DEPENDS}

USES=		cmake compiler:c++17-lang desktop-file-utils \
		gettext-runtime gnome iconv jpeg shebangfix ssl
USE_GNOME=	libxml2

SHEBANG_FILES=	config/rootssh etc/dictpch/makepch.py etc/proof/utils/circle.sh \
		etc/proof/utils/crypt etc/proof/utils/pps \
		etc/proof/utils/proofctl.sh etc/proof/utils/proofinstall.sh

# Flags and environment variables for building
CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17
CMAKE_ON=	gnuinstall soversion
CMAKE_OFF=	builtin_gtest clad
CONFIGURE_WRKSRC?=	${WRKDIR}/.build
MAKE_ENV+=		ROOTSYS=${CONFIGURE_WRKSRC}

# Port build options; DOCS also on by default
OPTIONS_DEFINE=	DOCS MYSQL PGSQL PYROOT ROOT7 SQLITE X11
OPTIONS_DEFAULT=	PYROOT ROOT7 X11
OPTIONS_SUB=	yes

# Option: MYSQL
MYSQL_DESC=		Enable MySQL bindings
MYSQL_USES=		mysql
MYSQL_CMAKE_BOOL=	mysql

# Option: PGSQL
PGSQL_DESC=		Enable PostgreSQL bindings
PGSQL_USES=		pgsql:13+
PGSQL_CMAKE_BOOL=	pgsql

#Option: PYROOT
PYROOT_DESC=		Enable bindings between Python and C++ with PyROOT
PYROOT_BUILD_DEPENDS=	${PYNUMPY}
PYROOT_USES=		python:3.9+,build,run
PYROOT_USES_OFF=	python:3.9+,build
PYROOT_CMAKE_BOOL=	pyroot

# Option: ROOT7
ROOT7_DESC=		Enable supplementary preview features of ROOT version 7
ROOT7_CMAKE_BOOL=	root7

# Option: SQLITE
SQLITE_DESC=		Enable SQLite bindings
SQLITE_USES=		sqlite
SQLITE_CMAKE_BOOL=	sqlite

# Option: X11
X11_DESC=		Enable interfacing with X11 graphics system
X11_LIB_DEPENDS=	libAfterImage.so:graphics/libafterimage \
			libftgl.so:graphics/ftgl \
			libgl2ps.so:print/gl2ps \
			libxkbcommon.so:x11/libxkbcommon
X11_USES=		gl xorg
X11_USE=		gl=glew,glu,opengl gnome=cairo,gdkpixbuf2,glib20,librsvg2 \
			xorg=ice,sm,x11,xau,xaw,xcb,xcomposite,xcursor,xdamage,xdmcp,xext,xfixes,xfont,xfont2,xft,xi,xinerama,xkbfile,xmu,xpm,xrandr,xrender,xres,xscrnsaver,xt,xv,xxf86vm
X11_CMAKE_BOOL=		x11

.include <bsd.port.options.mk>

PLIST_SUB+=	SHLIB_SHVER="${DISTVERSION:R}" \
		SHLIB_VER="${DISTVERSION}"

# Some .modulemap, .pcm and .idx files are not installed on aarch64, a few .pcm files are exclusive to aarch64 and files LIBRARY.pcm are renamed libLIBRARY_rdict.pcm on aarch64
.if ${ARCH} == "aarch64"
PLIST_SUB+=	NOT_INSTALLED_ON_AARCH64="@comment " ONLY_INSTALLED_ON_AARCH64="" AARCH64_PCM_PREFIX="lib" AARCH64_PCM_SUFFIX="_rdict"
.else
PLIST_SUB+=	NOT_INSTALLED_ON_AARCH64="" ONLY_INSTALLED_ON_AARCH64="@comment " AARCH64_PCM_PREFIX="" AARCH64_PCM_SUFFIX=""
.endif

# Some files only installed with LLVM/Clang 13 (used on FreeBSD 12.4, 13.0 and 13.1)
# TODO: Introduce USES+=llvm:min=14 instead when this can be deemed not too obtrusive on supported releases
.if 1204000 <= ${OSVERSION} && ${OSVERSION} < 1302000 && ${OSVERSION} != 1301507
PLIST_SUB+=	ONLY_INSTALLED_WITH_LLVM_CLANG_13=""
.else
PLIST_SUB+=	ONLY_INSTALLED_WITH_LLVM_CLANG_13="@comment "
.endif

.include <bsd.port.mk>
