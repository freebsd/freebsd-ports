# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	mp3guessenc
DISTVERSION=	${DIST_REL}${ALPHA_REL}
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${DIST_REL}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility for guessing which encoder was used to encode an mp3 file

MAKE_JOBS_SAFE=	yes

DIST_REL=	0.25
ALPHA_REL=	alpha23-HPR

PLIST_FILES=	bin/mp3guessenc
SRC=		decode.c mp3guessenc.c

do-build:
.for f in ${SRC}
	${CC} ${CFLAGS} ${WRKSRC}/${f} -c -o ${WRKSRC}/${f:C/\.c/.o/}
.endfor
	${CC} ${SRC:S|\.c|${WRKSRC}/.o|:S|^|${WRKSRC}/|} \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
