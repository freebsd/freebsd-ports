# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kscd
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	audio kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	CD Player for KDE

LICENSE=	GPLv2

LIB_DEPENDS=	libmusicbrainz3.so:audio/libmusicbrainz3

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	phonon moc_build qmake_build rcc_build uic_build

OPTIONS_DEFINE=	ALSA

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_EXTRA_PATCHES_OFF=	${FILESDIR}/extrapatch-no_alsa

.include <bsd.port.mk>
