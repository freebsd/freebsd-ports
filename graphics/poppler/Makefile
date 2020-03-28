# Created by: marcus@FreeBSD.org
# $FreeBSD$

PORTNAME=	poppler
DISTVERSION=	0.86.1
PORTREVISION?=	1
CATEGORIES=	graphics print
MASTER_SITES=	https://poppler.freedesktop.org/

MAINTAINER?=	desktop@FreeBSD.org
COMMENT?=	PDF rendering library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnspr4.so:devel/nspr \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2 \
		libnss3.so:security/nss \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	poppler-data>0:graphics/poppler-data

USES=		compiler:c++11-lang cpe cmake:insource gnome jpeg libtool \
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

# Slave ports.
_POPPLER_SLAVES=	library glib qt5 utils
_SLAVE_PORT?=		library

# Activate the wanted module, and deactivate the others.
CMAKE_ON+=	ENABLE_${_SLAVE_PORT:tu}
CMAKE_OFF+=	${_POPPLER_SLAVES:N${_SLAVE_PORT}:tu:S/^/ENABLE_/}

.if ${_SLAVE_PORT} == library
PORTSCOUT=	limitw:1,even
USES+=		iconv
CMAKE_ON+=	ENABLE_CPP
PLIST_SUB+=	SHLIB_VER=97

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
USE_GNOME+=		glib20 introspection:Build
.  elif ${_SLAVE_PORT} == qt5
USES+=			qt:5
USE_QT=			core gui widgets xml \
			buildtools_build qmake_build testlib_build
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
.endif

.include <bsd.port.mk>
