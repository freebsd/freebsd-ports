# $FreeBSD$

PORTNAME=	kaccessible
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	accessibility kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibility services for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		corelib dbus gui xml \
		qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
