PORTNAME=	gmic-qt
DISTVERSIONPREFIX=	v.
DISTVERSION=	3.4.1
PORTEPOCH=	1
CATEGORIES=	graphics kde
MASTER_SITES=	http://gmic.eu/:stdlib
DISTFILES=	gmic_stdlib_community${DISTVERSION:S/.//g}.h:stdlib
DIST_SUBDIR=	KDE/${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}.tar.gz ${DISTFILE_gmic} ${DISTFILE_cimg}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Versatile Qt front-end to G'MIC
WWW=		https://github.com/c-koi/gmic-qt

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		gmake:devel/gmake
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libpng16.so:graphics/png

FLAVORS=	none gimp # reflect the value of GMIC_QT_HOST for simplicity
FLAVOR?=	${FLAVORS:[1]}
gimp_PKGNAMESUFFIX=	-gimp

USES=		cmake compiler:c++14-lang pkgconfig qt:5 shebangfix xorg
USE_QT=		core gui network widgets \
		buildtools:build linguisttools:build qmake:build
USE_XORG=	ice sm x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	c-koi
GH_TUPLE=	GreycLab:gmic:${DISTVERSIONFULL}:gmic/gmic \
		GreycLab:CImg:${DISTVERSIONFULL}:cimg

SHEBANG_FILES=	translations/lrelease.sh \
		translations/filters/csv2ts.sh \
		translations/filters/ts2csv.sh

# Use the extracted cimg/gmic & Co, as we do not want to depend on graphics/gimp
# which would get pulled in by graphics/cimg.
CMAKE_ARGS=	-DGMIC_QT_HOST:STRING="${FLAVOR}" \
		-DGMIC_PATH:STRING="${WRKSRC_gmic}/src"
CMAKE_OFF=	ENABLE_SYSTEM_GMIC

PORTSCOUT=	limit:[0-9]\..*

.if ${FLAVOR} == gimp
LIB_DEPENDS+=	libbabl-0.1.so:x11/babl \
		libgegl-0.4.so:graphics/gegl \
		libgimp-2.0.so:graphics/gimp-app \
		libjson-glib-1.0.so:devel/json-glib
USES+=		gettext-runtime gnome
USE_GNOME=	cairo gdkpixbuf2 glib20
PLUGINS_DIR=	libexec/gimp/2.2/plug-ins/gmic_gimp_qt
.else
PLUGINS_DIR=	bin
.endif

PLIST_FILES=	${PLUGINS_DIR}/gmic_${FLAVOR:S/$/_/:S/none_//}qt

pre-configure:
# Copy the necessary files
	${CP} ${WRKSRC_cimg}/CImg.h ${WRKSRC_gmic}/src
	${CP} ${DISTDIR}/${DIST_SUBDIR}/gmic_stdlib_community${DISTVERSION:S/.//g}.h ${WRKSRC_gmic}/src/gmic_stdlib_community.h

.include <bsd.port.mk>
