# New ports collection makefile for:	crip
# Date created:				30 June 2003
# Whom:	      				Philip Paeps <philip@paeps.cx>
#
# $FreeBSD$
#

PORTNAME=	crip
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://bach.dynet.com/crip/src/

MAINTAINER=	philip@paeps.cx
COMMENT=	Terminal-based ripper/encoder/tagger

RUN_DEPENDS=	${SITE_PERL}/CDDB_get.pm:${PORTSDIR}/audio/p5-CDDB_get \
		cdparanoia:${PORTSDIR}/audio/cdparanoia \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		vorbisgain:${PORTSDIR}/audio/vorbisgain

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/wav_find_beginning ${WRKSRC}/wav_find_beginning.c
	${CC} ${CFLAGS} -o ${WRKSRC}/wav_find_end ${WRKSRC}/wav_find_end.c

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/crip ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/editcomment ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/wav_find_beginning ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/wav_find_end ${PREFIX}/bin

.include <bsd.port.mk>
