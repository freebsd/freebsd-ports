# New ports collection makefile for:	pigz
# Date created:		2008-06-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	pigz
PORTVERSION=	1.7
CATEGORIES=	archivers
MASTER_SITES=	http://zlib.net/
DISTFILES=	pigz17.c.gz

MAINTAINER=	gslin@gslin.org
COMMENT=	Parallel GZIP

EXTRACT_AFTER_ARGS=	> ${WRKSRC}/pigz17.c
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/pigz

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/pigz ${WRKSRC}/pigz17.c -lz ${PTHREAD_LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pigz ${PREFIX}/bin

.include <bsd.port.mk>
