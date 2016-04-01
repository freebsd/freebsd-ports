# Created by: Anonymous <swell.k@gmail.com>
# $FreeBSD$

PORTNAME=	apngasm
PORTVERSION=	2.9
DISTVERSIONSUFFIX=-src
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Create Animated PNG from a sequence of files

LICENSE=	ZLIB

OPTIONS_DEFINE=	DOCS STATIC

NO_WRKSUBDIR=	yes

USES=		dos2unix gmake zip

LDFLAGS+=	-lz

PORTDOCS=	readme.txt
PLIST_FILES=	bin/${PORTNAME}

STATIC_BUILD_DEPENDS=	${LOCALBASE}/lib/libpng.a:graphics/png
STATIC_MAKE_ENV=	STATIC=1
STATIC_LIB_DEPENDS_OFF=	libpng.so:graphics/png

# libzopfli.a is N/A
STATIC_LIB_DEPENDS_OFF+=libzopfli.so:archivers/zopfli
STATIC_CPPFLAGS_OFF+=	-I${LOCALBASE}/include/zopfli
STATIC_LDFLAGS_OFF+=	-lzopfli

MAKE_JOBS_UNSAFE=	yes

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
