# Created by: Golyashov Sergei <svvord@mail.ru>
# $FreeBSD$

PORTNAME=	kdevplatform
PORTVERSION=	${KDEVELOP_VERSION:S/4./1./}
PORTREVISION=	2
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDEVELOP_BRANCH}/kdevelop/${KDEVELOP_VERSION}/src
DIST_SUBDIR=	KDE/kdevelop/${KDEVELOP_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Set of libraries for KDE IDE-like programs

LIB_DEPENDS=	libsvn_client-1.so:devel/subversion \
		libboost_thread.so:devel/boost-libs \
		libqjson.so:devel/qjson

USES=		cmake:outsource compiler:c++11-lib grantlee:4 kde:4 shebangfix \
		tar:bz2
USE_KDE=	kate_run kdelibs automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build \
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
