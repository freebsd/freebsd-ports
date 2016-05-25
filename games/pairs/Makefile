# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pairs
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Memory and pairs game for KDE

LICENSE=	GPLv2

USES=		cmake:outsource tar:xz
USE_KDE4=	kdelibs automoc4
USE_QT4=	declarative opengl phonon xmlpatterns \
		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
