# $FreeBSD$

PORTNAME=	heaptrack
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0-43
PORTREVISION=	1
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Heap memory profiler

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libunwind.so:devel/libunwind \
		libKChart.so:graphics/kdiagram

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 \
		localbase  qt:5 tar:xz
USE_KDE=	auth auth codecs completion config config \
		configwidgets coreaddons ecm i18n itemmodels \
		jobwidgets kio kio service threadweaver \
		widgetsaddons windowsystem
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build

KDE_INVENT=	1c2d406387dc59e7ebba727fd42a647f2f38bba4 sdk

.include <bsd.port.mk>
