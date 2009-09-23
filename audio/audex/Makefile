# New ports collection makefile for:	audex
# Date Created:				2009-05-20
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	audex
DISTVERSION=	0.72b1
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_GENTOO} \
		http://opensource.maniatek.de/${PORTNAME}/files/
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Audio CD ripping utility for KDE4

LIB_DEPENDS=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia \
		kcddb.5:${PORTSDIR}/multimedia/kdemultimedia4

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus network qt3support sql svg xml \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	FAAC "Depend on audio/faac for m4a encoding" off \
		FLAC "Depend on audio/flac for flac encoding" on \
		LAME "Depend on audio/lame for mp3 encoding" off \
		OGG "Depend on audio/vorbis-tools for ogg encoding" on

.include <bsd.port.pre.mk>

.if defined(WITH_FAAC)
RUN_DEPENDS+=	faac:${PORTSDIR}/audio/faac
.endif

.if defined(WITH_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if defined(WITH_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if defined(WITH_OGG)
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
.endif

.include <bsd.port.post.mk>
