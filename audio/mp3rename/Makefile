# New ports collection makefile for: mp3rename
# Date created:         6 Januari 2000
# Whom:                 Sander Janssen <janssen@rendo.dekooi.nl>
#
# $FreeBSD$
#

PORTNAME=	mp3rename
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.debian.org/debian/pool/main/m/mp3rename/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o mp3rename mp3rename.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3rename ${PREFIX}/bin

.include <bsd.port.mk>
