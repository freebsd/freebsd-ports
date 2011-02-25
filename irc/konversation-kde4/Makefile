# New ports collection makefile for:	konversation
# Date created:				15 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	konversation
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	irc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${DISTVERSION}/src

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A user friendly IRC client for KDE

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_XORG=	x11 xscrnsaver
USE_KDE4=	kdeprefix pimlibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
