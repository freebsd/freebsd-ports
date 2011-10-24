# New ports collection makefile for:	plasma-applet-icontasks
# Date created:				24 October 2011
# Whom:					avilla@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	icontasks
PORTVERSION=	0.8.0
CATEGORIES=	deskutils kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	144808-plasma-${PORTNAME}-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Modified version of KDE SC taskbar applet and taskmanager library

LIB_DEPENDS=	dbusmenu-qt.2:${PORTSDIR}/devel/libdbusmenu-qt

USE_KDE4=	automoc4 kdehier kdelibs kdeprefix workspace
USE_QT_VER=	4
QT_COMPONENTS=	dbus moc_build qmake_build rcc_build uic_build
USE_XORG=	xcomposite xfixes xrender
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/plasma-${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
