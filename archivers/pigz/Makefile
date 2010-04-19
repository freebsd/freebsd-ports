# New ports collection makefile for:	pigz
# Date created:		2008-06-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	pigz
PORTVERSION=	2.1.6
CATEGORIES=	archivers
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://www.zlib.net/pigz/

MAINTAINER=	gslin@gslin.org
COMMENT=	Parallel GZIP

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	pigz.1
.endif

do-install:
.for FILE in pigz pigzn pigzt unpigz
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor

.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/pigz.1 ${MAN1PREFIX}/man/man1/
.endif

.include <bsd.port.mk>
