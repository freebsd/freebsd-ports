# New ports collection makefile for:	sredird
# Date created:				19 Dec 1999
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sredird
PORTVERSION=	2.2.1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/serial

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RFC 2217 compliant serial port redirector

PLIST_FILES=	libexec/sredird
.if !defined(NOPORTDOCS)
PORTDOCS=	README COPYING
.endif

do-build:
	${CC} ${CFLAGS} -Wall -o ${WRKSRC}/sredird ${WRKSRC}/sredird.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sredird ${PREFIX}/libexec
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${WRKSRC}/COPYING ${DOCSDIR}
.endif

.include <bsd.port.mk>
