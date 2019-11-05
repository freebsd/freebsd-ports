# $FreeBSD$

PORTNAME=	gmic-qt
DISTVERSIONPREFIX=	v.
DISTVERSION=	2.3.6
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	graphics kde
MASTER_SITES=	http://gmic.eu/:stdlib \
		LOCAL/tcberner/${PORTNAME}/${PORTVERSION}:stdlib
DISTFILES=	gmic_stdlib.h:stdlib
DIST_SUBDIR=	KDE/${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}.tar.gz ${DISTFILE_gmic} ${DISTFILE_cimg}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Versatile Qt front-end to GMIC

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libpng.so:graphics/png

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
CMAKE_ARGS=	-DGMIC_QT_HOST:STRING="krita" \
		-DGMIC_PATH:STRING="${WRKSRC_gmic}/src"

PORTSCOUT=	limit:[0-9]\..*

pre-configure:
# Copy the necessary files
	${CP} ${WRKSRC_cimg}/CImg.h ${WRKSRC_gmic}/src
	${CP} ${DISTDIR}/${DIST_SUBDIR}/gmic_stdlib.h ${WRKSRC_gmic}/src

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gmic_krita_qt ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${BUILD_WRKSRC}/*.qm ${STAGEDIR}${DATADIR}/translations

.include <bsd.port.mk>
