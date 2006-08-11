# New ports collection makefile for:	gzrecover
# Date created:				3 June 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	gzrecover
PORTVERSION=	0.4
CATEGORIES=	archivers
MASTER_SITES=	http://www.urbanophile.com/arenn/hacking/gzrt/ \
		http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/
DISTNAME=	gzrt-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A gzip recovery toolkit

CFLAGS+=	-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

do-build:
	${CC} -o ${WRKSRC}/${PORTNAME} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c -lz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${TARGETDIR}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
