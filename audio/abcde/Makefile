# New ports collection makefile for:	abcde
# Date created:			July 29, 2002
# Whom:				Munish Chopra <mchopra@engmail.uwaterloo.ca>
#
# $FreeBSD$
#

PORTNAME=	abcde
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://frantica.lly.org/~rcw/abcde/
DISTNAME= 	abcde_2.0.3.orig

MAINTAINER=	mchopra@engmail.uwaterloo.ca

RUN_DEPENDS=    cd-discid:${PORTSDIR}/audio/cd-discid \
		dagrab:${PORTSDIR}/audio/dagrab \
		id3v2:${PORTSDIR}/audio/id3v2 \
		oggenc:${PORTSDIR}/audio/vorbis-tools \

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

.if defined(WITH_CDDA2WAV)
RUN_DEPENDS+=	cdda2wav:${PORTSDIR}/sysutils/cdrtools
.endif

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build option:"
	@${ECHO_MSG} "WITH_CDDA2WAV=yes           enable support for cdda2wav"
	@${ECHO_MSG} ""

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

.include <bsd.port.mk>
