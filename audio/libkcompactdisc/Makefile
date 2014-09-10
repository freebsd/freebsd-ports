# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libkcompactdisc
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for interfacing with audio CDs

USES=		cmake:outsource tar:xz
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
USE_QT4=	phonon moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ALSA

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_EXTRA_PATCHES=	${FILESDIR}/extrapatch-no_alsa

.include <bsd.port.mk>
