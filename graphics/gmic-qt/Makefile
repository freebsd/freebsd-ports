# $FreeBSD$

PORTNAME=	gmic-qt
DISTVERSIONPREFIX=	v.
DISTVERSION=	2.3.6
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	graphics kde
MASTER_SITES=	http://gmic.eu/:stdlib \
		LOCAL/tcberner/${PORTNAME}/${PORTVERSION}:stdlib
DISTFILES=	gmic_stdlib${DISTVERSION:S/.//g}.h:stdlib
DIST_SUBDIR=	KDE/${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}.tar.gz ${DISTFILE_gmic} ${DISTFILE_cimg}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	64cdd2cdd416ec43171753eddf55a7b3fda0d33b.patch:-p1 # Remove translation files install directive

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Versatile Qt front-end to GMIC

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libpng.so:graphics/png

FLAVORS=	none krita gimp # reflect the value of GMIC_QT_HOST for simplicity
FLAVOR?=	${FLAVORS:[1]}
krita_PKGNAMESUFFIX=	-krita
gimp_PKGNAMESUFFIX=	-gimp

USES=		cmake compiler:c++14-lang pkgconfig qt:5 xorg
USE_QT=		core gui network widgets \
		buildtools_build linguisttools_build qmake_build
USE_XORG=	ice sm x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	c-koi
GH_TUPLE=	dtschump:gmic:${DISTVERSIONFULL}:gmic/gmic \
		dtschump:CImg:${DISTVERSIONFULL}:cimg

# Use the extracted cimg/gmic & Co, as we do not want to depend on graphics/gimp
# which would get pulled in by graphics/cimg.
CMAKE_ARGS=	-DGMIC_QT_HOST:STRING="${FLAVOR}" \
		-DGMIC_PATH:STRING="${WRKSRC_gmic}/src"

PLIST_FILES=	bin/gmic_${FLAVOR:S/$/_/:S/none_//}qt

PORTSCOUT=	limit:[0-9]\..*

.if ${FLAVOR} == gimp
LIB_DEPENDS+=	libbabl-0.1.so:x11/babl \
		libgegl-0.4.so:graphics/gegl \
		libgimp-2.0.so:graphics/gimp-app \
		libjson-glib-1.0.so:devel/json-glib
USES+=		gettext-runtime gnome
USE_GNOME=	cairo gdkpixbuf2 glib20
.endif

pre-configure:
# Copy the necessary files
	${CP} ${WRKSRC_cimg}/CImg.h ${WRKSRC_gmic}/src
	${CP} ${DISTDIR}/${DIST_SUBDIR}/gmic_stdlib${DISTVERSION:S/.//g}.h ${WRKSRC_gmic}/src/gmic_stdlib.h

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gmic_${FLAVOR:S/$/_/:S/none_//}qt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
