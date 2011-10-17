# New ports collection makefile for:	skanlite
# Date created:		2008-09-01
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	skanlite
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	SF/sanewidget/Skanlite/
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple image scanning application for KDE

LIB_DEPENDS=	ksane.0:${PORTSDIR}/graphics/libksane

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
