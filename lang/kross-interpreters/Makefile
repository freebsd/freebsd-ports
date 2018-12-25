# $FreeBSD$

PORTNAME=	kross-interpreters
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	lang kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Language interpreters to enable in-process scripting with Kross

USES=		cmake gettext kde:5 python:2.7 qt:5 tar:xz
USE_KDE=	ecm kross
USE_QT=		core gui script widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=		RUBY DOCS
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

RUBY_USE=		ruby
RUBY_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Ruby

.include <bsd.port.mk>
