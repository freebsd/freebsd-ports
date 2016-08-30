# $FreeBSD$

PORTNAME=	kaccessible
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	accessibility kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibility services for KDE

LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	corelib dbus gui xml \
		qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
