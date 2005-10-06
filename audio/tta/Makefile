# New ports collection makefile for:   tta
# Date created:        10 Aug 2004
# Whom:                dieringe
#
# $FreeBSD$
#

PORTNAME=	tta
PORTVERSION=	3.3
CATEGORIES=	audio
MASTER_SITES=	http://www.true-audio.com/ftp/
DISTNAME=	${PORTNAME}enc-${PORTVERSION}-src

MAINTAINER=	dieringe@zedat.fu-berlin.de
COMMENT=	"The True Audio Encoder", lossless (de)compressor

USE_ZIP=	yes

WRKSRC=		${WRKDIR}
LDFLAGS+=	-lm

PROGRAM=	ttaenc

PORTDOCS=	Readme
PLIST_FILES=	bin/ttaenc

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		Requires FreeBSD 5.x or higher for wide character support
.endif

do-build:
	${CC} ${CFLAGS} -c ${WRKSRC}/${PROGRAM}.c -o ${WRKSRC}/${PROGRAM}.o
	${CC} ${LDFLAGS} -o ${WRKSRC}/${PROGRAM} ${WRKSRC}/${PROGRAM}.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
