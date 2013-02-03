# $FreeBSD$

PORTNAME=	ksnapshot
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 screen capture program

CONFLICTS=	kdegraphics-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix libkipi automoc4
KDE4_BUILDENV=	yes
USE_QT4=	dbus qmake_build moc_build uic_build rcc_build
USE_XORG=	x11 xext xfixes
USE_XZ=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
