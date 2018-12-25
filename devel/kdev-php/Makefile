# $FreeBSD$

PORTNAME=	kdev-php
DISTVERSION=	5.3.0
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/kdevelop/${DISTVERSION}/src
DIST_SUBDIR=	KDE/kdevelop

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PHP support for KDevelop

BUILD_DEPENDS=	kdev-pg-qt:devel/kdevelop-pg-qt
LIB_DEPENDS=	libkdevcmakecommon.so:devel/kdevelop

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons ecm \
		i18n itemmodels jobwidgets kcmutils kio parts service sonnet \
		texteditor textwidgets threadweaver widgetsaddons xmlgui
USE_QT=		concurrent core dbus gui network webkit widgets xml \
		buildtools_build qmake_build

# Does not build with jobs.
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
