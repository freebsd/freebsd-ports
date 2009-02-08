# New ports collection makefile for:	automoc4
# Date created:				today
# Whom:					miwi
#
# $FreeBSD$

PORTNAME=	automoc4
PORTVERSION=	0.9.88
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Automatic moc for Qt 4 packages

USE_BZIP2=	yes
USE_ICONV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc rcc_build uic_build
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes

.include <bsd.port.mk>
