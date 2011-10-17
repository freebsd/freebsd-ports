# New ports collection makefile for:	kdebindings4-smoke
# Date created:		2008-08-19
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	smokeqt
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	kdebindings-smoke-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for Qt

LIB_DEPENDS=	qscintilla2.5:${PORTSDIR}/devel/qscintilla2 \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt5 \
		smokebase.3:${PORTSDIR}/devel/kdebindings4-smoke-smokegen

CONFLICTS=	kdebindings-smoke-4.[0-6].*

USE_KDE4=	kdehier kdeprefix
USE_QT_VER=	4
QT_COMPONENTS=	dbus declarative designer gui help multimedia \
		network opengl phonon qt3support qtestlib \
		script sql svg xml xmlpatterns webkit \
		qmake_build moc_build uic_build rcc_build
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
CFLAGS+=	-I/usr/local/include
USE_LDCONFIG=	yes

.include <bsd.port.mk>
