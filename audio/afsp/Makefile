# Created by: Kawaguti Ginga <ginga@athena.club.ne.jp>
# $FreeBSD$

PORTNAME=	afsp
PORTVERSION=	8.2
CATEGORIES=	audio
MASTER_SITES=	http://www-mmsp.ece.mcgill.ca/Documents/Downloads/AFsp/
DISTNAME=	AFsp-v8r2

MAINTAINER=	ginga-freebsd@ginganet.org
COMMENT=	Audio file conversion utilities and library

USES=		gmake
MAKE_JOBS_UNSAFE=	yes

MAN1=	AFsp.1audio CompAudio.1audio CopyAudio.1audio FiltAudio.1audio \
	GenNoise.1audio GenTone.1audio InfoAudio.1audio LPanal.1audio \
	LPsyn.1audio PQevalAudio.1audio ResampAudio.1audio
MAN3=	AFclose.3tsp AFdReadData.3tsp AFdWriteData.3tsp AFfReadData.3tsp \
	AFfWriteData.3tsp AFopnRead.3tsp AFopnWrite.3tsp AFsetFileType.3tsp \
	AFsetInfo.3tsp AFsetNHpar.3tsp AFsetSpeaker.3tsp

MAKE_ARGS=	COPTS="${CFLAGS}"

post-extract:
	@${CP} -f ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
