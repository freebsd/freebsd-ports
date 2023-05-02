PORTNAME=	qca
DISTVERSION=	2.3.6
CATEGORIES=	devel
MASTER_SITES=	KDE/stable/qca/${PORTVERSION}
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform crypto API for Qt ${FLAVOR:C/qt//}
WWW=		https://api.kde.org/qca/html/index.html

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cmake compiler:c++11-lang qt:${FLAVOR:S/qt//} tar:xz
CMAKE_ARGS=	-DBUILD_PLUGINS=none -DBUILD_TESTS=no \
		-DPKGCONFIG_INSTALL_PREFIX=${PREFIX}/libdata/pkgconfig \
		-DQCA_FEATURE_INSTALL_DIR=${QT_MKSPECDIR}/features \
		-DQCA_MAN_INSTALL_DIR=${PREFIX}/man
CONFIGURE_ENV=	QC_CERTSTORE_PATH=${LOCALBASE}/share/certs/ca-root-nss.crt
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DQCA_SUFFIX=${FLAVOR} \
		-D${FLAVOR:tu}:BOOL=TRUE
_USE_QT5=	core buildtools:build qmake:build
_USE_QT6=	5compat base
USE_QT=		${_USE_QT${FLAVOR:S/qt//}}

_PLIST_SUB_QT5=	QT5_ONLY=""
_PLIST_SUB_QT6= QT5_ONLY="@comment "
PLIST_SUB=	SHLIB_VER=${PORTVERSION} \
		QCA_QT_VERSION=${FLAVOR} \
		${_PLIST_SUB_QT${FLAVOR:S/qt//}}

OPTIONS_DEFINE=	BOTAN GNUPG OPENSSL SASL TEST
OPTIONS_DEFAULT=GNUPG OPENSSL
OPTIONS_SUB=	yes

BOTAN_CMAKE_ON=		-DWITH_botan_PLUGIN=yes
BOTAN_DESC=		Build with Botan crypto library
BOTAN_LIB_DEPENDS=	libbotan-2.so:security/botan2
BOTAN_USES=		pkgconfig

GNUPG_CMAKE_ON=		-DWITH_gnupg_PLUGIN=yes
GNUPG_RUN_DEPENDS=	gpg2:security/gnupg

OPENSSL_CMAKE_ON=	-DWITH_ossl_PLUGIN=yes
OPENSSL_USES=		ssl

SASL_CMAKE_ON=		-DWITH_cyrus-sasl_PLUGIN=yes
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_TEST_TARGET=	test
TEST_USE=		QT=network,testlib

.include <bsd.port.mk>
