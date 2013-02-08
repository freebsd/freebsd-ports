# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=		libkcddb
PORTVERSION=		${KDE4_VERSION}
CATEGORIES=		audio kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=		KDE

MAINTAINER=		kde@FreeBSD.org
COMMENT=		KDE CDDB library

LIB_DEPENDS=		musicbrainz5:${PORTSDIR}/audio/libmusicbrainz5

CONFLICTS_INSTALL=	kdemultimedia-4.[1-8].*

MAKE_JOBS_SAFE=		yes
KDE4_BUILDENV=		yes
USE_KDE4=		automoc4 kdehier kdelibs kdeprefix
USE_QT4=		moc_build qmake_build rcc_build uic_build
USE_XZ=			yes

.include <bsd.port.mk>
