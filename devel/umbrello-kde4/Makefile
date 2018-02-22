# $FreeBSD$

PORTNAME=	umbrello
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	9
CATEGORIES=	devel kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	UML modeller for KDE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_GNOME=	libxml2 libxslt
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
