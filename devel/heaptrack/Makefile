PORTNAME=	heaptrack
DISTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Heap memory profiler
WWW=		https://github.com/KDE/heaptrack

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libunwind.so:devel/libunwind \
		libKChart.so:graphics/kdiagram \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 \
		localbase  qt:5 tar:xz xorg
USE_KDE=	auth auth codecs completion config config \
		configwidgets coreaddons ecm i18n iconthemes itemmodels \
		jobwidgets kio kio service solid threadweaver \
		widgetsaddons windowsystem
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
