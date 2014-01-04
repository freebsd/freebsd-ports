# Created by: Sander Janssen <janssen@rendo.dekooi.nl>
# $FreeBSD$

PORTNAME=	mp3rename
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Renaming program for MP3 files based on their ID3 tag

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

PLIST_FILES=	bin/mp3rename

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o mp3rename mp3rename.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3rename ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
