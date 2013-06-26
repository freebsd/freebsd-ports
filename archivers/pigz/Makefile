# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	pigz
PORTVERSION=	2.3
CATEGORIES=	archivers
MASTER_SITES=	http://www.zlib.net/pigz/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	gslin@gslin.org
COMMENT=	Parallel GZIP

USE_GMAKE=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	pigz.1
.endif

post-patch:
	${REINPLACE_CMD} -e 's/ -lz/ -lm -lz/g' ${WRKSRC}/Makefile

do-install:
.for FILE in pigz pigzn pigzt unpigz
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/pigz.1 ${MAN1PREFIX}/man/man1/
.endif

.include <bsd.port.mk>
