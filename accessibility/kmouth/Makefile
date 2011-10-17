# New ports collection Makefile for:	kdeaccessibility
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdeaccessibility
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	accessibility kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibility applications for KDE4

LIB_DEPENDS=	speechd.5:${PORTSDIR}/accessibility/speech-dispatcher

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui qmake_build moc_build rcc_build uic_build
USE_XORG=	x11 xext xtst
MAKE_JOBS_SAFE=	yes
CMAKE_ARGS+=	-DBUILD_jovie=OFF

MAN1=	kmag.1 \
	kmousetool.1 \
	kmouth.1

OPTIONS=	JOVIE "Install Jovie text-to-speech system" on

.include <bsd.port.options.mk>

.ifndef(WITHOUT_JOVIE)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/jovie:${PORTSDIR}/accessibility/jovie
.endif

.include <bsd.port.mk>
