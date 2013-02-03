# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kremotecontrol
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	comms kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE frontend for your remote controls

RUN_DEPENDS=	lircd:${PORTSDIR}/comms/lirc

CONFLICTS_INSTALL=	kdeutils-4.[0-7].*

USE_XZ=	yes
USE_KDE4=	kdeprefix kdehier automoc4 kdelibs
KDE4_BUILDENV=	yes
USE_QT4=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
