# New ports collection makefile for:	AFsp
# Date created:				30 May 2000
# Whom:					Kawaguti Ginga <ginga@athena.club.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	afsp
PORTVERSION=	7.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.tsp.ece.mcgill.ca/pub/AFsp/
DISTNAME=	AFsp-v7r1

MAINTAINER=	ginga-freebsd@ginganet.org
COMMENT=	Audio file conversion utilities and library

USE_GMAKE=	yes

MAN1=	AFsp.1audio CompAudio.1audio CopyAudio.1audio FiltAudio.1audio \
	GenNoise.1audio GenTone.1audio InfoAudio.1audio LPanal.1audio \
	LPsyn.1audio ResampAudio.1audio
MAN3=	AFclose.3tsp AFdReadData.3tsp AFdWriteData.3tsp AFfReadData.3tsp \
	AFfWriteData.3tsp AFopnRead.3tsp AFopnWrite.3tsp AFsetFileType.3tsp \
	AFsetHinfo.3tsp AFsetNHpar.3tsp AFsetSpeaker.3tsp

MAKE_ARGS=	COPTS="${CFLAGS}"

post-extract:
	@${CP} -f ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
