# New ports collection makefile for:	unzoo
# Date created:				20 Jun 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	unzoo
DISTVERSION=	4.4
CATEGORIES=	archivers
MASTER_SITES=	http://critical.ch/unzoo/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A zoo archive extractor

EXTRA_DEFINES=	-DSYS_IS_UNIX -DSYS_HAS_MKDIR

PLIST_FILES=	bin/unzoo

MAN1=		unzoo.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
CFLAGS+=	-trigraphs
.endif

do-build:
	${CC} ${CFLAGS} ${EXTRA_DEFINES} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
