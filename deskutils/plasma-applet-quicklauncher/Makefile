# New ports collection makefile for:	plasma-applet-quicklauncher
# Date Created:				2008-09-21
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	quicklauncher
PORTVERSION=	0.5
CATEGORIES=	deskutils kde
MASTER_SITES=	http://www.svenstorp.com/plasma/applets/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Quicklauncher plasma applet for KDE4

USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix workspace
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus network opengl svg webkit xml \
		qmake_build moc_build rcc_build uic_build

BROKEN=		Does not compile with KDE 4.2
DEPRECATED=	Abandoned upstream, use Quicklaunch applet included with KDE 4.2
EXPIRATION_DATE=	2009-07-10

WRKSRC=		${WRKDIR}/${DISTNAME}/src/

PLIST_FILES=	lib/kde4/plasma_applet_quicklauncher.so \
		share/kde4/services/plasma-applet-quicklauncher.desktop

.include <bsd.port.mk>
