# Created by: will
# $FreeBSD$

PORTNAME=	tiff2png
PORTVERSION=	0.91
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/png-mng/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts TIFF images to PNG format

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
MAKEFILE=	Makefile.unx
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
ALL_TARGET=	tiff2png

PORTDOCS=	README
PLIST_FILES=	bin/tiff2png

CFLAGS+=	-DINVERT_MINISWHITE -DFAXPECT -DDEFAULT_DESTDIR_IS_CURDIR \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lpng -lz -ltiff -ljpeg -lm

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
PLIST_FILES+=	%%DOCSDIR%%/README
PLIST_DIRS+=	%%DOCSDIR%%
.endif

.include <bsd.port.mk>
