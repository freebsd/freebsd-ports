# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=		pairs
PORTVERSION=		${KDE4_VERSION}
CATEGORIES=		games kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=		KDE

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Memory and pairs game for KDE

LICENSE=		GPLv2

KDE4_BUILDENV=		yes
MAKE_JOBS_SAFE=		yes
USE_KDE4=		kdehier kdelibs kdeprefix automoc4
USE_QT4=		declarative opengl phonon xmlpatterns \
			moc_build qmake_build rcc_build uic_build
USE_XZ=			yes

.include <bsd.port.mk>
