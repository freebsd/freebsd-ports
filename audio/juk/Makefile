# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=		juk
PORTVERSION=		${KDE4_VERSION}
CATEGORIES=		audio kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=		KDE

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Juk is a jukebox, tagger and music collection manager

LICENSE=		GPLv2

LIB_DEPENDS=		tag.1:${PORTSDIR}/audio/taglib

CONFLICTS_INSTALL=	kdemultimedia-4.[1-8].*

CMAKE_ARGS=		-DWITH_TunePimp:BOOL=OFF
MAKE_JOBS_SAFE=		yes
KDE4_BUILDENV=		yes
USE_KDE4=		automoc4 kdehier kdelibs kdeprefix
USE_QT4=		dbus qt3support svg \
			moc_build qmake_build rcc_build uic_build
USE_XZ=			yes

.include <bsd.port.mk>
