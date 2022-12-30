PORTNAME=	root
DISTVERSION=	6.26.06
CATEGORIES=	devel science math parallel python
MASTER_SITES=	https://root.cern/download/
DISTFILES=	${PORTNAME}_v${DISTVERSION}.source${EXTRACT_SUFX}

MAINTAINER=	erik@tenku.dk
COMMENT=	Data analysis framework made at CERN
WWW=		https://root.cern/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL2_1.txt

BUILD_DEPENDS=	${PYNUMPY} \
		bash:shells/bash
LIB_DEPENDS=	libAfterImage.so:graphics/libafterimage \
		libcfitsio.so:astro/cfitsio \
		libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libfreetype.so:print/freetype2 \
		libgif.so:graphics/giflib \
		libgsl.so:math/gsl \
		libjpeg.so:graphics/jpeg-turbo \
		liblz4.so:archivers/liblz4 \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libtbb.so:devel/onetbb \
		libtiff.so:graphics/tiff \
		libvdt.so:math/vdt \
		libxkbcommon.so:x11/libxkbcommon \
		libXrdCl.so:databases/xrootd \
		libzstd.so:archivers/zstd

USES=		blaslapack:openblas cmake desktop-file-utils gettext-runtime gl \
		gnome iconv mysql:57 pgsql:13.0+ python:3.9+ shebangfix sqlite \
		ssl xorg
USE_GL=		glew glu opengl
USE_GNOME=	cairo gdkpixbuf2 glib20 librsvg2 libxml2
USE_XORG=	ice sm x11 xau xaw xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xfont xfont2 xft xi xinerama xkbfile xmu xpm xrandr \
		xrender xres xscrnsaver xt xv xxf86vm

SHEBANG_FILES=	etc/dictpch/makepch.py etc/proof/utils/circle.sh \
		etc/proof/utils/crypt etc/proof/utils/pps \
		etc/proof/utils/proofctl.sh etc/proof/utils/proofinstall.sh

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=14
CMAKE_ON=	gnuinstall soversion

MAKE_ENV+=		ROOTSYS=${CONFIGURE_WRKSRC}
CONFIGURE_WRKSRC?=	${WRKDIR}/.build

PLIST_SUB+=	SHLIB_SHVER="${DISTVERSION:R}" \
		SHLIB_VER="${DISTVERSION}"

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

# File not installed in 14 Current maybe because of clang 14+, temporary fix
.if ${OSVERSION} < 1400000
PLIST_FILES+=	lib/root/std_config.pcm
.endif

.include <bsd.port.mk>
