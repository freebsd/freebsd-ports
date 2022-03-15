PORTNAME=	kross-interpreters
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	lang kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Language interpreters to enable in-process scripting with Kross

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	kross \
		ecm_build
USE_QT=		core gui script widgets xml \
		buildtools_build qmake_build

CFLAGS+=	-fdeclspec

OPTIONS_DEFINE=		RUBY DOCS
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_PythonLibs

RUBY_USE=		ruby
RUBY_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Ruby

.include <bsd.port.mk>
