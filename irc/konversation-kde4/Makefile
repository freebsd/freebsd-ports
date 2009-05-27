# New ports collection makefile for:	konversation
# Date created:				15 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	konversation
DISTVERSION=	1.2-alpha1
CATEGORIES=	irc kde
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A user friendly IRC client for KDE

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_XORG=	x11 xscrnsaver
USE_KDE4=	kdeprefix pimlibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
