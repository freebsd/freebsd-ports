# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kscd
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	audio kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	CD Player for KDE

LICENSE=	GPLv2

LIB_DEPENDS=	libmusicbrainz3.so:${PORTSDIR}/audio/libmusicbrainz3

USES=		cmake:outsource tar:xz
USE_KDE4=	kdehier kdelibs kdeprefix libkcddb libkcompactdisc \
		automoc4
USE_QT4=	phonon moc_build qmake_build rcc_build uic_build

OPTIONS_DEFINE=	ALSA

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_EXTRA_PATCHES=	${FILESDIR}/extrapatch-no_alsa

.include <bsd.port.mk>

