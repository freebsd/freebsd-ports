# $FreeBSD$

PORTNAME=	kmancala
PORTVERSION=	1.0.2
PORTREVISION=	7
CATEGORIES=	games kde
MASTER_SITES=	http://horinek.net/~dal/ \
		LOCAL/makc
DISTNAME=	kMancala-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Board game for KDE, also known as Mancala or Kalah

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USES=		cmake:outsource tar:bzip2
USE_KDE4=	kdelibs automoc4 libkdegames
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
