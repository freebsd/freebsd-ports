# Created by: Max Brazhnikov <makc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dolphin-plugins
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugins for Dolphin file manager

USES=		cmake:outsource tar:xz
USE_KDE4=	kdelibs libkonq kdeprefix kdehier automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
