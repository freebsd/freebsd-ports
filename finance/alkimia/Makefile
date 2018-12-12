# $FreeBSD$

PORTNAME=	alkimia
PORTVERSION=	7.0.2
PORTREVISION=	1
CATEGORIES=	finance kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}
PKGNAMESUFFIX=	-${SLAVE}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE financial data handling library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

# Depending on ecm via USE_KDE causes unwanted CMAKE_ARGS to be set
BUILD_DEPENDS=	${LOCALBASE}/share/ECM/cmake/ECMConfig.cmake:devel/kf5-extra-cmake-modules

USES=		cmake:outsource compiler:c++11-lang pathfix tar:xz
USE_LDCONFIG=	yes

SLAVE?=		qt5
.if ${SLAVE} ==	qt4
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES+=		qt:4
USE_QT=		corelib dbus \
		moc_build qmake_build rcc_build
# BUILD_QT4 must be set to "1" due to comparison used in src/LibAlkimiaConfig.cmake.in
CMAKE_ARGS+=	-DBUILD_QT4=1
CMAKE_OFF+=	KDE_INSTALL_USE_QT_SYS_PATHS
INCLUDE_SUBDIR=	Qt4
.else
USES+=		qt:5
USE_QT=		core dbus \
		buildtools_build qmake_build
CMAKE_ON+=	KDE_INSTALL_USE_QT_SYS_PATHS
INCLUDE_SUBDIR=	Qt5
QTVER_SUFFIX=	5
.endif

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

.if ${SLAVE} == qt4
TEST_USE=		QT=qtestlib
.else
TEST_USE=		QT=testlib
.endif
TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
