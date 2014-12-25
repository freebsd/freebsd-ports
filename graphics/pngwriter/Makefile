# Created by: ijliao
# $FreeBSD$

PORTNAME=	pngwriter
PORTVERSION=	0.5.4
PORTREVISION=	4
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for creating PNG images

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2

USES=		pkgconfig

WRKSRC=		${WRKDIR}/${DISTNAME}

CXXFLAGS+=	`pkg-config --cflags freetype2 libpng` -I${LOCALBASE}/include

PLIST_FILES=	include/pngwriter.h \
		lib/libpngwriter.a \
		%%DATADIR%%/fonts/FreeMonoBold.ttf \
		%%DATADIR%%/fonts/FreeSansBold.ttf

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	@${FIND} ${WRKSRC} -name "\.*" -delete

do-build:
	cd ${WRKSRC}/src \
		&& ${CXX} ${CXXFLAGS} -c pngwriter.cc -o pngwriter.o \
		&& ${AR} rv libpngwriter.a pngwriter.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/pngwriter.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/src/libpngwriter.a ${STAGEDIR}${PREFIX}/lib/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} fonts ${STAGEDIR}${DATADIR})

	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
