# $FreeBSD$

PORTNAME=	audex
DISTVERSION=	0.74b1
PORTREVISION=	5
CATEGORIES=	audio kde
MASTER_SITES=	http://kde.maniatek.com/${PORTNAME}/files/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Audio CD ripping utility for KDE4

LICENSE=	GPLv3

LIB_DEPENDS=	cdda_paranoia:${PORTSDIR}/audio/cdparanoia

USE_XZ=		yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix kdelibs libkcddb
USE_QT4=	gui dbus network svg xml \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=		NLS EYED3 FAAC FLAC LAME VORBIS
OPTIONS_DEFAULT=	FLAC VORBIS
NO_OPTIONS_SORT=	yes

EYED3_DESC=		Unicode MP3 tag support via audio/py-eyed3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DDISABLE_ALL_OPTIONAL_SUBDIRECTORIES=TRUE
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MEYED3}
RUN_DEPENDS+=	eyeD3:${PORTSDIR}/audio/py-eyed3
.endif

.if ${PORT_OPTIONS:MFAAC}
RUN_DEPENDS+=	faac:${PORTSDIR}/audio/faac
.endif

.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if ${PORT_OPTIONS:MVORBIS}
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
.endif

.include <bsd.port.mk>
