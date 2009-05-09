# New ports collection makefile for:	atunes
# Date Created:		29 Dec 2007
# Whom:			Lars Engels <lme@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	atunes
PORTVERSION=	1.13.0
CATEGORIES=	audio java
MASTER_SITES=	SF
DISTNAME=	aTunes_${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	A full-featured audio player and manager developed in Java

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
SUB_FILES=	atunes

WRKSRC=		${WRKDIR}/aTunes

OPTIONS=	CDDA2WAV "Ripper:  Enable cdrtools support" on \
		LAME "Encoder: Enable lame MP3 encoder" on \
		VORBIS "Encoder: Enable vorbis OGG encoder" on \
		FLAC "Encoder: Enable FLAC encoder" off

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer

.if defined(WITH_CDDA2WAV)
USE_CDRTOOLS=	yes
.endif

.if !defined(WITHOUT_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if defined(WITH_VORBIS)
RUN_DEPENDS+=	ogg123:${PORTSDIR}/audio/vorbis-tools
.endif

.if defined(WITH_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

DESKTOP_ENTRIES="aTunes" \
		"Audio player and manager" \
		"${DATADIR}/aTunes.ico" \
		"aTunes" \
		"Application;Audio;Player;" \
		false

INSTALL_FILES=	aTunes.ico aTunes.jar build.properties changelog.txt \
		extendedLog.properties license.txt log4j.properties \
		presets.properties shortcutSpec.xml

do-install:
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/lib
	@${MKDIR} ${DATADIR}/settings
	@${MKDIR} ${DATADIR}/translations
	${INSTALL_SCRIPT} ${WRKDIR}/atunes ${PREFIX}/bin
.for file in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}/${file}
.endfor
	cd ${WRKSRC} && ${FIND} translations -type f -exec ${INSTALL_DATA} {} \
		${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} lib -type f -name "*.jar" -exec ${INSTALL_DATA} {} \
		${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} settings -type f -exec ${INSTALL_DATA} {} \
		${DATADIR}/{} \;

.include <bsd.port.post.mk>
