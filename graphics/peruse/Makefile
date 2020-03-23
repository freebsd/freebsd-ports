# $FreeBSD$

PORTNAME=	peruse
DISTVERSION=	1.2-186
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g4982089
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Comic book viewer

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lang pkgconfig kde:5 qt:5 tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	KDE
USE_KDE=	archive baloo completion config coreaddons ecm filemetadata i18n \
		iconthemes jobwidgets kdeclarative kio package service \
		widgetsaddons
USE_QT=		concurrent core dbus declarative gui network opengl sql widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
