# New ports collection makefile for:	plasma-applet-fancytasks
# Date created:		2009-12-06
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	fancytasks
PORTVERSION=	0.9.8
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	99737-${PORTNAME}-${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Plasmoid fancy representation of your tasks and launchers

LIB_DEPENDS=	qimageblitz.4:${PORTSDIR}/x11/qimageblitz

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix kdelibs kdebase workspace
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus network opengl svg phonon webkit xml \
		qmake_build moc_build rcc_build uic_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
