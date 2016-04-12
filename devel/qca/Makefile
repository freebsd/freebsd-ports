# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	qca
PORTVERSION=	2.1.1
CATEGORIES=	devel
MASTER_SITES=	KDE/stable/qca/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform crypto API for Qt 4

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cmake:outsource tar:xz
CMAKE_ARGS=	-DBUILD_PLUGINS=none -DBUILD_TESTS=no \
		-DPKGCONFIG_INSTALL_PREFIX=${PREFIX}/libdata/pkgconfig \
		-DQCA_FEATURE_INSTALL_DIR=${QT_MKSPECDIR}/features \
		-DQCA_MAN_INSTALL_DIR=${PREFIX}/man
CONFIGURE_ENV=	QC_CERTSTORE_PATH=${LOCALBASE}/share/certs/ca-root-nss.crt
USE_LDCONFIG=	yes

.if defined(PKGNAMESUFFIX)
CMAKE_ARGS+=	-DQCA_SUFFIX=qt5
USE_QT5=	core buildtools_build qmake_build
.else
USE_QT4=	corelib moc_build qmake_build rcc_build
CMAKE_ARGS+=	-DQT4_BUILD=yes
.endif

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

OPTIONS_DEFINE=	GNUPG OPENSSL SASL
OPTIONS_DEFAULT=GNUPG OPENSSL
OPTIONS_SUB=	yes

GNUPG_CMAKE_ON=		-DWITH_gnupg_PLUGIN=yes
GNUPG_RUN_DEPENDS=	gpg2:security/gnupg

OPENSSL_CMAKE_ON=	-DWITH_ossl_PLUGIN=yes
OPENSSL_USE=		OPENSSL=yes

SASL_CMAKE_ON=		-DWITH_cyrus-sasl_PLUGIN=yes
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

post-patch:
# Qt Network module is used for tests only
	${REINPLACE_CMD} 's,Core Network,Core,' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
