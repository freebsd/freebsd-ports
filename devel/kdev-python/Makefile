# $FreeBSD$

PORTNAME=	kdev-python
DISTVERSION=	5.2.1
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/kdevelop/${DISTVERSION}/src
DIST_SUBDIR=	KDE/kdevelop

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python support for KDevelop

BUILD_DEPENDS=	kdev-pg-qt:devel/kdevelop-pg-qt
LIB_DEPENDS=	libkdevcmakecommon.so:devel/kdevelop

USES=		cmake:outsource compiler:c++11-lib kde:5 python:3.4+ tar:xz
USE_KDE=	attica auth codecs completion config coreaddons \
		ecm i18n jobwidgets kio parts service \
		sonnet texteditor textwidgets threadweaver widgetsaddons xmlgui
USE_QT5=	core dbus gui network widgets xml \
		buildtools_build qmake_build

# Does not build with jobs.
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
