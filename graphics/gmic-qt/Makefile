# $FreeBSD$

PORTNAME=	gmic-qt
DISTVERSIONPREFIX=	v.
DISTVERSION=	215
CATEGORIES=	graphics kde
MASTER_SITES=	http://gmic.eu/:stdlib \
		LOCAL/tcberner/${PORTNAME}/${PORTVERSION}:stdlib
DISTFILES=	gmic_stdlib.h:stdlib
DIST_SUBDIR=	KDE/${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}.tar.gz ${DISTFILE_gmic} ${DISTFILE_cimg}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Versatile Qt front-end to GMIC

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libpng.so:graphics/png

USES=		cmake:outsource compiler:c++14-lang pkgconfig
USE_QT5=	core gui network widgets \
		buildtools_build linguisttools_build qmake_build
USE_XORG=	ice sm x11 xext

# Use the extracted cimg/gmic & Co, as we do not want to depend on graphics/gimp
# which would get pulled in by graphics/cimg.
CMAKE_ARGS=	-DGMIC_QT_HOST:STRING="krita" \
		-DGMIC_PATH:STRING="${WRKSRC_gmic}/src"

USE_GITHUB=	yes
GH_ACCOUNT=	c-koi
GH_TUPLE=	dtschump:gmic:${DISTVERSIONFULL}:gmic \
		dtschump:cimg:${DISTVERSIONFULL}:cimg

pre-configure:
# Copy the necessary files
	${CP} ${WRKDIR}/CImg-${DISTVERSIONFULL}/CImg.h ${WRKSRC_gmic}/src
	${CP} ${DISTDIR}/${DIST_SUBDIR}/gmic_stdlib.h ${WRKSRC_gmic}/src

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gmic_krita_qt ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${BUILD_WRKSRC}/*.qm ${STAGEDIR}${DATADIR}/translations/

.include <bsd.port.mk>
