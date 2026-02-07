PORTNAME=	gmic
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.4.1
CATEGORIES=	graphics kde
MASTER_SITES=	https://github.com/vanyossi/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	krita-
PKGNAMESUFFIX=	-plugin
DISTNAME=	${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	KDE/${PKGBASE}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Krita native plugin for G'MIC
WWW=		https://github.com/vanyossi/gmic

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		gmake:devel/gmake
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libkritaqmicinterface.so:graphics/krita \
		libpng16.so:graphics/png

USES=		cmake compiler:c++14-lang kde:5 pkgconfig qt:5 shebangfix xorg
USE_KDE=	coreaddons ecm:build
USE_QT=		core gui network widgets \
		buildtools:build linguisttools:build qmake:build
USE_XORG=	ice sm x11 xext

SHEBANG_FILES=	translations/lrelease.sh \
		translations/filters/csv2ts.sh \
		translations/filters/ts2csv.sh

CMAKE_ARGS=	-DGMIC_QT_HOST:STRING="krita-plugin"
CMAKE_OFF=	ENABLE_SYSTEM_GMIC

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSIONFULL}
WRKSRC_SUBDIR=	gmic-qt

PLIST_FILES=	lib/kritaplugins/krita_gmic_qt.so \
		share/gmic/gmic_cluts.gmz \
		share/gmic/gmic_denoise_cnn.gmz

.include <bsd.port.mk>
