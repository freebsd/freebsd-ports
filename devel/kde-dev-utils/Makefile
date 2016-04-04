# $FreeBSD$

PORTNAME=	kde-dev-utils
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE development utilities

USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build \
		corelib designer gui qt3support xml
USES=		cmake:outsource tar:xz

.include <bsd.port.mk>
