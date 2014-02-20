# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ppsei
PORTVERSION=	0.3
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}.src
EXTRACT_SUFX=	.tgz

MAINTAINER=	romain@FreeBSD.org
COMMENT=	PowerPoint images extractor

PLIST_FILES=	bin/ppsei
WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
