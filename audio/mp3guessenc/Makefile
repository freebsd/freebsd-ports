# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	mp3guessenc
DISTVERSION=	${DIST_REL}${BETA_REL}
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${DIST_REL}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility for guessing which encoder was used to encode an mp3 file

DIST_REL=	0.25
BETA_REL=	beta2

PLIST_FILES=	bin/mp3guessenc
SRC=		decode.c mp3guessenc.c bit_utils.c tags.c

do-build:
.for f in ${SRC}
	${CC} ${CFLAGS} ${WRKSRC}/${f} -c -o ${WRKSRC}/${f:C/\.c/.o/}
.endfor
	${CC} ${SRC:S|\.c|${WRKSRC}/.o|:S|^|${WRKSRC}/|} \
		-o ${WRKSRC}/${PORTNAME} ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
