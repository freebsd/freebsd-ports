# New ports collection makefile for:	kdevelop
# Date created:		Sun Aug 23 17:14:39 UTC 2009
# Whom:			Golyashov Sergei <svvord@mail.ru>
#
# $FreeBSD$

PORTNAME=	kdevelop
DISTVERSION=	${KDEVELOP_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEVELOP_BRANCH}/kdevelop/${DISTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Opensource IDE based on KDevPlatform, KDE and Qt libraries

LIB_DEPENDS+=	kdevplatforminterfaces.1:${PORTSDIR}/devel/kdevplatform

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GMAKE=	yes
USE_KDE4=	kdelibs kdeprefix automoc4 workspace
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib assistant assistantclient clucene \
		dbus designer help gui multimedia network \
		opengl qt3support qtestlib script sql svg \
		scripttools webkit xml xmlpatterns phonon \
		qmake_build moc_build uic_build rcc_build

OPTIONS=	PHP	"Install PHP support" on

.include <bsd.port.pre.mk>

.ifdef(WITH_PHP)
RUN_DEPENDS+=	kdevelop-php>=0:${PORTSDIR}/devel/kdevelop-php
.endif

.include <bsd.port.post.mk>
