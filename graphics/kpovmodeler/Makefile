# New ports collection makefile for:	kpovmodeler
# Date created:		2008-07-31
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kpovmodeler
PORTVERSION=	1.1.3
DISTVERSIONSUFFIX=	-kde${EXTRA_VER}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${EXTRA_VER}/src/extragear
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A KDE editor/frontend for Povray

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl
USE_CMAKE=	yes
USE_GETTEXT=	yes

EXTRA_VER=	4.1.0

.include <bsd.port.mk>
