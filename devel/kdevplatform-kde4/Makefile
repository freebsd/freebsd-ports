# Created by: Golyashov Sergei <svvord@mail.ru>
# $FreeBSD$

PORTNAME=	kdevplatform
PORTVERSION=	${KDEVELOP_VERSION:S/4./1./}
PORTREVISION=	17
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDEVELOP_BRANCH}/kdevelop/${KDEVELOP_VERSION}
DIST_SUBDIR=	KDE/kdevelop/${KDEVELOP_VERSION}
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Set of libraries for KDE IDE-like programs

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libsvn_client-1.so:devel/subversion \
		libboost_thread.so:devel/boost-libs \
		libqjson.so:devel/qjson@qt4

USES=		cmake:outsource compiler:c++11-lib grantlee:4 kde:4 qt:4 shebangfix \
		tar:xz
USE_KDE=	kate_run kdelibs automoc4
USE_QT=		qmake_build moc_build uic_build rcc_build \
		corelib designer_build gui webkit
USE_LDCONFIG=	yes

SHEBANG_FILES=	util/kdev_format_source util/kdevplatform_shell_environment.sh

PLIST_SUB+=	SHLIB_VER=8.0.0 \
		SHLIB_SHVER=8

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po:BOOL=Off

.include <bsd.port.mk>
