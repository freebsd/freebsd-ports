# Created by: Sue Blake <sue@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abcmidi
PORTVERSION=	2011.04.29
CATEGORIES=	audio
MASTER_SITES=	http://ifdo.ca/~seymour/runabc/
DISTNAME=	abcMIDI-${PORTVERSION:S/./-/g}
EXTRACT_SUFX=	.zip

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Convert abc music files to MIDI and PostScript

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake
MAKEFILE=	makefiles/unix.mak
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DANSILIBS -c" LNK="${CC}"

MANPAGES=		abc2abc.1 abc2midi.1 mftext.1 midi2abc.1 midicopy.1 yaps.1

do-install:
.for FILE in abc2abc abc2midi abcmatch mftext midi2abc midicopy yaps
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${STAGEDIR}${PREFIX}/bin
.endfor
.for FILE in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/CHANGES ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/programming
	${INSTALL_DATA} ${WRKSRC}/doc/programming/*.abc ${STAGEDIR}${DOCSDIR}/programming
	${INSTALL_DATA} ${WRKSRC}/doc/programming/*.txt ${STAGEDIR}${DOCSDIR}/programming

.include <bsd.port.mk>
