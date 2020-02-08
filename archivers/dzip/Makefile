# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dzip
PORTVERSION=	2.9
CATEGORIES=	archivers games
MASTER_SITES=	http://speeddemosarchive.com/dzip/
DISTNAME=	dz${PORTVERSION:S/.//g}src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	File compression utility specializing in Quake demo compression

LICENSE=	ZLIB

USES=		dos2unix zip

NO_WRKSUBDIR=	yes
MAKEFILE=	${WRKSRC}/Makefile.linux
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	Readme

OPTIONS_DEFINE=	DOCS

post-extract: .SILENT
	${REINPLACE_CMD} -e 's/ifdef BIG_ENDIAN/if BYTE_ORDER == BIG_ENDIAN/' \
		-e 's/ifndef BIG_ENDIAN/if BYTE_ORDER == LITTLE_ENDIAN/' \
			${WRKSRC}/dzip.h ${WRKSRC}/conmain.c
	${REINPLACE_CMD} -e '4s,^,#include <machine/endian.h>,' \
		${WRKSRC}/dzip.h
	${REINPLACE_CMD} -e '21d;23d' ${WRKSRC}/dzipcon.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
