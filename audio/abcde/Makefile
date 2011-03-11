# New ports collection makefile for:	abcde
# Date created:			July 29, 2002
# Whom:				Munish Chopra <mchopra@engmail.uwaterloo.ca>
#
# $FreeBSD$
#

PORTNAME=	abcde
PORTVERSION=	2.4.2
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Front-end shell script to encode CDs in flac/mp3/ogg/speex format

RUN_DEPENDS=	cd-discid:${PORTSDIR}/audio/cd-discid \
		cdparanoia:${PORTSDIR}/audio/cdparanoia \
		id3v2:${PORTSDIR}/audio/id3v2 \
		lame:${PORTSDIR}/audio/lame \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes
MAN1=		abcde.1 cddb-tool.1

PLIST_FILES=	bin/abcde bin/cddb-tool etc/abcde.conf

OPTIONS=	CDDA2WAV "support cdda2wav to rip CD" Off \
		DAGRAB	"support dagrab to rip IDE CD" Off \
		EJECT	"enable auto-eject support" Off \
		GOGO	"support gogo MP3 encoder" Off \
		BLADEENC	"support BladeEnc MP3 encoder" Off \
		FLAC	"support FLAC format" Off \
		AAC	"support AAC format" Off \
		MPP	"support Musepack format" Off \
		NORMALIZE "enable normalize support" Off \
		REPLAYGAIN "support (vorbis|mp3)gain" Off \
		SPEEX	"enable Speex support" Off

LICENSE=	GPLv2

.include <bsd.port.options.mk>

.if defined(WITH_CDDA2WAV)
USE_CDRTOOLS=	yes
.endif

.if defined(WITH_DAGRAB)
RUN_DEPENDS+=	dagrab:${PORTSDIR}/audio/dagrab
.endif

.if defined(WITH_EJECT)
RUN_DEPENDS+=	eject:${PORTSDIR}/sysutils/eject
.endif

.if defined(WITH_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if defined(WITH_NORMALIZE)
RUN_DEPENDS+=	normalize:${PORTSDIR}/audio/normalize
.endif

.if defined(WITH_SPEEX)
RUN_DEPENDS+=	speexenc:${PORTSDIR}/audio/speex
.endif

.if defined(WITH_GOGO)
RUN_DEPENDS+=	gogo:${PORTSDIR}/audio/gogo
.endif

.if defined(WITH_BLADEENC)
RUN_DEPENDS+=	bladeenc:${PORTSDIR}/audio/bladeenc
.endif

.if defined(WITH_AAC)
RUN_DEPENDS+=	faac:${PORTSDIR}/audio/faac
.endif

.if defined(WITH_MPP)
RUN_DEPENDS+=	mppenc:${PORTSDIR}/audio/musepack
.endif

.if defined(WITH_REPLAYGAIN)
RUN_DEPENDS+=	mp3gain:${PORTSDIR}/audio/mp3gain \
		vorbisgain:${PORTSDIR}/audio/vorbisgain
.endif

post-patch:
	${REINPLACE_CMD} -e 's#/etc/#${PREFIX}/etc/#g' \
		${WRKSRC}/abcde.1
	${REINPLACE_CMD} -e 's#/etc/#${PREFIX}/etc/#g' \
		-e 's#/bin/bash#${LOCALBASE}/bin/bash#g' \
		${WRKSRC}/abcde

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abcde ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cddb-tool ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/abcde.conf ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/abcde.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cddb-tool.1 ${PREFIX}/man/man1

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please copy ${PREFIX}/etc/abcde.conf to ~/.abcde.conf"
	@${ECHO_MSG} "and edit as necessary. Sane defaults have been set."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "NOTE: If you have been using ${PORTNAME}-2.1.4 or older,"
	@${ECHO_MSG} "you must start with a fresh ~/.abcde.conf."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
