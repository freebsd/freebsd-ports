# Created by: Munish Chopra <mchopra@engmail.uwaterloo.ca>
# $FreeBSD$

PORTNAME=	abcde
PORTVERSION=	2.5.4
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Front-end shell script to encode CDs in flac/mp3/ogg/speex format

LICENSE=	GPLv2

RUN_DEPENDS=	cd-discid:${PORTSDIR}/audio/cd-discid \
		cdparanoia:${PORTSDIR}/audio/cdparanoia \
		${PYTHON_PKGNAMEPREFIX}eyed3-06>0:${PORTSDIR}/audio/py-eyed3-06 \
		lame:${PORTSDIR}/audio/lame \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes

OPTIONS_DEFINE=	CDDA2WAV DAGRAB EJECT FLAC MPP NORMALIZE REPLAYGAIN SPEEX

EJECT_DESC?=	Enable auto-eject support
NORMALIZE_DESC?=	Enable normalize support
REPLAYGAIN_DESC?=	Enable (vorbis|mp3)gain support

USES=		shebangfix
SHEBANG_FILES=	${PORTNAME} cddb-tool

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCDDA2WAV}
RUN_DEPENDS+=	cdda2wav:${PORTSDIR}/sysutils/cdrtools
.endif

.if ${PORT_OPTIONS:MDAGRAB}
RUN_DEPENDS+=	dagrab:${PORTSDIR}/audio/dagrab
.endif

.if ${PORT_OPTIONS:MEJECT}
RUN_DEPENDS+=	eject:${PORTSDIR}/sysutils/eject
.endif

.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if ${PORT_OPTIONS:MNORMALIZE}
RUN_DEPENDS+=	normalize:${PORTSDIR}/audio/normalize
.endif

.if ${PORT_OPTIONS:MSPEEX}
RUN_DEPENDS+=	speexenc:${PORTSDIR}/audio/speex
.endif

.if ${PORT_OPTIONS:MAAC}
RUN_DEPENDS+=	faac:${PORTSDIR}/audio/faac
.endif

.if ${PORT_OPTIONS:MMPP}
RUN_DEPENDS+=	mpcenc:${PORTSDIR}/audio/musepack
.endif

.if ${PORT_OPTIONS:MREPLAYGAIN}
RUN_DEPENDS+=	mp3gain:${PORTSDIR}/audio/mp3gain \
		vorbisgain:${PORTSDIR}/audio/vorbisgain
.endif

post-patch:
	${REINPLACE_CMD} -e 's#/etc/#${PREFIX}/etc/#g' \
		${WRKSRC}/abcde.1
	${REINPLACE_CMD} -e 's#/etc/#${PREFIX}/etc/#g' \
		${WRKSRC}/abcde

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
