# New ports collection makefile for:	kdebindings4-python-krosspython
# Date created:		2009-02-13
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	krosspython
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde python
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}kdebindings-
DISTNAME=	kross-interpreters-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kross Python scripting library

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_PYTHON=	2.5+
USE_QT_VER=	4
QT_COMPONENTS=	gui qmake_build moc_build uic_build rcc_build
USE_BZIP2=	yes
DISTINFO_FILE=	${PORTSDIR}/devel/kdebindings4-kross-interpreters/distinfo
USE_CMAKE=	yes
CMAKE_ARGS+=	-DBUILD_falcon:BOOL=FALSE \
		-DBUILD_ruby:BOOL=FALSE \
		-DBUILD_java:BOOL=FALSE
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
