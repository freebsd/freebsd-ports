# New ports collection makefile for:	knight
# Date created:		24 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	knights
PORTVERSION=	2.0
CATEGORIES=	games kde
MASTER_SITES=   http://www.kde-look.org/CONTENT/content-files/
DISTNAME=       122046-${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	syncer@gmail.com
COMMENT=	A KDE4 chess interface

LIB_DEPENDS=	kdegames.5:${PORTSDIR}/games/kdegames4
RUN_DEPENDS=	${LOCALBASE}/bin/gnuchess:${PORTSDIR}/games/gnuchess

WRKSRC=         ${WRKDIR}/Knights
LATEST_LINK=	${PORTNAME}-kde4
USE_CMAKE=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
