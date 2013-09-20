# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	apngdis
PORTVERSION=	2.5
DISTVERSIONSUFFIX=-src
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Deconstructs APNG files into individual frames

LICENSE=	ZLIB

NO_WRKSUBDIR=	yes

USE_DOS2UNIX=	yes
USE_ZIP=	yes

LDFLAGS+=	-lz

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS STATIC

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTATIC}
LDFLAGS+=	-static
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
