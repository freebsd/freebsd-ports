# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	qca
PORTVERSION=	2.1.3
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	KDE/stable/qca/${PORTVERSION}/src
PKGNAMESUFFIX=	-qt5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform crypto API for Qt ${FLAVOR:C/qt//}

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cmake compiler:c++11-lang qt:5 tar:xz
CMAKE_ARGS=	-DBUILD_PLUGINS=none -DBUILD_TESTS=no \
		-DPKGCONFIG_INSTALL_PREFIX=${PREFIX}/libdata/pkgconfig \
		-DQCA_FEATURE_INSTALL_DIR=${QT_MKSPECDIR}/features \
		-DQCA_MAN_INSTALL_DIR=${PREFIX}/man
CONFIGURE_ENV=	QC_CERTSTORE_PATH=${LOCALBASE}/share/certs/ca-root-nss.crt
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DQCA_SUFFIX=qt5
USE_QT=	core buildtools_build qmake_build

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

OPTIONS_DEFINE=	GNUPG OPENSSL SASL TEST
OPTIONS_DEFAULT=GNUPG OPENSSL
OPTIONS_SUB=	yes

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
