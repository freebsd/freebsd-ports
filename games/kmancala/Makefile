# $FreeBSD$

PORTNAME=	kmancala
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	games kde
MASTER_SITES=	http://horinek.net/~dal/ \
		LOCAL/makc
DISTNAME=	kMancala-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Board game for KDE, also known as Mancala or Kalah

LIB_DEPENDS=	kdegames:${PORTSDIR}/games/kdegames4

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
