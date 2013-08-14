# New ports collection makefile for:	plasma-applet-teacooker
# Date Created:				2008-10-03
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	teacooker
PORTVERSION=	0.3.0
PORTREVISION=	8
CATEGORIES=	deskutils kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	85564-TeaCooker

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Tea cooker plasma applet for KDE4

USES=		cmake
USE_KDE4=	automoc4 kdeprefix kdelibs
USE_QT4=	gui dbus network opengl svg webkit xml \
		qmake_build moc_build rcc_build uic_build

WRKSRC=		${WRKDIR}/TeaCooker

.include <bsd.port.mk>
