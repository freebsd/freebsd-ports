# $FreeBSD$

PORTNAME=	kmousetool
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	accessibility kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Automatic mouse click tool for KDE

CONFLICTS_INSTALL=	kdeaccessibility-4.[0-7].*

NO_STAGE=	yes
USE_XZ=		yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USES=		cmake:outsource
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_XORG=	xtst

MAN1=	kmousetool.1

.include <bsd.port.mk>
