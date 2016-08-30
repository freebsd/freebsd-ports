# $FreeBSD$

PORTNAME=	kturtle
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	lang kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Educational programming environment for KDE 4

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	corelib gui xml moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
