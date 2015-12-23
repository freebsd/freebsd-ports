# $FreeBSD$

PORTNAME=	audex
PORTVERSION=	0.79
CATEGORIES=	audio kde
MASTER_SITES=	http://kde.maniatek.com/${PORTNAME}/files/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE4 audio CD ripping utility

LICENSE=	GPLv3

BROKEN=		unfetchable

LIB_DEPENDS=	libcdda_paranoia.so:${PORTSDIR}/audio/cdparanoia

USES=		tar:xz cmake
USE_KDE4=	automoc4 kdeprefix kdelibs libkcddb libkcompactdisc
USE_QT4=	gui dbus network svg xml \
		qmake_build moc_build rcc_build uic_build

OPTIONS_DEFINE=		NLS EYED3 FAAC FLAC LAME VORBIS
OPTIONS_DEFAULT=	FLAC VORBIS
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=	yes

NLS_USES=		gettext
NLS_CMAKE_OFF=		-DDISABLE_ALL_OPTIONAL_SUBDIRECTORIES=TRUE

EYED3_DESC=		Unicode MP3 tag support via audio/py-eyed3
EYED3_RUN_DEPENDS=	eyeD3:${PORTSDIR}/audio/py-eyed3

FAAC_RUN_DEPENDS=	faac:${PORTSDIR}/audio/faac

FLAC_RUN_DEPENDS=	flac:${PORTSDIR}/audio/flac

LAME_RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame

VORBIS_RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools

.include <bsd.port.mk>
