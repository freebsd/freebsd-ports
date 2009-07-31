# New ports collection makefile for:	plasma-applet-teacooker
# Date Created:				2008-10-03
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	teacooker
PORTVERSION=	0.3.0
PORTREVISION=	4
CATEGORIES=	deskutils kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	85564-TeaCooker

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Tea cooker plasma applet for KDE4

USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus network opengl svg webkit xml \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/TeaCooker

.include <bsd.port.mk>
