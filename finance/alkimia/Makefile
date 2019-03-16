# $FreeBSD$

PORTNAME=	alkimia
PORTVERSION=	7.0.2
PORTREVISION=	2
CATEGORIES=	finance kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}
PKGNAMESUFFIX?=	-qt5

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE financial data handling library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

# Depending on ecm via USE_KDE causes unwanted CMAKE_ARGS to be set
BUILD_DEPENDS=	${LOCALBASE}/share/ECM/cmake/ECMConfig.cmake:devel/kf5-extra-cmake-modules

USES=		cmake compiler:c++11-lang pathfix qt:5 tar:xz
USE_LDCONFIG=	yes
USE_QT=		core dbus \
		buildtools_build qmake_build
CMAKE_ON=	KDE_INSTALL_USE_QT_SYS_PATHS
INCLUDE_SUBDIR=	Qt5
QTVER_SUFFIX=	5

PLIST_SUB=	INCLUDE_SUBDIR=${INCLUDE_SUBDIR} \
		QTVER_SUFFIX=${QTVER_SUFFIX} \
		VER=${PORTVERSION:R}

OPTIONS_SINGLE=		MPLIB
OPTIONS_SINGLE_MPLIB=	GMP MPIR
OPTIONS_DEFINE=		TEST
OPTIONS_DEFAULT=	MPIR
OPTIONS_SUB=		yes
MPLIB_DESC=		Multi-precision library (MPIR preferred)

GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_CMAKE_BOOL=		CMAKE_DISABLE_FIND_PACKAGE_MPIR

MPIR_DESC=		MPIR (multiple precision arithmetic) support
MPIR_LIB_DEPENDS=	libmpir.so:math/mpir

TEST_USE=		QT=testlib
TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
