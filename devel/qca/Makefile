# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	qca
PORTVERSION=	2.1.3
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	KDE/stable/qca/${PORTVERSION}/src
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform crypto API for Qt ${FLAVOR:C/qt//}

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

qt4_DEPRECATED=		Qt4 has been EOL since december 2015
qt4_EXPIRATION_DATE=	2019-03-15

USES=		cmake:outsource tar:xz
CMAKE_ARGS=	-DBUILD_PLUGINS=none -DBUILD_TESTS=no \
		-DPKGCONFIG_INSTALL_PREFIX=${PREFIX}/libdata/pkgconfig \
		-DQCA_FEATURE_INSTALL_DIR=${QT_MKSPECDIR}/features \
		-DQCA_MAN_INSTALL_DIR=${PREFIX}/man
CONFIGURE_ENV=	QC_CERTSTORE_PATH=${LOCALBASE}/share/certs/ca-root-nss.crt
USE_LDCONFIG=	yes

.  if ${FLAVOR} == qt4
CMAKE_ON=	QT4_BUILD
USES+=		qt:4
USE_QT=		corelib moc_build qmake_build rcc_build
.  else
CMAKE_ARGS+=	-DQCA_SUFFIX=qt5
USES+=		compiler:c++11-lang qt:5
USE_QT=	core buildtools_build qmake_build
.  endif
qt4_PLIST=	${.CURDIR}/pkg-plist.qt4
qt5_PLIST=	${.CURDIR}/pkg-plist.qt5

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

OPTIONS_DEFINE=	GNUPG OPENSSL SASL
OPTIONS_DEFAULT=GNUPG OPENSSL
OPTIONS_SUB=	yes

GNUPG_CMAKE_ON=		-DWITH_gnupg_PLUGIN=yes
GNUPG_RUN_DEPENDS=	gpg2:security/gnupg

OPENSSL_CMAKE_ON=	-DWITH_ossl_PLUGIN=yes
OPENSSL_USES=		ssl

SASL_CMAKE_ON=		-DWITH_cyrus-sasl_PLUGIN=yes
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

post-patch:
# Qt Network module is used for tests only
	${REINPLACE_CMD} 's,Core Network,Core,' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
