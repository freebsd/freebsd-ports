# $FreeBSD$

PORTNAME=	libkmahjongg
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for the Mahjongg Solitaire for KDE 4

CONFLICTS_INSTALL=	kdegames-4.[0-9].*

USE_KDE4=	kdehier kdelibs kdeprefix libkdegames automoc4
USES=		cmake:outsource
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_XZ=		yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
