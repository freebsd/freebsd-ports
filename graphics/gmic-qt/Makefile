PORTNAME=	gmic-qt
DISTVERSIONPREFIX=	v.
DISTVERSION=	3.6.1
PORTEPOCH=	1
CATEGORIES=	graphics kde
MASTER_SITES=	https://github.com/GreycLab/gmic/releases/download/${DISTVERSIONFULL}/ \
		https://gmic.eu/files/source/
DISTNAME=	gmic_${DISTVERSION}
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Versatile Qt front-end to G'MIC
WWW=		https://gmic.eu

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		gmake:devel/gmake
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libpng16.so:graphics/png

FLAVORS=	none gimp gimp3 # reflect the value of GMIC_QT_HOST for simplicity
FLAVOR?=	${FLAVORS:[1]}
gimp_PKGNAMESUFFIX=	-gimp
gimp3_PKGNAMESUFFIX=	-gimp3

USES=		cmake compiler:c++17-lang gl pkgconfig qt:6 shebangfix xorg
USE_GL=		opengl
USE_QT=		base tools:build
USE_XORG=	ice sm x11 xext

SHEBANG_FILES=	translations/lrelease.sh \
		translations/filters/csv2ts.sh \
		translations/filters/ts2csv.sh

CMAKE_ARGS=	-DGMIC_QT_HOST:STRING="${FLAVOR}"
CMAKE_ON=	BUILD_WITH_QT6
CMAKE_OFF=	ENABLE_SYSTEM_GMIC

PORTSCOUT=	limit:[0-9]\..*

WRKSRC=		${WRKDIR}/${DISTNAME:S|_|-|}
WRKSRC_SUBDIR=	${PORTNAME}

.if ${FLAVOR} == "gimp"
LIB_DEPENDS+=	libbabl-0.1.so:x11/babl \
		libgegl-0.4.so:graphics/gegl \
		libgimp-2.0.so:graphics/gimp-app \
		libjson-glib-1.0.so:devel/json-glib
USES+=		gettext-runtime gnome
USE_GNOME=	cairo gdkpixbuf glib20
PLUGINS_DIR=	libexec/gimp/2.2/plug-ins/gmic_gimp_qt
.elif ${FLAVOR} == "gimp3"
LIB_DEPENDS+=	libbabl-0.1.so:x11/babl \
		libgegl-0.4.so:graphics/gegl \
		libgexiv2.so:graphics/gexiv2 \
		libgimp-3.0.so:graphics/gimp3-app \
		libjson-glib-1.0.so:devel/json-glib
USES+=		gettext-runtime gnome
USE_GNOME=	cairo gdkpixbuf glib20 pango
PLUGINS_DIR=	lib/gimp/3.0/plug-ins/gmic_gimp_qt
.else
PLUGINS_DIR=	bin
.endif

PLIST_FILES=	${PLUGINS_DIR}/gmic_${FLAVOR:S|$|_|:S|none_||:C|gimp[3]|gimp|}qt

.include <bsd.port.mk>
