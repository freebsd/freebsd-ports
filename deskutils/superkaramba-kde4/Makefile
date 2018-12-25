# $FreeBSD$

PORTNAME=	superkaramba
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	deskutils kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Widget framework for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 python:2.7 qt:4 tar:xz
USE_KDE=	kdelibs automoc4 qimageblitz
USE_QT=		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
USE_CXXSTD=	gnu++98

.include <bsd.port.mk>
