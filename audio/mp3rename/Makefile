# New ports collection makefile for: mp3rename
# Date created:         6 Januari 2000
# Whom:                 Sander Janssen <janssen@rendo.dekooi.nl>
#
# $FreeBSD$
#

PORTNAME=	mp3rename
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A renaming program for mp3 files based on their id3tag

PLIST_FILES=	bin/mp3rename
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o mp3rename mp3rename.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3rename ${PREFIX}/bin

.include <bsd.port.mk>
