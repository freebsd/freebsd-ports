# Created by: dom@happygiraffe.net
# $FreeBSD$

PORTNAME=	gkermit
PORTVERSION=	1.0
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/
DISTNAME=	gku100

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File transfer utility using the kermit protocol

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
NO_WRKSUBDIR=	yes

ALL_TARGET=	posix

OPTIONS_DEFINE=	DOCS

post-extract:
	cd ${WRKSRC} && ${MV} makefile Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gkermit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gkermit.nr ${STAGEDIR}${PREFIX}/man/man1/gkermit.1
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/gkermit.txt

.include <bsd.port.mk>
