# New ports collection makefile for:	TTA encoder
# Date created:				10 Aug 2004
# Whom:			Martin Dieringer <Martin.Dieringer@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	tta
PORTVERSION=	3.3
CATEGORIES=	audio
MASTER_SITES=	http://www.true-audio.com/ftp/
DISTNAME=	${PORTNAME}enc-${PORTVERSION}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	The True Audio Encoder, lossless (de)compressor

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

LDFLAGS+=	-lm

PROGRAM=	ttaenc

PORTDOCS=	Readme
PLIST_FILES=	bin/ttaenc

do-build:
	${CC} ${CFLAGS} -c ${WRKSRC}/${PROGRAM}.c -o ${WRKSRC}/${PROGRAM}.o
	${CC} ${LDFLAGS} -o ${WRKSRC}/${PROGRAM} ${WRKSRC}/${PROGRAM}.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
