# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hvl2wav
DISTVERSION=	g20180905
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool for converting AHX sound modules to WAV

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	pete-gordon
GH_PROJECT=	hivelytracker
GH_TAGNAME=	8296a50

OPTIONS_DEFINE=	EXAMPLES

LDFLAGS+=	-lm

PLIST_FILES=	bin/hvl2wav man/man1/hvl2wav.1.gz
PORTEXAMPLES=	*

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}/*.c \
		-o ${WRKSRC}/${PORTNAME}/${PORTNAME}

do-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Songs/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
