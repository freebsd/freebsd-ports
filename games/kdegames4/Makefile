# New ports collection Makefile for:	kdegames
# Date created:				2008-02-08
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdegames
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Games for the KDE integrated X11 desktop

LIB_DEPENDS=	ggzcore.9:${PORTSDIR}/games/ggz-client-libs

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	opengl gui moc rcc uic svg iconengines pixeltool

post-extract:
	${MKDIR} ${WRKSRC}

.include <bsd.port.mk>
