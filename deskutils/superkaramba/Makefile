# New ports collection Makefile for:	superkaramba
# Date created:				2012-02-23
# Whom:					Max Brazhikov <makc@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	superkaramba
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Widget framework for KDE

CONFLICTS=	kdeutils-4.[0-7].*

USE_XZ=	yes
USE_PYTHON=	2.5+
USE_KDE4=	kdehier kdelibs kdeprefix automoc4 qimageblitz
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
