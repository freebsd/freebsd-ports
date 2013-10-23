# $FreeBSD$

PORTNAME=	kmancala
PORTVERSION=	1.0.2
PORTREVISION=	4
CATEGORIES=	games kde
MASTER_SITES=	http://horinek.net/~dal/ \
		LOCAL/makc
DISTNAME=	kMancala-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Board game for KDE, also known as Mancala or Kalah

USE_BZIP2=	yes
USES=		cmake:outsource
USE_KDE4=	kdelibs kdeprefix automoc4 libkdegames
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
