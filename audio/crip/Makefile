# New ports collection makefile for:	crip
# Date created:				30 June 2003
# Whom:	      				Philip Paeps <philip@paeps.cx>
#
# $FreeBSD$
#

PORTNAME=	crip
PORTVERSION=	3.5
CATEGORIES=	audio
MASTER_SITES=	http://bach.dynet.com/crip/src/

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Terminal-based ripper/encoder/tagger

RUN_DEPENDS=	${SITE_PERL}/CDDB_get.pm:${PORTSDIR}/audio/p5-CDDB_get \
		cdparanoia:${PORTSDIR}/audio/cdparanoia \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		vorbisgain:${PORTSDIR}/audio/vorbisgain

.if !defined(NOPORTDOCS)
PORTDOCS=	Changelog README criprc_example
.endif

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/wav_find_beginning ${WRKSRC}/wav_find_beginning.c
	${CC} ${CFLAGS} -o ${WRKSRC}/wav_find_end ${WRKSRC}/wav_find_end.c

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/crip ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/editcomment ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/editfilenames ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/wav_find_beginning ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/wav_find_end ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
