# New ports collection makefile for:	AFsp
# Date created:				30 May 2000
# Whom:					Kawaguti Ginga <ginga@athena.club.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	afsp
PORTVERSION=	5.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.tsp.ece.mcgill.ca/pub/AFsp/
DISTNAME=	AFsp-v5r0

MAINTAINER=	ginga@athena.club.ne.jp

USE_GMAKE=	yes

MAN1=	AFsp.1audio CompAudio.1audio CopyAudio.1audio FiltAudio.1audio \
	GenNoise.1audio GenTone.1audio InfoAudio.1audio LPanal.1audio \
	LPsyn.1audio ResampAudio.1audio
MAN3=	AFclose.3tsp AFopenRead.3tsp AFopenWrite.3tsp AFreadData.3tsp \
	AFsetFileType.3tsp AFsetHinfo.3tsp AFwriteData.3tsp AFsetNHpar.3tsp

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-patch:
	cd ${WRKSRC} && find . -name Makefile | \
		xargs -n10 ${PERL} -i -pe 's/^(CFLAGS\s*)=\s*-O/$$1+=/'

.include <bsd.port.mk>
