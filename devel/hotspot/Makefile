PORTNAME=	hotspot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Perf GUI for performance analysis (needs mock 'perf' command)
WWW=		https://github.com/KDAB/hotspot

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/librustc_demangle.a:devel/rustc-demangle
LIB_DEPENDS=	libdw.so:devel/elfutils \
		libQCustomPlotQt6.so:graphics/qcustomplot@qt6 \
		libkddockwidgets-qt6.so:x11-toolkits/kddockwidgets \
		libkgraphviewer.so:graphics/kgraphviewer \
		libzstd.so:archivers/zstd

USES=		cmake desktop-file-utils gettext-tools qt:6 kde:6 pkgconfig xorg
USE_KDE=	ecm \
		archive auth bookmarks codecs completion config configwidgets coreaddons i18n iconthemes \
		itemmodels itemviews jobwidgets kio notifications parts service solid sonnet syntaxhighlighting \
		textwidgets threadweaver widgetsaddons windowsystem xmlgui
USE_QT=		base declarative
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	KDAB
GH_TUPLE=	KDAB:perfparser:851ebf0:perfparser/3rdparty/perfparser \
		koenpoppe:PrefixTickLabels:6e86393:PrefixTickLabels/3rdparty/PrefixTickLabels

CMAKE_ON=	QT6_BUILD
CMAKE_ARGS=	-DCMAKE_MODULE_PATH=${LOCALBASE}/share/ECM/find-modules

PORTSCOUT=	limit:^.*[0-9]\.[0-9].*$$ # prevent tags like 'continuous'

.include <bsd.port.mk>
