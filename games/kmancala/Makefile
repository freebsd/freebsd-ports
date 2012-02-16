# New ports collection makefile for:	kmancala
# Date created:		2011-05-26
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kmancala
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	http://horinek.net/~dal/ \
		LOCAL/makc
DISTNAME=	kMancala-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A board game for KDE, also known as Mancala or Kalah

LIB_DEPENDS=	kdegames.5:${PORTSDIR}/games/kdegames4

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
