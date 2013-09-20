# Created by: Anonymous <swell.k@gmail.com>
# $FreeBSD$

PORTNAME=	apngasm
PORTVERSION=	2.7
DISTVERSIONSUFFIX=-src
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Creates an APNG animation from a PNG/TGA image sequence

LICENSE=	ZLIB

NO_WRKSUBDIR=	yes

USE_DOS2UNIX=	yes
USE_ZIP=	yes

CPPFLAGS+=	`libpng-config --I_opts`
LDFLAGS+=	`libpng-config --ldflags` -lm -lz

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS STATIC

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpng.a:${PORTSDIR}/graphics/png
LDFLAGS+=	-static
.else
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
.endif

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} ${PORTNAME}.c \
		-o ${PORTNAME} ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
