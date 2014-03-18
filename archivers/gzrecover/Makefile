# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	gzrecover
PORTVERSION=	0.8
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

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
