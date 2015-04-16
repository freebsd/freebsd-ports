# Created by: Munish Chopra <mchopra@engmail.uwaterloo.ca>
# $FreeBSD$

PORTNAME=	abcde
PORTVERSION=	2.6
CATEGORIES=	audio
MASTER_SITES=	http://abcde.einval.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Front-end shell script to encode CDs in flac/mp3/ogg/speex format

LICENSE=	GPLv2

RUN_DEPENDS=	cd-discid:${PORTSDIR}/audio/cd-discid \
		cdparanoia:${PORTSDIR}/audio/cdparanoia \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		lame:${PORTSDIR}/audio/lame \
		${PYTHON_PKGNAMEPREFIX}eyed3>=0.7:${PORTSDIR}/audio/py-eyed3 \
		bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes
USES=		python:run shebangfix
SHEBANG_FILES=	${PORTNAME} cddb-tool

OPTIONS_GROUP=		CODEC RIPPER
OPTIONS_GROUP_CODEC=	AAC FLAC MPP OPUS SPEEX
OPTIONS_GROUP_RIPPER=	CDDA2WAV DAGRAB
OPTIONS_DEFINE=		NORMALIZE REPLAYGAIN

NORMALIZE_DESC?=	Enable normalize support
REPLAYGAIN_DESC?=	Enable (vorbis|mp3)gain support

AAC_RUN_DEPENDS+=	faac:${PORTSDIR}/audio/faac
FLAC_RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
MPP_RUN_DEPENDS+=	mpcenc:${PORTSDIR}/audio/musepack
OPUS_RUN_DEPENDS+=	opusenc:${PORTSDIR}/audio/opus-tools
SPEEX_RUN_DEPENDS+=	speexenc:${PORTSDIR}/audio/speex
CDDA2WAV_RUN_DEPENDS+=	cdda2wav:${PORTSDIR}/sysutils/cdrtools
DAGRAB_RUN_DEPENDS+=	dagrab:${PORTSDIR}/audio/dagrab
NORMALIZE_RUN_DEPENDS+=	normalize:${PORTSDIR}/audio/normalize
REPLAYGAIN_RUN_DEPENDS+=mp3gain:${PORTSDIR}/audio/mp3gain \
			vorbisgain:${PORTSDIR}/audio/vorbisgain

PLIST_FILES=	bin/abcde bin/cddb-tool etc/abcde.conf.sample \
		man/man1/abcde.1.gz man/man1/cddb-tool.1.gz

post-patch:
	${REINPLACE_CMD} -e 's#/etc/#${PREFIX}/etc/#g' \
		${WRKSRC}/abcde ${WRKSRC}/abcde.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abcde ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cddb-tool ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/abcde.conf \
		${STAGEDIR}${PREFIX}/etc/abcde.conf.sample
	${INSTALL_MAN} ${WRKSRC}/abcde.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cddb-tool.1 ${STAGEDIR}${PREFIX}/man/man1

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please copy ${PREFIX}/etc/abcde.conf.sample to ~/.abcde.conf"
	@${ECHO_MSG} "and edit as necessary. Sane defaults have been set."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "NOTE: If you have been using ${PORTNAME}-2.1.4 or older,"
	@${ECHO_MSG} "you must start with a fresh ~/.abcde.conf."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
