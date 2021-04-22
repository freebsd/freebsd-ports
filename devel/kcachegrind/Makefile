PORTNAME=	kcachegrind
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Profiler frontend for KDE

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 python:run qt:5 \
		shebangfix tar:xz
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons dbusaddons ecm i18n itemviews jobwidgets kio service solid \
		widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build

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
