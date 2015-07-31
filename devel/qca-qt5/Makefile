# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	qca
PORTVERSION=	2.1.0
CATEGORIES=	devel
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/
PKGNAMESUFFIX=	-qt5

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Cross-platform crypto API for Qt5

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

USES=		cmake:outsource
CMAKE_ARGS=	-DBUILD_PLUGINS=none -DBUILD_TESTS=no -DQT5_BUILD=yes \
		-DPKGCONFIG_INSTALL_PREFIX=${PREFIX}/libdata/pkgconfig \
		-DQCA_FEATURE_INSTALL_DIR=${QT_MKSPECDIR}/features \
		-DQCA_MAN_INSTALL_DIR=${MANPREFIX}/man \
		-DQCA_SUFFIX=qt5
CMAKE_ENV=	QC_CERTSTORE_PATH=${LOCALBASE}/share/certs/ca-root-nss.crt
USE_LDCONFIG=	yes
USE_QT5=	buildtools_build core network qmake_build

OPTIONS_DEFINE=	GNUPG OPENSSL SASL
OPTIONS_DEFAULT=GNUPG OPENSSL
OPTIONS_SUB=	yes

GNUPG_CMAKE_ON=		-DWITH_gnupg_PLUGIN=yes
GNUPG_RUN_DEPENDS=	gpg2:${PORTSDIR}/security/gnupg

OPENSSL_CMAKE_ON=	-DWITH_ossl_PLUGIN=yes
OPENSSL_USE=		OPENSSL=yes

SASL_CMAKE_ON=		-DWITH_cyrus-sasl_PLUGIN=yes
SASL_LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

.include <bsd.port.mk>
