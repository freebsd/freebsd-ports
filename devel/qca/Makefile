PORTNAME=	qca
DISTVERSION=	2.3.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	KDE/stable/qca/${PORTVERSION}
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform crypto API for Qt ${FLAVOR:C/qt//}
WWW=		https://api.kde.org/qca/html/index.html

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake:testing compiler:c++20-lang localbase:ldflags pkgconfig \
		qt:${FLAVOR:S/qt//} tar:xz
USE_LDCONFIG=	yes
_USE_QT_qt5=	core \
		buildtools:build qmake:build \
		network:test testlib:test
_USE_QT_qt6=	5compat base
USE_QT=		${_USE_QT_${FLAVOR}}

CMAKE_ARGS=	-DBUILD_PLUGINS=none \
		-DPKGCONFIG_INSTALL_PREFIX=${PREFIX}/libdata/pkgconfig \
		-DQCA_FEATURE_INSTALL_DIR=${QT_MKSPECDIR}/features \
		-DQCA_SUFFIX=${FLAVOR} \
		-D${FLAVOR:tu}:BOOL=TRUE
CMAKE_OFF=	BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS

CONFIGURE_ENV=	QC_CERTSTORE_PATH=${LOCALBASE}/share/certs/ca-root-nss.crt

_PLIST_SUB_qt5=	QT5_ONLY=""
_PLIST_SUB_qt6=	QT5_ONLY="@comment "
PLIST_SUB=	SHLIB_VER=${PORTVERSION} \
		QCA_QT_VERSION=${FLAVOR} \
		${_PLIST_SUB_${FLAVOR}}

OPTIONS_DEFINE=	BOTAN GCRYPT GNUPG LOGGER NSS OPENSSL PKCS11 SASL SOFTSTORE
OPTIONS_DEFAULT=GNUPG OPENSSL
OPTIONS_SUB=	yes

BOTAN_DESC=		Build with Botan crypto library
BOTAN_LIB_DEPENDS=	libbotan-3.so:security/botan3
BOTAN_CMAKE_ON=		-DWITH_botan_PLUGIN=yes

GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_CMAKE_ON=	-DWITH_gcrypt_PLUGIN=yes

GNUPG_RUN_DEPENDS=	gpg2:security/gnupg
GNUPG_CMAKE_ON=		-DWITH_gnupg_PLUGIN=yes

LOGGER_DESC=		Simple logger writer
LOGGER_CMAKE_ON=	-DWITH_logger_PLUGIN=yes

NSS_LIB_DEPENDS=	libnspr4.so:devel/nspr \
			libnss3.so:security/nss
NSS_CMAKE_ON=		-DWITH_nss_PLUGIN=yes

OPENSSL_USES=		ssl
OPENSSL_CMAKE_ON=	-DWITH_ossl_PLUGIN=yes

PKCS11_DESC=		Smartcard integration
PKCS11_LIB_DEPENDS=	libpkcs11-helper.so:security/pkcs11-helper
PKCS11_CMAKE_ON=	-DWITH_pkcs11_PLUGIN=yes
PKCS11_IMPLIES=		OPENSSL

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CMAKE_ON=		-DWITH_cyrus-sasl_PLUGIN=yes

SOFTSTORE_DESC=		Simple persistent certificate store
SOFTSTORE_CMAKE_ON=	-DWITH_softstore_PLUGIN=yes

.include <bsd.port.mk>
