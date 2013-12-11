# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	juk
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Jukebox, tagger and music collection manager

LICENSE=	GPLv2

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib

CONFLICTS_INSTALL=	kdemultimedia-4.[1-8].*

USES=		cmake:outsource
NO_STAGE=	yes
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_XZ=		yes

CMAKE_ARGS=	-DWITH_TunePimp:BOOL=OFF

.include <bsd.port.mk>
