# New ports collection makefile for:	sredird
# Date created:				19 Dec 1999
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sredird
PORTVERSION=	1.1.8
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/serial

MAINTAINER=	sobomax@FreeBSD.org

do-build:
	${CC} ${CFLAGS} -Wall -o ${WRKSRC}/sredird ${WRKSRC}/sredird.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sredird ${PREFIX}/libexec
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sredird
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/sredird
	${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/sredird
.endif

.include <bsd.port.mk>
