# New ports collection makefile for:	gzrecover
# Date created:				3 June 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	gzrecover
PORTVERSION=	0.5
CATEGORIES=	archivers
MASTER_SITES=	http://www.urbanophile.com/arenn/hacking/gzrt/ \
		CRITICAL
DISTNAME=	gzrt-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A gzip recovery toolkit

CFLAGS+=	-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -lz

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

do-build:
	${CC} -o ${WRKSRC}/${PORTNAME} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
