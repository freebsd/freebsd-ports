# New ports collection makefile for:	abcde
# Date created:			July 29, 2002
# Whom:				Munish Chopra <mchopra@engmail.uwaterloo.ca>
#
# $FreeBSD$
#

PORTNAME=	abcde
PORTVERSION=	2.1.9
PORTREVISION=	1
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

pre-everything::
	@${ECHO}
	@${ECHO} "You can build ${PORTNAME} with the following options:"
	@${ECHO} "WITH_CDDA2WAV         enable cdda2wav support"
	@${ECHO} "WITH_DAGRAB           enable dagrab support"
	@${ECHO} "WITH_EJECT            enable auto-eject support"
	@${ECHO} "WITH_FLAC             enable FLAC support"
	@${ECHO} "WITH_NORMALIZE        enable normalize support"
	@${ECHO} "WITH_SPEEX            enable Speex support"
	@${ECHO}

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
