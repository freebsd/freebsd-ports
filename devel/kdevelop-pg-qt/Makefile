# New ports collection makefile for:	kdevelop-pg-qt
# Date created:		Thu Nov  4 13:35:29 UTC 2010
# Whom:			Douglas Carmichael <dcarmich@dcarmichael.net>
#
# $FreeBSD$

PORTNAME=	kdevelop
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION}/src
PKGNAMESUFFIX=	-pg-qt
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Parser-generator from KDevplatform

USE_BZIP2=	yes
USE_BISON=	build
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build uic_build rcc_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
