PORTNAME=	hotspot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Perf GUI for performance analysis (needs mock 'perf' command)
WWW=		https://github.com/KDAB/hotspot

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/librustc_demangle.a:devel/rustc-demangle
LIB_DEPENDS=	libdw.so:devel/elfutils \
		libQCustomPlot-qt5.so:graphics/qcustomplot@qt5 \
		libkddockwidgets.so:x11-toolkits/kddockwidgets \
		libzstd.so:archivers/zstd

USES=		cmake desktop-file-utils qt:5 kde:5 pkgconfig xorg
USE_KDE=	ecm \
		archive auth bookmarks codecs completion config configwidgets coreaddons i18n iconthemes \
		itemmodels itemviews jobwidgets kio notifications parts service solid sonnet syntaxhighlighting \
		textwidgets threadweaver widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network svg widgets x11extras xml buildtools:build qmake:build
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	KDAB
GH_TUPLE=	KDAB:perfparser:d84473c:perfparser/3rdparty/perfparser \
		KDAB:PrefixTickLabels:1d56145:PrefixTickLabels/3rdparty/PrefixTickLabels

CMAKE_ARGS=	-DCMAKE_MODULE_PATH=${LOCALBASE}/share/ECM/find-modules

PORTSCOUT=	limit:^.*[0-9]\.[0-9].*$$ # prevent tags like 'continuous'

.include <bsd.port.mk>
