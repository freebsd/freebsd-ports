# $FreeBSD$

PORTNAME=	audex
DISTVERSION=	0.74b1
PORTREVISION=	4
CATEGORIES=	audio kde
MASTER_SITES=	http://kde.maniatek.com/${PORTNAME}/files/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Audio CD ripping utility for KDE4

LIB_DEPENDS=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia \
		kcddb.5:${PORTSDIR}/multimedia/kdemultimedia4

USE_XZ=		yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix kdelibs
USE_QT4=	gui dbus network svg xml \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv3

OPTIONS_DEFINE= FAAC FLAC LAME EYED3 OGG
OPTIONS_DEFAULT=	FLAC OGG
EYED3_DESC=	 Unicode mp3 tags support

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MNLS}
CMAKE_ARGS+=	-DDISABLE_ALL_OPTIONAL_SUBDIRECTORIES=TRUE
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
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

.if ${PORT_OPTIONS:MEYED3}
RUN_DEPENDS+=	eyeD3:${PORTSDIR}/audio/py-eyed3
.endif

.if ${PORT_OPTIONS:MOGG}
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
.endif

.include <bsd.port.mk>
