# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kscd
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	audio kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	CD Player for KDE

LICENSE=	GPLv2

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libdiscid.so:audio/libdiscid \
		libmusicbrainz5.so:audio/libmusicbrainz5

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		phonon moc_build qmake_build rcc_build uic_build

OPTIONS_DEFINE=	ALSA

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_EXTRA_PATCHES_OFF=	${FILESDIR}/extrapatch-no_alsa

.include <bsd.port.mk>
