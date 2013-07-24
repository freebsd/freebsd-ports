# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	gzrecover
PORTVERSION=	0.7
CATEGORIES=	archivers
MASTER_SITES=	http://www.urbanophile.com/arenn/hacking/gzrt/ \
		CRITICAL
DISTNAME=	gzrt-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	GZIP recovery toolkit

LICENSE=	GPLv2

CFLAGS+=	-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -lz

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-build:
	${CC} -o ${WRKSRC}/${PORTNAME} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
