# $FreeBSD$

PORTNAME=	jovie
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	accessibility kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE text-to-speech system

LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher

USES=		cmake:outsource tar:xz
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT4=	xml qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
