PORTNAME=	kcachegrind
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Profiler frontend for KDE
WWW=		https://www.kde.org

USES=		cmake compiler:c++11-lang desktop-file-utils gettext-tools gl kde:6 \
		qt:6 shebangfix tar:xz xorg \
		python:run
USE_GL=		gl opengl
USE_KDE=	archive config coreaddons dbusaddons i18n kio \
		widgetsaddons xmlgui \
		ecm:build
USE_QT=		base \
		declarative:build tools:build
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
