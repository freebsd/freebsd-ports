# Created by: luigi@FreeBSD.org
# $FreeBSD$

PORTNAME=	jpg2pdf
PORTVERSION=	20090113
CATEGORIES=	graphics
MASTER_SITES=	http://info.iet.unipi.it/~luigi/FreeBSD/
DISTNAME=	${PORTVERSION}-${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plain C converter of jpeg images to PDF or PostScript

MAN1=		jpg2pdf.1
PLIST_FILES=	bin/jpg2pdf

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
