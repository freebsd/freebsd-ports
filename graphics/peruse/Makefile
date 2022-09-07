PORTNAME=	peruse
DISTVERSION=	1.2-502
PORTREVISION=	1
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Comic book viewer

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lang gl pkgconfig kde:5 qt:5 tar:xz xorg
USE_GL=		gl
USE_KDE=	archive attica baloo completion config coreaddons crash ecm \
		filemetadata guiaddons i18n iconthemes jobwidgets \
		kdeclarative kio newstuff package service solid \
		widgetsaddons windowsystem
USE_QT=		concurrent core dbus declarative gui network opengl sql widgets xml \
		buildtools_build qmake_build
USE_XORG=	x11

KDE_INVENT=	8d1de5f4a7c4a6ca7444b0c55cb9aaa44a982a78

.include <bsd.port.mk>
