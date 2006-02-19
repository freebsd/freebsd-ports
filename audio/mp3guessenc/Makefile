# New ports collection makefile for:	mp3guessenc
# Date created:				1 Oct 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	mp3guessenc
PORTVERSION=	0.21
CATEGORIES=	audio
MASTER_SITES=	http://shibatch.sourceforge.net/download/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility for guessing which encoder was used to encode an mp3 file

USE_ZIP=	yes

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/mp3guessenc

post-extract:
	@${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' \
		${WRKSRC}/${PORTNAME}.c \
		${WRKSRC}/VbrTag.h

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
