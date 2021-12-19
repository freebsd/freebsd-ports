PORTNAME=	heaptrack
DISTVERSION=	1.3.0
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Heap memory profiler

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

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

.include <bsd.port.mk>
