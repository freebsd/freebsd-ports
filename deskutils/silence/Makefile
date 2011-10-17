# New ports collection makefile for: silence
# Date created:		21 May 2010
# Whom:			Mina R Waheeb <syncer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	silence
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	124776-${PORTNAME}-${PORTVERSION}

MAINTAINER=	syncer@gmail.com
COMMENT=	An information management tool

RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/katepart.so:${PORTSDIR}/editors/kate

USE_CMAKE=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build linguist_build

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
