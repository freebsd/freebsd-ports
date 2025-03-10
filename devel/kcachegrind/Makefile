PORTNAME=	kcachegrind
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Profiler frontend for KDE
WWW=		https://www.kde.org

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		qt:6 shebangfix tar:xz xorg \
		python:run
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons dbusaddons i18n itemviews jobwidgets kio service \
		solid widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

SHEBANG_FILES=	converters/dprof2calltree \
		converters/hotshot2calltree.in \
		converters/memprof2calltree \
		converters/op2calltree

OPTIONS_DEFINE=	DOT VALGRIND DOCS

DOT_DESC=		Use GraphViz/dot to render call graphs
DOT_RUN_DEPENDS=	dot:graphics/graphviz

VALGRIND_DESC=		Install devel/valgrind
VALGRIND_RUN_DEPENDS=	valgrind:devel/valgrind

.include <bsd.port.mk>
