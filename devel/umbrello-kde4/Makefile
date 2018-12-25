# $FreeBSD$

PORTNAME=	umbrello
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	12
CATEGORIES=	devel kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	UML modeller for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_GNOME=	libxml2 libxslt
USE_QT=		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
