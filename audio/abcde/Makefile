# New ports collection makefile for:	abcde
# Date created:			July 29, 2002
# Whom:				Munish Chopra <mchopra@engmail.uwaterloo.ca>
#
# $FreeBSD$
#

PORTNAME=	abcde
PORTVERSION=	2.1.8
CATEGORIES=	audio
MASTER_SITES=	http://www.hispalinux.es/~data/files/
DISTNAME=	abcde_${PORTVERSION}.orig

MAINTAINER=	chopra@soulwax.net
COMMENT=	Front-end shell script to encode CDs in flac/mp3/ogg/speex format

RUN_DEPENDS=	cd-discid:${PORTSDIR}/audio/cd-discid \
		cdparanoia:${PORTSDIR}/audio/cdparanoia \
		id3v2:${PORTSDIR}/audio/id3v2 \
		lame:${PORTSDIR}/audio/lame \
		oggenc:${PORTSDIR}/audio/vorbis-tools

USE_REINPLACE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAN1=		abcde.1 cddb-tool.1

.if defined(WITH_CDDA2WAV)
RUN_DEPENDS+=	cdda2wav:${PORTSDIR}/sysutils/cdrtools
.else
CDDA2WAV_MSG=	"Define WITH_CDDA2WAV to enable cdda2wav support."
.endif

.if defined(WITH_DAGRAB)
RUN_DEPENDS+=	dagrab:${PORTSDIR}/audio/dagrab
.else
DAGRAB_MSG=	"Define WITH_DAGRAB to enable dagrab support."
.endif

.if defined(WITH_EJECT)
RUN_DEPENDS+=	eject:${PORTSDIR}/sysutils/eject
.else
EJECT_MSG=	"Define WITH_EJECT to enable auto-eject support."
.endif

.if defined(WITH_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.else
FLAC_MSG=	"Define WITH_FLAC to enable FLAC support."
.endif

.if defined(WITH_NORMALIZE)
RUN_DEPENDS+=	normalize:${PORTSDIR}/audio/normalize
.else
NORMALIZE_MSG=	"Define WITH_NORMALIZE to enable normalize support."
.endif

.if defined(WITH_SPEEX)
RUN_DEPENDS+=	speexenc:${PORTSDIR}/audio/speex
.else
SPEEX_MSG=	"Define WITH_SPEEX to enable Speex support."
.endif

pre-fetch:
.if defined(CDDA2WAV_MSG)
	@${ECHO_MSG} ${CDDA2WAV_MSG}
	@${ECHO_MSG} ""
.endif
.if defined(DAGRAB_MSG)
	@${ECHO_MSG} ${DAGRAB_MSG}
	@${ECHO_MSG} ""
.endif
.if defined(EJECT_MSG)
	@${ECHO_MSG} ${EJECT_MSG}
	@${ECHO_MSG} ""
.endif
.if defined(FLAC_MSG)
	@${ECHO_MSG} ${FLAC_MSG}
	@${ECHO_MSG} ""
.endif
.if defined(NORMALIZE_MSG)
	@${ECHO_MSG} ${NORMALIZE_MSG}
	@${ECHO_MSG} ""
.endif
.if defined(SPEEX_MSG)
	@${ECHO_MSG} ${SPEEX_MSG}
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/etc/#${PREFIX}/etc/#g' \
		${WRKSRC}/abcde.1
	@${REINPLACE_CMD} -e 's#/etc/#${PREFIX}/etc/#g' \
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
