# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=		kio-audiocd
PORTVERSION=		${KDE4_VERSION}
CATEGORIES=		audio kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=		audiocd-kio-${PORTVERSION}
DIST_SUBDIR=		KDE

MAINTAINER=		kde@FreeBSD.org
COMMENT=		KDE IOSlave for accessing audio CDs

LICENSE=		GPLv2

LIB_DEPENDS=		FLAC.10:${PORTSDIR}/audio/flac \
			cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia \
			ogg.8:${PORTSDIR}/audio/libogg \
			vorbis.4:${PORTSDIR}/audio/libvorbis

CONFLICTS_INSTALL=	kdemultimedia-4.[1-8].*

MAKE_JOBS_SAFE=		yes
KDE4_BUILDENV=		yes
USE_KDE4=		kdehier kdelibs kdeprefix libkcddb libkcompactdisc \
			automoc4
USE_QT4=		moc_build qmake_build rcc_build uic_build
USE_XZ=			yes

OPTIONS_DEFINE=		LAME
LAME_DESC=		Install LAME MP3 audio encoder
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	LAME
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=		lame:${PORTSDIR}/audio/lame
.endif

.include <bsd.port.mk>
