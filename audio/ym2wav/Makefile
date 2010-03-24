# New ports collection makefile for:	ym2wav
# Date created:				24 Mar 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ym2wav
DISTVERSION=	0.21a
CATEGORIES=	audio
MASTER_SITES=	http://atariarea.krap.pl/stymulator/files/ \
		CRITICAL
DISTNAME=	STYMulator-${DISTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Convert .ym (Yamaha YM2149 soundchip) music files to wav

PLIST_FILES=	bin/ym2wav

do-build:
.for i in digidrum Ymload Ym2149Ex YmMusic YmUserInterface
	${CXX} ${CXXFLAGS} -c ${WRKSRC}/src/stsoundlib/${i}.cpp \
		-o ${WRKSRC}/src/stsoundlib/${i}.o
.endfor
	${CC} ${CFLAGS} -c ${WRKSRC}/src/stsoundlib/lzh/lzhlib.cpp \
		-o ${WRKSRC}/src/stsoundlib/lzh/lzhlib.o
	${CXX}  -o ${WRKSRC}/src/${PORTNAME} ${WRKSRC}/src/ym2wav.cpp \
		${WRKSRC}/src/stsoundlib/lzh/lzhlib.o \
		${WRKSRC}/src/stsoundlib/*.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
