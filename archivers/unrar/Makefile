# New ports collection makefile for:    unrar
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	unrar
PORTVERSION=	2.50
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ache

MAINTAINER=	ache@FreeBSD.org

NO_WRKSUBDIR=	Yes

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} -D_UNIX unrar.c -o unrar

do-install:
	${INSTALL} -d -m 755 -o ${SHAREOWN} -g ${SHAREGRP} \
		${PREFIX}/share/doc/unrar
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unrar ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} readme.txt license.txt \
		${PREFIX}/share/doc/unrar

.include <bsd.port.mk>
