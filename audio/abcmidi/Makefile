# New ports collection makefile for:   abcmidi
# Date created:			10 March 2002
# Whom:				Sue Blake <sue@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abcmidi
PORTVERSION=	2003.11.12
CATEGORIES=	audio
MASTER_SITES=	http://ifdo.pugmarks.com/~seymour/runabc/
DISTNAME=	abcMIDI-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert abc music files to MIDI and PostScript

WRKSRC=		${WRKDIR}/${PORTNAME}

EXTRACT_BEFORE_ARGS=	-aqo

USE_ZIP=	yes
USE_GMAKE=	yes
MAKEFILE=	makefiles/unix.mak
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DANSILIBS -c" LNK="${CC}"

DOCS=	demo.abc doc/abcguide.txt doc/readme.txt doc/yaps.txt

do-install:
.for file in abc2abc abc2midi mftext midi2abc yaps
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
