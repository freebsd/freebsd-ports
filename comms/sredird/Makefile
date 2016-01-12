# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sredird
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	SUNSITE/system/serial

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RFC 2217 compliant serial port redirector

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

do-build:
	${CC} ${CFLAGS} -Wall -o ${WRKSRC}/sredird ${WRKSRC}/sredird.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sredird ${STAGEDIR}${PREFIX}/libexec

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
