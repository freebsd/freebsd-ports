PORTNAME=	poppler
DISTVERSION=	23.12.0
CATEGORIES=	graphics print
MASTER_SITES=	https://poppler.freedesktop.org/

MAINTAINER?=	desktop@FreeBSD.org
COMMENT?=	PDF rendering library
WWW=		https://poppler.freedesktop.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnspr4.so:devel/nspr \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2 \
		libnss3.so:security/nss \
		libfontconfig.so:x11-fonts/fontconfig \
		libgpgmepp.so:security/gpgme-cpp
BUILD_DEPENDS=	${LOCALBASE}/include/boost/container/small_vector.hpp:devel/boost-libs \
		gsed:textproc/gsed
RUN_DEPENDS=	poppler-data>0:graphics/poppler-data

USES=		cmake:insource compiler:c++17-lang cpe gnome gperf jpeg libtool \
		localbase pathfix pkgconfig tar:xz
CPE_VENDOR=	freedesktop
USE_GNOME=	cairo libxml2
USE_LDCONFIG=	yes
CMAKE_ON=	ENABLE_LIBJPEG  \
		ENABLE_LIBPNG \
		ENABLE_LIBTIFF \
		ENABLE_UNSTABLE_API_ABI_HEADERS \
		ENABLE_ZLIB \
		ENABLE_NSS \
		ENABLE_SPLASH
CMAKE_OFF=	BUILD_GTK_TESTS
# Ensure that path ordering does not lead to openjpeg15 being found and picked
# instead of openjpeg2 on systems that have both installed
# Note: since f3ba77e14cac05d43caf35100848eeaee3bc64b4 graphics/openjpeg15 installs
# its cmake files to ${PREFIX}/lib/openjpeg15
CMAKE_ARGS+=	-DCMAKE_IGNORE_PATH:PATH=${PREFIX}/lib/openjpeg-1.5

# Slave ports.
_POPPLER_SLAVES=	library glib qt5 qt6 utils
_SLAVE_PORT?=		library

BINARY_ALIAS=		gperf=${GPERF} \
			sed=${LOCALBASE}/bin/gsed

# Activate the wanted module, and deactivate the others.
CMAKE_ON+=	ENABLE_${_SLAVE_PORT:tu}
CMAKE_OFF+=	${_POPPLER_SLAVES:N${_SLAVE_PORT}:tu:S/^/ENABLE_/}

.if ${_SLAVE_PORT} == library
PORTSCOUT=	limitw:1,even
USES+=		iconv
CMAKE_ON+=	ENABLE_CPP
PLIST_SUB+=	SHLIB_VER=133

OPTIONS_DEFINE=		CURL OPENJPEG
OPTIONS_DEFAULT=	OPENJPEG
OPTIONS_SUB=		yes
.else
PORTSCOUT=		ignore:1

LIB_DEPENDS+=		libpoppler.so:graphics/poppler
PKGNAMESUFFIX=		-${_SLAVE_PORT}

BUILD_WRKSRC=		${WRKSRC}/${_SLAVE_PORT}
INSTALL_WRKSRC=		${WRKSRC}/${_SLAVE_PORT}

CMAKE_ARGS+=		-DENABLE_LIBOPENJPEG:STRING="none" \
			-DENABLE_LIBCURL:BOOL=FALSE

.  if ${_SLAVE_PORT} == glib
USES+=			python:build
USE_GNOME+=		glib20 introspection:Build
BINARY_ALIAS+=		python3=${PYTHON_CMD}
.  elif ${_SLAVE_PORT} == qt5
USES+=			qt:5
USE_QT=			core gui widgets xml \
			buildtools:build qmake:build testlib:build
.  elif ${_SLAVE_PORT} == qt6
USES+=			gl qt:6
USE_GL+=		gl opengl
USE_QT=			base
.  elif ${_SLAVE_PORT} == utils
LIB_DEPENDS+=		libpoppler-glib.so:graphics/poppler-glib
USES+=			gnome
.  endif

.endif

CURL_CMAKE_BOOL=	ENABLE_LIBCURL
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
OPENJPEG_CMAKE_ON=	-DENABLE_LIBOPENJPEG:STRING="openjpeg2"
OPENJPEG_CMAKE_OFF=	-DENABLE_LIBOPENJPEG:STRING="none"

post-install:
.if ${_SLAVE_PORT} == glib
	${INSTALL_DATA} ${WRKSRC}/poppler-glib.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig
.elif ${_SLAVE_PORT} == qt5
	${INSTALL_DATA} ${WRKSRC}/poppler-qt5.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig
.elif ${_SLAVE_PORT} == qt6
	${INSTALL_DATA} ${WRKSRC}/poppler-qt6.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig
.endif

.include <bsd.port.mk>
