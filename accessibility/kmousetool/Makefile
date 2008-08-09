# New ports collection Makefile for:	kdeaccessibility
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdeaccessibility
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	accessibility kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibility applications for KDE4

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdelibs workspace kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	opengl gui moc rcc uic

CMAKE_ARGS+=	-DKDE4_KTTSD_ALSA:BOOL=OFF

post-extract:
	${MKDIR} ${WRKSRC}

.include <bsd.port.mk>
