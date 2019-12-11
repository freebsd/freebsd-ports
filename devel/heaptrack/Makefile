# $FreeBSD$

PORTNAME=	heaptrack
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0-92
DISTVERSIONSUFFIX=	-g987d9c4
PORTREVISION=	3
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Heap memory profiler

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libKChart.so:graphics/kdiagram

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 qt:5 tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	KDE
USE_KDE=	auth auth codecs completion config config \
		configwidgets coreaddons ecm i18n itemmodels \
		jobwidgets kio kio service threadweaver \
		widgetsaddons
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
