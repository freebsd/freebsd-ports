# $FreeBSD$

PORTNAME=	kruler
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 screen ruler

CONFLICTS=	kdegraphics-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
KDE4_BUILDENV=	yes
USE_QT4=	corelib qmake_build moc_build uic_build rcc_build
USE_XORG=	x11
USE_XZ=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
