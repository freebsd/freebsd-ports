# New ports collection makefile for:	gkermit
# Date created:		8 Jan 2000
# Whom:			dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	gkermit
PORTVERSION=	1.0
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/
DISTNAME=	gku100

MAINTAINER=	dom@happygiraffe.net
COMMENT=	File transfer utility using the kermit protocol

NO_WRKSUBDIR=	yes
MAN1=		gkermit.1

ALL_TARGET=	posix
MAKE_ENV=	CC="${CC}"

GKERMIT_DOCDIR=	${PREFIX}/share/doc/gkermit

post-extract:
	cd ${WRKSRC} && ${MV} makefile Makefile

do-install:
	${MKDIR} ${GKERMIT_DOCDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gkermit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gkermit.nr ${PREFIX}/man/man1/gkermit.1
	${INSTALL_DATA} ${WRKSRC}/README ${GKERMIT_DOCDIR}/gkermit.txt

.include <bsd.port.mk>
