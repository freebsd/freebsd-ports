# New ports collection makefile for:	showimage
# Date Created:				2011-11-26
# Whom:					Rusty Nejdl <rnejdl@ringofsaturn.com>
#
# $FreeBSD$
#

PORTNAME=	showimage
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
DISTNAME=	143977-${PORTNAME}-${PORTVERSION}

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	ShowImage is a simple KDE based image viewer

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME}-kde4 \
		share/applications/kde4/${PORTNAME}.desktop \
		share/icons/hicolor/32x32/apps/${PORTNAME}.png

.include <bsd.port.mk>
