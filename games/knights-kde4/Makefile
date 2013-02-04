# Created by: Stefan Jahn <stefan.jahn@nemesis-sektor.de>
# $FreeBSD$

PORTNAME=	knights
PORTVERSION=	2.3.1
PORTREVISION=	2
CATEGORIES=	games kde
MASTER_SITES=	http://dl.dropbox.com/u/2888238/Knights/

MAINTAINER=	syncer@gmail.com
COMMENT=	KDE4 chess interface

LIB_DEPENDS=	kdegames:${PORTSDIR}/games/kdegames4
RUN_DEPENDS=	${LOCALBASE}/bin/gnuchess:${PORTSDIR}/games/gnuchess

BROKEN=		does not build with kdegames4>=4.9.0

LATEST_LINK=	${PORTNAME}-kde4
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT4=	qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
