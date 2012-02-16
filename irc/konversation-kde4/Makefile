# New ports collection makefile for:	konversation
# Date created:				15 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	konversation
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	irc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${DISTVERSION}/src

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A user friendly IRC client for KDE

LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca

LATEST_LINK=	${PORTNAME}-kde4

USE_XZ=		yes
USE_CMAKE=	yes
USE_KDE4=	kdeprefix pimlibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
