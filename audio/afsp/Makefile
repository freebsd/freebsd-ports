# New ports collection makefile for:	AFsp
# Date created:				30 May 2000
# Whom:					Kawaguti Ginga <ginga@athena.club.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	afsp
PORTVERSION=	6.6a
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.tsp.ece.mcgill.ca/pub/AFsp/
DISTNAME=	AFsp-v6r6a

MAINTAINER=	ginga-freebsd@ginganet.org

USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=	AFsp.1audio CompAudio.1audio CopyAudio.1audio FiltAudio.1audio \
	GenNoise.1audio GenTone.1audio InfoAudio.1audio LPanal.1audio \
	LPsyn.1audio ResampAudio.1audio
MAN3=	AFclose.3tsp AFopenRead.3tsp AFopenWrite.3tsp AFreadData.3tsp \
	AFsetFileType.3tsp AFsetHinfo.3tsp AFsetNHpar.3tsp \
	AFwriteData.3tsp AFsetSpeaker.3tsp

MAKE_ENV=	COPTS="${CFLAGS}"

post-extract:
	@${CP} -f ${FILESDIR}/Makefile ${WRKSRC}

post-patch:
	cd ${WRKSRC} && find . -name Makefile | \
		xargs -n10 ${REINPLACE_CMD} -e 's/^(COPTS)/#$$1/'

.include <bsd.port.mk>
