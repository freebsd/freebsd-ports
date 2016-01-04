# Created by: dom@happygiraffe.net
# $FreeBSD$

PORTNAME=	gkermit
PORTVERSION=	1.0
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.kermitproject.org/kermit/archives/
DISTNAME=	gku100

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File transfer utility using the kermit protocol

NO_WRKSUBDIR=	yes

ALL_TARGET=	posix
MAKEFILE=	makefile

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gkermit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gkermit.nr ${STAGEDIR}${PREFIX}/man/man1/gkermit.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/gkermit.txt

.include <bsd.port.mk>
