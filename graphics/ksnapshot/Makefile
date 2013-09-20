# $FreeBSD$

PORTNAME=	ksnapshot
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 screen capture program

CONFLICTS=	kdegraphics-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix libkipi automoc4
USES=		cmake:outsource
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xext xfixes
USE_XZ=		yes

NO_STAGE=	yes
.include <bsd.port.mk>
