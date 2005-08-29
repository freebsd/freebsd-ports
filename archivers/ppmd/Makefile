# New ports collection makefile for:	ppmd
# Date created:				11 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	ppmd
PORTVERSION=	20050811
CATEGORIES=	archivers
MASTER_SITES=	http://critical.ch/distfiles/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A fast archiver with a good compression ratio

MAN1=		ppmd.1
PORTDOCS=	read_me.txt
PLIST_FILES=	bin/ppmd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
