# New ports collection makefile for:	pigz
# Date created:		2008-06-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	pigz
PORTVERSION=	2.1.5
CATEGORIES=	archivers
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://www.zlib.net/pigz/

MAINTAINER=	gslin@gslin.org
COMMENT=	Parallel GZIP

do-install:
.for FILE in pigz pigzn pigzt unpigz
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
