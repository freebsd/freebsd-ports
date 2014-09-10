# Created by: Golyashov Sergei <svvord@mail.ru>
# $FreeBSD$

PORTNAME=	kdevplatform
PORTVERSION=	${KDEVELOP_VERSION:S/4./1./}
PORTREVISION=	5
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEVELOP_BRANCH}/kdevelop/${KDEVELOP_VERSION}/src
DIST_SUBDIR=	KDE/kdevelop/${KDEVELOP_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Set of libraries for KDE IDE-like programs

LIB_DEPENDS=	libsvn_client-1.so:${PORTSDIR}/devel/subversion \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libqjson.so:${PORTSDIR}/devel/qjson \
		libgrantlee_gui.so:${PORTSDIR}/devel/grantlee

USE_KDE4=	kate_run kdehier kdelibs kdeprefix automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build \
		corelib designer_build gui webkit
USES=		cmake shebangfix tar:xz
USE_LDCONFIG=	yes

SHEBANG_FILES=	util/kdev_format_source util/kdevplatform_shell_environment.sh

PLIST_SUB+=	SHLIB_VER=7.0.0 \
		SHLIB_SHVER=7 \
		GRANTLEE_VER=0.4

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po:BOOL=Off

.include <bsd.port.mk>
