# Created by: jmz
# $FreeBSD$

PORTNAME=	zoo
PORTVERSION=	2.10.1
PORTREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/arcers/ \
		LOCAL/ehaupt
DISTNAME=	zoo-2.10pl1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Manipulate archives of files in compressed form

NO_WRKSUBDIR=	yes
ALL_TARGET=	bsdansi
MAKEFILE=	makefile

do-install:
.for f in fiz zoo
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
