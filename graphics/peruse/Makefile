# $FreeBSD$

PORTNAME=	peruse
DISTVERSION=	1.2-502
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Comic book viewer

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lang pkgconfig kde:5 qt:5 tar:xz
USE_KDE=	archive attica baloo completion config coreaddons crash ecm filemetadata guiaddons i18n \
		iconthemes jobwidgets kdeclarative kio newstuff package service \
		widgetsaddons windowsystem 
USE_QT=		concurrent core dbus declarative gui network opengl sql widgets xml \
		buildtools_build qmake_build

KDE_INVENT=	8d1de5f4a7c4a6ca7444b0c55cb9aaa44a982a78

.include <bsd.port.mk>
