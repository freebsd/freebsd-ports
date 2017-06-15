# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	wav2cdr
PORTVERSION=	2.3.4
DISTVERSIONSUFFIX=	.orig
CATEGORIES=	audio converters
MASTER_SITES=	DEBIAN \
		LOCAL/ehaupt
DISTNAME=	${PORTNAME}_${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Converts WAV files into CDR audio file format

LICENSE=	GPLv2

USES=		tar:bz2

WRKSRC=		${WRKDIR}/${PORTNAME}
SRC=		wav2cdr cmdarg data fileio process

PLIST_FILES=	bin/wav2cdr man/man1/wav2cdr.1.gz

do-build:
.for f in ${SRC}
	${CC} ${CFLAGS} -c -o ${WRKSRC}/${f}.o ${WRKSRC}/${f}.c
.endfor
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/${PORTNAME} \
		${SRC:C/(.*)/${WRKSRC}\/\1.o/}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
