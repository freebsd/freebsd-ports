# Created by: dom@happygiraffe.net
# $FreeBSD$

PORTNAME=	gkermit
PORTVERSION=	1.0
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/
DISTNAME=	gku100

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File transfer utility using the kermit protocol

NO_WRKSUBDIR=	yes
MAN1=		gkermit.1
PORTDOCS=	gkermit.txt
PLIST_FILES=	bin/gkermit

ALL_TARGET=	posix

NO_STAGE=	yes
post-extract:
	cd ${WRKSRC} && ${MV} makefile Makefile

do-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gkermit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gkermit.nr ${PREFIX}/man/man1/gkermit.1
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/gkermit.txt

.include <bsd.port.mk>
